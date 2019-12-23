#include <random>

using namespace std;

class Mt {
private:
    mt19937_64 *mt64;
    uniform_real_distribution<double> *get_rand_uni_real;

public:
    explicit Mt();
    ~Mt();

    double get_random_0_to_1();
};
