#include <vector>
#include <atomic>
#include <thread>
#include "../util2.h"

using namespace std;

using container = std::vector<std::atomic<int>>;
using container_size_type = container::size_type;

container c(10);

std::atomic<container::pointer> p_busy_elem_from{ nullptr };
std::atomic<container::pointer> p_busy_elem_to{ nullptr };

const int nCpuThread = int(thread::hardware_concurrency());
const int nExchange = 10000;

bool try_change(container_size_type giveFrom, container_size_type giveTo, bool breaked) {
    // A1: wait for editor thread to finish editing value
    while (p_busy_elem_from == &c[giveFrom] || p_busy_elem_to == &c[giveTo] || p_busy_elem_from == &c[giveTo] || p_busy_elem_to == &c[giveFrom])
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

void editor(int iThread)
{
    for (int i = iThread; i < nExchange; i += nCpuThread) {
//        printf("i = %d\n", i);
        bool breaked = false;
        while (!breaked) {
            container_size_type giveFrom { static_cast<container_size_type>(get_random_0_to_n(c.size())) };
            container_size_type giveTo { static_cast<container_size_type>(get_random_0_to_n(c.size())) };
            if (giveTo != giveFrom) {
                breaked = try_change(giveFrom, giveTo, breaked);
            }
        }
    }
}

int main()
{
    for (container_size_type i{ 0 }, sz{ c.size() }; i < sz; ++i) {
        c[i] = int(i);
    }
//    std::thread t_editor{ editor };
//    std::thread t_reader{ reader };
//    t_editor.join();
//    t_reader.join();

    // spawn n threads:
    printf("nCpuThread = %d\n", nCpuThread);
    vector<thread> threads(nCpuThread);
    for (int iThread = 0; iThread < nCpuThread; iThread++) {
        threads[iThread] = std::thread { editor, iThread };
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
