#include <cstdio>
#include <string>
#include "../../util.h"

using namespace std;

int main() {
    const float g = -9.8;
    double v = 20.0, x = 0.0, t = 0.0, dt = 0.1;
    string s;
    s += to_string(t) + " " + to_string(x) + "\n";
    for (int n = 0; n < 40; n++) {
        t = dt * double(n + 1);
        x += v * dt;
        v += g * dt;
        s += to_string(t) + " " + to_string(x) + "\n";
    }
    string fpath = "../../out/euler/fall.dat";
    write_to_file(s, fpath);

    return 0;
}
