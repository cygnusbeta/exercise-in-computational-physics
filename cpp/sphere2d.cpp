#include <iostream>
//#include <cstdlib>
#include <cmath>
#include <random>
#include <fstream>
#include <string>

using namespace std;

double get_random_0_to_1() {
    // 乱数生成器
    static mt19937_64 mt64(0);

    // [0.0, 1.0) の一様分布実数生成器
    uniform_real_distribution<double> get_rand_uni_real(0.0, 1.0);
    // 乱数を生成
    return get_rand_uni_real(mt64);
}

int write_to_file(const string& s) {
    ofstream f;
    f.open("../out/x_y_plot_2d.csv");
    f << s;
    f.close();
    return 0;
}

int main() {
    int n = int(pow(10, 5)), d = 2, count = 0, interval = pow(10, 4);
    auto *r2s = new double[n];
    string s;
    for (int i = 0; i < n; i++) {
        double r2 = 0.0;
        for (int j = 0; j < d; j++) {
            double x_j = get_random_0_to_1();
            r2 += pow(x_j, 2);
            if (j == 0) {
                s += to_string(x_j) + ",";
            } else {
                s += to_string(x_j) + "\n";
            }
        }
        if (r2 <= 1) count++;
        if (i % interval == interval - 1 or i == n - 1) {
            r2s[i] = r2;
            double v = double(count) / double(i + 1) * pow(2, d);
            double p = double(count) / double(i + 1);
            double q = 1.0 - p;
            double error = 1.96 * pow(2, d) * sqrt(p * q / double(i + 1));
            cout << "i + 1 = " << i + 1 << " v = " << v << " ± " << error << "\n";
        }
    }
    write_to_file(s);
}
