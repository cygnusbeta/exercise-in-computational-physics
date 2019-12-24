#pragma once

#include <fstream>
#include <random>

using namespace std;

inline double get_random_0_to_1() {
    // 乱数生成器
    static mt19937_64 mt64(0);

    // [0.0, 1.0) の一様分布実数生成器
    uniform_real_distribution<double> get_rand_uni_real(0.0, 1.0);
    // 乱数を生成
    return get_rand_uni_real(mt64);
}

inline int write_to_file(const string& s, const string& fpath) {
    ofstream f;
    f.open(fpath);
    f << s;
    f.close();
    return 0;
}