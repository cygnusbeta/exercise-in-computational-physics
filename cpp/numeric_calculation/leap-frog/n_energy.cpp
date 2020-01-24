#include <string>
#include "../../util.h"

using namespace std;

int main() {
    const int tmax = 100;
    const int n = 1000;
    const double dt = double(tmax) / double(n), G = 1.0, M = 1.0, m = 1.0;
    double x[2 * n], y[2 * n], v_x[2 * (n + 1)], v_y[2 * (n + 1)];
    x[0] = 0.5, y[0] = 0.0, v_x[0] = 0.0, v_y[0] = 1.63;

    double r = sqrt(pow(x[0], 2) + pow(y[0], 2));
    v_x[1] = v_x[0] - G * M * m * x[0] / (pow(r, 3) * m) * dt * 0.5;
    v_y[1] = v_y[0] - G * M * m * y[0] / (pow(r, 3) * m) * dt * 0.5;
    for (long i = 0; i < n - 1; i++) {
        x[2 * (i + 1)] = x[2 * i] + v_x[2 * i + 1] * dt;
        y[2 * (i + 1)] = y[2 * i] + v_y[2 * i + 1] * dt;
        r = sqrt(pow(x[2 * (i + 1)], 2) + pow(y[2 * (i + 1)], 2));
        v_x[2 * i + 3] = v_x[2 * i + 1] - G * M * m * x[2 * (i + 1)] / (pow(r, 3) * m) * dt;
        v_y[2 * i + 3] = v_y[2 * i + 1] - G * M * m * y[2 * (i + 1)] / (pow(r, 3) * m) * dt;
    }
    string s, s_theory, s_error;
    r = sqrt(pow(x[0], 2) + pow(y[0], 2));
    double v = sqrt(pow(v_x[0], 2) + pow(v_y[0], 2));
    double energy_theory = (1.0 / 2.0) * m * pow(v, 2) - G * M * m / r;
    for (int i = 0; i < n; i++) {
        double t = dt * i;
        r = sqrt(pow(x[2 * i], 2) + pow(y[2 * i], 2));
        v = sqrt(pow(v_x[2 * i + 1], 2) + pow(v_y[2 * i + 1], 2));
        double energy = (1.0 / 2.0) * m * pow(v, 2) - G * M * m / r;
        s += to_string(t) + " " + to_string(energy) + "\n";
        s_theory += to_string(t) + " " + to_string(energy_theory) + "\n";
        s_error += to_string(t) + " " + to_string(abs(energy_theory - energy)) + "\n";
    }
    string fpath = "../out/leap-frog/n_energy.dat";
    write_to_file(s, fpath);
    string f_theory_path = "../out/leap-frog/n_energy_theory.dat";
    write_to_file(s_theory, f_theory_path);
    string f_error = "../out/leap-frog/n_energy_error.dat";
    write_to_file(s_error, f_error);

//    gnuplot で
//    ```set size ratio -1
//       plot 'n.dat' with points pointtype 0```
//    でプロット
    return 0;
}