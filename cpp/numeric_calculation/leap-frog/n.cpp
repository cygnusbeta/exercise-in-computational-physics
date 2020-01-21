#include <string>
#include "../../util.h"

using namespace std;

int main() {
    const double dt = 0.1, G = 1.0, M = 1.0, m = 1.0;
    const int n = 100;
    double x[2 * n], y[2 * n], v_x[2 * n], v_y[2 * n];
    x[0] = 0.5, y[0] = 0.0, v_x[0] = 0.0, v_y[0] = 1.63;

    double r = sqrt(pow(x[0], 2) + pow(y[0], 2));
    v_x[1] = v_x[0] - G * M * m * x[0] / (pow(r, 3) * m) * dt * 0.5;
    v_y[1] = v_y[0] - G * M * m * y[0] / (pow(r, 3) * m) * dt * 0.5;
    for (int i = 0; i < n - 1; i++) {
        x[2 * (i + 1)] = x[2 * i] + v_x[2 * i + 1] * dt;
        y[2 * (i + 1)] = y[2 * i] + v_y[2 * i + 1] * dt;
        r = sqrt(pow(x[2 * (i + 1)], 2) + pow(y[2 * (i + 1)], 2));
        v_x[2 * i + 3] = v_x[2 * i + 1] - G * M * m * x[2 * (i + 1)] / (pow(r, 3) * m) * dt;
        v_y[2 * i + 3] = v_y[2 * i + 1] - G * M * m * y[2 * (i + 1)] / (pow(r, 3) * m) * dt;
    }
    string s;
    for (int i = 0; i < n; i++) {
        s += to_string(x[2 * i]) + " " + to_string(y[2 * i]) + "\n";
    }
    string fpath = "../out/leap-frog/n.dat";
    write_to_file(s, fpath);

//    gnuplot で
//    ```set size ratio -1
//       plot 'n.dat' with points pointtype 0```
//    でプロット
    return 0;
}