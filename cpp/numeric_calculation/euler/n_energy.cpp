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
    string s, s_theory;
    double r = sqrt(pow(x[0], 2) + pow(y[0], 2));
    double v = sqrt(pow(v_x[0], 2) + pow(v_y[0], 2));
    double energy_theory = (1.0 / 2.0) * m * pow(v, 2) - G * M * m / r;
    for (int i = 0; i < n; i++) {
        double t = dt * i;
        r = sqrt(pow(x[i], 2) + pow(y[i], 2));
        v = sqrt(pow(v_x[i], 2) + pow(v_y[i], 2));
        double energy = (1.0 / 2.0) * m * pow(v, 2) - G * M * m / r;
        s += to_string(t) + " " + to_string(energy) + "\n";
        s_theory += to_string(t) + " " + to_string(energy_theory) + "\n";
    }
    string fpath = "../out/euler/n_energy.dat";
    write_to_file(s, fpath);
    string f_theory_path = "../out/euler/n_energy_theory.dat";
    write_to_file(s_theory, f_theory_path);

//    gnuplot で
//    ```set size ratio -1
//       plot 'n_energy.dat', 'n_energy_theory.dat' with points pointtype 0```
//    でプロット
    return 0;
}