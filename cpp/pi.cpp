//pi.C
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>

using namespace std;
#define RAND() (float(rand()/pow(2,15)))

double get_random_0_to_1() {
    // 乱数生成器
    static std::mt19937_64 mt64(0);

    // [0.0, 1.0) の一様分布実数生成器
    std::uniform_real_distribution<double> get_rand_uni_real(0.0, 1.0);
    // 乱数を生成
    return get_rand_uni_real(mt64);
}

int main()
{
    int i;
    double ncout = 0.0;
    int ntry;
    double x, y, pi;
//    cout << "ntry=?";
////    cin >> ntry;
    ntry = 1000;
    for (i = 1; i <= ntry; ++i){
        x = get_random_0_to_1();
        y = get_random_0_to_1();
        if (x*x+y*y <= 1){
            ncout=ncout+1;
        }
        pi=(float(ncout)/i)*4;
        cout << "i=" << i << " pi=" << pi << "\n";
    }
}