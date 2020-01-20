#include <cstdio>
#include <string>
#include "../../util.h"

using namespace std;

int main() {
    double v = 0.0, x = 1.0, t = 0.0, dt = 0.1;
    string s;
    s += to_string(t) + " " + to_string(x) + "\n";
    for (int n = 0; n < 100; n++) {
        t = dt * double(n + 1);
        double x_tmp = x;
        x += v * dt;
        v += -x_tmp * dt;
        double diff = (x - cos(t)) / cos(t);
        s += to_string(t) + " " + to_string(diff) + "\n";
    }
    string fpath = "../out/euler/oscil5.dat";
    write_to_file(s, fpath);

    return 0;
}
