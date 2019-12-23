#include <iostream>
#include <cmath>
#include "Sample.h"

using namespace std;

int main() {
    int n = int(pow(10, 5)), d = 14, count = 0, interval = pow(10, 4);
    auto *r2s = new double[n];
    for (int i = 0; i < n; i++) {
        Sample *sample;
        sample = new Sample(d);
        if (sample->run()) count++;
        delete sample;

        if (i % interval == interval - 1 or i == n - 1) {
            r2s[i] = sample->r2;
            double v = double(count) / double(i + 1) * pow(2, d);
            double p = double(count) / double(i + 1);
            double q = 1.0 - p;
            double error = 1.96 * pow(2, d) * sqrt(p * q / double(i + 1));
            cout << "i + 1 = " << i + 1 << " v = " << v << " ± " << error << "\n";
        }
    }
    return 0;
}
