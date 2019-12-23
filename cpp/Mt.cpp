#include <random>
#include "Sample.h"

using namespace std;

Mt::Mt() {
    // 乱数生成器
    mt64 = new mt19937_64(0);

    // [0.0, 1.0) の一様分布実数生成器
    get_rand_uni_real = new uniform_real_distribution<double>(0.0, 1.0);
}

Mt::~Mt() = default;

double Mt::get_random_0_to_1() {
    // 乱数を生成
    return (*get_rand_uni_real)(*mt64);
}
