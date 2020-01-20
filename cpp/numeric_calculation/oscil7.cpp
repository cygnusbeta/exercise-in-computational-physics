#include <cstdio>
#include <string>
#include "../util.h"

using namespace std;

int main() {
    double v = 0.0, x = 1.0, t = 0.0, dt = 0.1, gamma = 2.0;
    string s;
    s += to_string(t) + " " + to_string(x) + "\n";
    for (int n = 0; n < 100; n++) {
        t = dt * double(n + 1);
        double x_tmp = x;
        x += v * dt;
        v += (-x_tmp - 2 * gamma * v) * dt;
        s += to_string(t) + " " + to_string(x) + "\n";
    }
    string fpath = "../out/oscil7_4.dat";
    write_to_file(s, fpath);

//    gnuplot で
//    ```set size ratio -1
//       plot "oscil7_1.dat", "oscil7_2.dat", "oscil7_3.dat", "oscil7_4.dat"```
//    でプロット
    return 0;
}
