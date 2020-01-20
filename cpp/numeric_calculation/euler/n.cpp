#include <string>
#include "../../util.h"

using namespace std;

int main() {
    const double dt = 0.1, G = 1.0, M = 1.0, m = 1.0;
    int n = 2000;
    double x[n], y[n], v_x[n], v_y[n];
    x[0] = 0.5, y[0] = 0.0, v_x[0] = 0.0, v_y[0] = 1.63;
    for (int i = 0; i < n - 1; i++) {
        x[i + 1] = x[i] + v_x[i] * dt;
        y[i + 1] = y[i] + v_y[i] * dt;
        double r = sqrt(pow(x[i], 2) + pow(y[i], 2));
        v_x[i + 1] = v_x[i] - G * M * m * x[i] / (pow(r, 3) * m) * dt;
        v_y[i + 1] = v_y[i] - G * M * m * y[i] / (pow(r, 3) * m) * dt;
    }
    string s;
    for (int i = 0; i < n; i++) {
        s += to_string(x[i]) + " " + to_string(y[i]) + "\n";
    }
    string fpath = "../../out/euler/n.dat";
    write_to_file(s, fpath);

//    gnuplot で
//    ```set size ratio -1
//       plot 'n.dat' with points pointtype 0```
//    でプロット
    return 0;
}