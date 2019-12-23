#include <random>
#include "Sample.h"

using namespace std;

double get_random_0_to_1() {
    // 乱数生成器
    static mt19937_64 mt64(0);

    // [0.0, 1.0) の一様分布実数生成器
    uniform_real_distribution<double> get_rand_uni_real(0.0, 1.0);
    // 乱数を生成
    return get_rand_uni_real(mt64);
}
