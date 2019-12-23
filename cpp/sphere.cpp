#include <iostream>
#include <cmath>
#include "Sample.h"

using namespace std;

int main() {
    clock_t start = clock();

    const int n = int(pow(10, 7)), d = 20, interval = int(pow(10, 5));
    int count = 0;
    double *r2s;
    r2s = new double[n];
    Sample *sample;
    for (int i = 0; i < n; i++) {
        sample = new Sample(d);
        if (sample->run()) count++;

        if (i % interval == interval - 1 or i == n - 1) {
            r2s[i] = sample->r2;
            double v = double(count) / double(i + 1) * pow(2, d);
            double p = double(count) / double(i + 1);
            double q = 1.0 - p;
            double error = 1.96 * pow(2, d) * sqrt(p * q / double(i + 1));
            printf("i + 1 = %d v = %f ± %f\n", i + 1, v, error);
        }
    }
    delete sample;

    clock_t end = clock();
    const int time = int(double(end - start) / CLOCKS_PER_SEC);
    printf("Process finished. (%d s)\n", time);

    return 0;
}
