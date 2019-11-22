//pi.C
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>

using namespace std;

double get_random_0_to_1() {
    // 乱数生成器
    static std::mt19937_64 mt64(0);

    // [0.0, 1.0) の一様分布実数生成器
    std::uniform_real_distribution<double> get_rand_uni_real(0.0, 1.0);
    // 乱数を生成
    return get_rand_uni_real(mt64);
}

int main() {
//    cout << "ntry=?";
////    cin >> ntry;
    int ntry = int(pow(10, 4)), d = 4, ncout = 0;
    for (int i = 1; i <= ntry; i++) {
        double r2 = 0.0;
        for (int j = 0; j < d; j++) {
            double x_j = get_random_0_to_1();
            r2 += pow(x_j, 2);
        }
        if (r2 <= 1) ncout++;
        double v = double(ncout) / double(i) * pow(2, d);
        double p = double(ncout) / double(i);
        double q = 1.0 - p;
        double error = 1.96 * pow(2, d) * sqrt(p * q / double(i));
        cout << "i = " << i << " v = " << v << " ± " << error << "\n";
    }
}

// 誤差も計算すること。
