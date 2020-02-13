#include <vector>
#include <atomic>
#include <thread>
#include "../util2.h"

using namespace std;

using container = std::vector<std::atomic<double>>;
using container_size_type = container::size_type;

container c(100);

std::atomic<container::pointer> p_busy_elem_from{ nullptr };
std::atomic<container::pointer> p_busy_elem_to{ nullptr };

bool try_change(int giveFrom, int giveTo, bool breaked) {
    // A1: wait for editor thread to finish editing value
    while (p_busy_elem_from == &c[giveFrom] || p_busy_elem_to == &c[giveTo])
    {
        // A2: room a better algorithm to prevent blocking/yielding
        std::this_thread::yield();
    }

    p_busy_elem_from.exchange(&c[giveFrom]); // c[i] is busy
    p_busy_elem_to.exchange(&c[giveTo]); // c[i] is busy
    // ... edit c[i] ... // E: calculate a value and assign it to c[i]
    // B: if c[i] is updated in between A and B, this will load the latest value
    auto valueFrom = c[giveFrom].load();
    auto valueTo = c[giveTo].load();
    // C: c[i] might have changed by this time, but we had the most up to date value we could get without checking again
    // ... use value ...
    if (valueFrom != 0) {
        c[giveFrom] = valueFrom - 1;
        c[giveTo] =  valueTo + 1;
        breaked = true;
    }
    p_busy_elem_from.exchange(nullptr); // c[i] is no longer busy
    p_busy_elem_to.exchange(nullptr); // c[i] is no longer busy
    return breaked;
}

void editor()
{
    int giveFrom, giveTo;
    bool breaked = false;
    while (!breaked) {
        giveFrom = get_random_0_to_n(c.size());
        giveTo = get_random_0_to_n(c.size());
        if (giveTo != giveFrom) {
            breaked = try_change(giveFrom, giveTo, breaked);
        }
    }
}

int main()
{
    for (container_size_type i{ 0 }, sz{ c.size() }; i < sz; ++i) {
        c[i] = i;
    }
//    std::thread t_editor{ editor };
//    std::thread t_reader{ reader };
//    t_editor.join();
//    t_reader.join();

    // spawn n threads:
    int nExchange = 10000;
    vector<thread> threads(nExchange);
    for (int iThread = 0; iThread < nExchange; iThread++) {
        threads[iThread] = std::thread { editor };
    }
    for (auto& t : threads) {
        t.join();
    }
    int sum = 0;
    for (container_size_type i{ 0 }, sz{ c.size() }; i < sz; ++i) {
        printf("c[%d] = %d\n", int(i), int(c[i]));
        sum += c[i];
    }
    printf("sum = %d\n", sum);
}
