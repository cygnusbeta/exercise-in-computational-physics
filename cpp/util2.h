#pragma once

#include <fstream>
#include <random>

using namespace std;

inline int get_random_0_to_n(int n) {
    // 乱数生成器
    static mt19937_64 mt64(0);

    // 0, 1, ... , n - 1 の一様分布整数生成器
    uniform_real_distribution<double> get_rand_uni_real(0.0, double(n));
    // 乱数を生成
    double numRandom = get_rand_uni_real(mt64);
    return int(floor(numRandom));
}

inline int write_to_file(const string& s, const string& fpath) {
    ofstream f;
    f.open(fpath);
    f << s;
    f.close();
    return 0;
}