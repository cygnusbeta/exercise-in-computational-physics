#include <iostream>
#include <cmath>
#include "Sample.h"

using namespace std;

inline int main_inline() {
    const int n = int(pow(10, 8)), d = 20, interval = int(pow(10, 7));
    int count = 0;
    double *r2s;
    r2s = new double[n];
    double max_sum_x_j = sqrt(d);
    for (int i = 0; i < n; i++) {
        Sample sample(d, max_sum_x_j);
        if (sample.run()) count++;

        if (i % interval == interval - 1 or i == n - 1) {
            r2s[i] = sample.r2;
            double v = double(count) / double(i + 1) * pow(2, d);
            double p = double(count) / double(i + 1);
            double q = 1.0 - p;
            double error = 1.96 * pow(2, d) * sqrt(p * q / double(i + 1));
            printf("d = %d, i + 1 = %d, v = %f ± %f\n", d, i + 1, v, error);
        }
    }

    return 0;
}

int main() {
    clock_t start = clock();

    main_inline();

    clock_t end = clock();
    const double time = double(end - start) / CLOCKS_PER_SEC;
    printf("Process finished. (%2.1f s)\n", time);

    return 0;
}
