//#include <iostream>
#include <cmath>
#include "Sample.h"

using namespace std;

inline int main_inline() {
    const int n = int(pow(10, 8)), num_plot = 100, interval = n / num_plot;
    const int d_max = 20;
    for (int d = 2; d <= d_max; d++) {
        int count = 0;
        double r2s[n];
        string s;
        for (int i = 0; i < n; i++) {
            Sample sample(d);
            if (sample.run()) count++;

            if (i % interval == interval - 1 or i == n - 1) {
                r2s[i] = sample.r2;
                double v = double(count) / double(i + 1) * pow(2, d);
                double p = double(count) / double(i + 1);
                double q = 1.0 - p;
                double error = 1.96 * pow(2, d) * sqrt(p * q / double(i + 1));
                printf("d = %d, i + 1 = %d, v = %f ± %f\n", d, i + 1, v, error);
                if (d == 4) {
                    true;
                }
                s += to_string(i + 1) + "," + to_string(v) + "," + to_string(error) + "\n";
            }
        }
        string fpath = "../out/r2_plot_" + to_string(d) + "d.csv";
        write_to_file(s, fpath);
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