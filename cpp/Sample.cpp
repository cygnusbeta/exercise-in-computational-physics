#include <cmath>
#include "Sample.h"
#include "util.h"

Sample::Sample(int d, double max_sum_x_j) {
    this->d = d;
    this->r2 = 0.0;
    this->sum = 0.0;
    this->max_sum_x_j = max_sum_x_j;
}

Sample::~Sample() = default;


