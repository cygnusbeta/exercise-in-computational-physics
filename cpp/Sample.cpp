#include <cmath>
#include "Sample.h"

Sample::Sample(int d, util mt) {
    this->d = d;
    this->r2 = 0.0;
    this->mt = mt;
}

Sample::~Sample() = default;

bool Sample::run() {
    for (int j = 0; j < d; j++) {
        x_j = mt.get_random_0_to_1();
        r2 += pow(x_j, 2);
        if (r2 > 1.0) return false;
    }
    return true;
}
