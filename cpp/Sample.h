#include <cmath>
#include "util.h"

class Sample {
private:
    int d;
    double sum;
    double max_sum_x_j;

public:
    explicit Sample(int d, double max_sum_x_j);
    ~Sample();

    bool run();

    double r2;
};

inline bool Sample::run() {
    double x_j_s[d];
    for (int j = 0; j < d; j++) {
        double x_j = get_random_0_to_1();
        sum += x_j;
        if (sum > max_sum_x_j) return false;
        x_j_s[j] = x_j;
    }
    for (int j = 0; j < d; j++) {
        if (x_j_s[j] != 0.0) {
            r2 += pow(x_j_s[j], 2);
        } else {
            r2 += pow(get_random_0_to_1(), 2);
        }
        if (r2 > 1) return false;
    }
    return true;
}
