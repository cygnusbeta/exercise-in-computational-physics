#include <vector>
#include <atomic>
#include <thread>

using container = std::vector<std::atomic<double>>;
using container_size_type = container::size_type;

container c(300);

std::atomic<container::pointer> p_busy_elem{ nullptr };

void editor()
{
    for (container_size_type i{ 0 }, sz{ c.size() }; i < sz; ++i)
    {
        p_busy_elem.exchange(&c[i]); // c[i] is busy
        // ... edit c[i] ... // E: calculate a value and assign it to c[i]
        c[i] = c[i] * 2;
        p_busy_elem.exchange(nullptr); // c[i] is no longer busy
    }
}

void reader()
{
    for (container_size_type i{ 0 }, sz{ c.size() }; i < sz; ++i)
    {
        // A1: wait for editor thread to finish editing value
        while (p_busy_elem == &c[i])
        {
            // A2: room a better algorithm to prevent blocking/yielding
            std::this_thread::yield();
        }

        // B: if c[i] is updated in between A and B, this will load the latest value
        auto value = c[i].load();

        // C: c[i] might have changed by this time, but we had the most up to date value we could get without checking again
        // ... use value ...
        printf("%lf\n", value);
    }
}

int main()
{
    std::thread t_editor{ editor };
    std::thread t_reader{ reader };
    t_editor.join();
    t_reader.join();
}
