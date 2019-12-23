#include <cmath>
#include "Sample.h"
#include "util.h"

Sample::Sample(int d) {
    this->d = d;
    this->r2 = 0.0;
}

Sample::~Sample() = default;

bool Sample::run() {
    for (int j = 0; j < d; j++) {
        double x_j = get_random_0_to_1();
        r2 += pow(x_j, 2);
    }
    return r2 <= 1;
}
