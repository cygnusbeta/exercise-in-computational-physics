#include <cmath>
#include "util.h"

class Sample {
private:
    int d;

public:
    explicit Sample(int d);
    ~Sample();

    bool run();

    double r2;
};

inline bool Sample::run() {
    for (int j = 0; j < d; j++) {
        double x_j = get_random_0_to_1();
        r2 += pow(x_j, 2);
        if (r2 > 1) return false;
    }
    return true;
}
