//#include <iostream>
#include <cmath>
#include <tuple>
#include "Sample.h"

using namespace std;

inline tuple<double, double, double, double> calc(int d, int i, int count) {
    double v = double(count) / double(i + 1) * pow(2, d);
    double p = double(count) / double(i + 1);
    double q = 1.0 - p;
    double error = 1.96 * pow(2, d) * sqrt(p * q / double(i + 1));
    return forward_as_tuple(v, p, q, error);
}

inline int main_inline() {
    const int n_pow = 8, n = int(pow(10, n_pow)), num_plot = 100, interval = n / num_plot;
    const int d_max = 20;
    string v_s;

    for (int d = 2; d <= d_max; d++) {
        double v_theory = pow(M_PI, double(d) / 2.0) / tgamma(double(d) / 2.0 + 1.0);

        int i_log = 0, count = 0;
        double r2s[n];
        string s;
        for (int i = 0; i < n; i++) {
            Sample sample(d);
            if (sample.run()) count++;

            double log10_i = log10(i + 1);
            if (log10_i >= double(n_pow) / double(num_plot) * double(i_log) or i == n - 1) {
                r2s[i] = sample.r2;
                double v, p, q, error;
                tie(v, p, q, error) = calc(d, i, count);
                printf("d = %d, i + 1 = %d, v = %f ± %f\n", d, i + 1, v, error);
                s += to_string(i + 1) + "," + to_string(v) + "," + to_string(error) + "," +
                        to_string(v_theory) + "\n";
                i_log++;
            }
            if (i + 1 == int(pow(10, 8))) {
                double v, error;
                tie(v, ignore, ignore, error) = calc(d, i, count);
                v_s += to_string(d) + "," + to_string(v) + "," + to_string(error) + "\n";
            }
        }
        string fpath = "../out/r2_plot_" + to_string(d) + "d.csv";
        write_to_file(s, fpath);
    }

    string v_s_path = "../out/v_s_plot.csv";
    write_to_file(v_s, v_s_path);

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
