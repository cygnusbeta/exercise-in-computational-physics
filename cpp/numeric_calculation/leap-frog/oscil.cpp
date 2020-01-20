#include <cstdio>
#include <string>
#include "../../util.h"

using namespace std;

int main() {
    double v = 0.0, x = 1.0, t = 0.0, dt = 0.1, dt2 = dt * 0.5, t2 = dt2;
    v += -x * dt * 0.5;
    string s;
    s += to_string(t) + " " + to_string(x) + "\n";
    for (int n = 0; n < 100; n++) {
        t = dt * double(n + 1);
        x += v * dt;
        s += to_string(t) + " " + to_string(x) + "\n";
        t2 = dt * double(n + 1.0 + 0.5);
        v += -x * dt;
    }
    string fpath = "../out/leap-frog/oscil.dat";
    write_to_file(s, fpath);

//    `plot cos(x), 'oscil.dat' with points pointtype 1` でプロット

    return 0;
}
