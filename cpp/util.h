#include <random>

using namespace std;

class util {
private:
    mt19937_64 *mt64;
    uniform_real_distribution<double> *get_rand_uni_real;

public:
    explicit util();
    ~util();

    double get_random_0_to_1();
};
