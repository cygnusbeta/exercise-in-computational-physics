#include <string>
#include "../../util.h"

using namespace std;

#define tmax 100
#define n 1000
#define dt double(tmax) / double(n)
#define G 1.0
#define M 1.0
#define m 1.0

double f_dx_dt(double t, double _x, double _y, double _v_x, double _v_y) {
    return _v_x;
}

double g_dy_dt(double t, double _x, double _y, double _v_x, double _v_y) {
    return _v_y;
}

double h_dv_x_dt(double t, double _x, double _y, double _v_x, double _v_y) {
    double r = sqrt(pow(_x, 2) + pow(_y, 2));
    return -G * M * m * _x / (pow(r, 3) * m);
}

double i_dv_y_dt(double t, double _x, double _y, double _v_x, double _v_y) {
    double r = sqrt(pow(_x, 2) + pow(_y, 2));
    return -G * M * m * _y / (pow(r, 3) * m);
}

int main() {
    double t[n], x[n], y[n], v_x[n], v_y[n];
    t[0] = 0.0, x[0] = 0.5, y[0] = 0.0, v_x[0] = 0.0, v_y[0] = 1.63;

    for (int i = 0; i < n - 1; i++) {
        double k0 = dt * f_dx_dt(t[i], x[i], y[i], v_x[i], v_y[i]);
        double l0 = dt * g_dy_dt(t[i], x[i], y[i], v_x[i], v_y[i]);
        double m0 = dt * h_dv_x_dt(t[i], x[i], y[i], v_x[i], v_y[i]);
        double n0 = dt * i_dv_y_dt(t[i], x[i], y[i], v_x[i], v_y[i]);
        double k1 = dt * f_dx_dt(t[i] + dt / 2, x[i] + k0 / 2, y[i] + l0 / 2, v_x[i] + m0 / 2, v_y[i] + n0 / 2);
        double l1 = dt * g_dy_dt(t[i] + dt / 2, x[i] + k0 / 2, y[i] + l0 / 2, v_x[i] + m0 / 2, v_y[i] + n0 / 2);
        double m1 = dt * h_dv_x_dt(t[i] + dt / 2, x[i] + k0 / 2, y[i] + l0 / 2, v_x[i] + m0 / 2, v_y[i] + n0 / 2);
        double n1 = dt * i_dv_y_dt(t[i] + dt / 2, x[i] + k0 / 2, y[i] + l0 / 2, v_x[i] + m0 / 2, v_y[i] + n0 / 2);
        double k2 = dt * f_dx_dt(t[i] + dt / 2, x[i] + k1 / 2, y[i] + l1 / 2, v_x[i] + m1 / 2, v_y[i] + n1 / 2);
        double l2 = dt * g_dy_dt(t[i] + dt / 2, x[i] + k1 / 2, y[i] + l1 / 2, v_x[i] + m1 / 2, v_y[i] + n1 / 2);
        double m2 = dt * h_dv_x_dt(t[i] + dt / 2, x[i] + k1 / 2, y[i] + l1 / 2, v_x[i] + m1 / 2, v_y[i] + n1 / 2);
        double n2 = dt * i_dv_y_dt(t[i] + dt / 2, x[i] + k1 / 2, y[i] + l1 / 2, v_x[i] + m1 / 2, v_y[i] + n1 / 2);
        double k3 = dt * f_dx_dt(t[i] + dt, x[i] + k2, y[i] + l2, v_x[i] + m2, v_y[i] + n2);
        double l3 = dt * g_dy_dt(t[i] + dt, x[i] + k2, y[i] + l2, v_x[i] + m2, v_y[i] + n2);
        double m3 = dt * h_dv_x_dt(t[i] + dt, x[i] + k2, y[i] + l2, v_x[i] + m2, v_y[i] + n2);
        double n3 = dt * i_dv_y_dt(t[i] + dt, x[i] + k2, y[i] + l2, v_x[i] + m2, v_y[i] + n2);
        t[i + 1] = t[i] + dt;
        x[i + 1] = x[i] + (k0 + 2 * k1 + 2 * k2 + k3) / 6;
        y[i + 1] = y[i] + (l0 + 2 * l1 + 2 * l2 + l3) / 6;
        v_x[i + 1] = v_x[i] + (m0 + 2 * m1 + 2 * m2 + m3) / 6;
        v_y[i + 1] = v_y[i] + (n0 + 2 * n1 + 2 * n2 + n3) / 6;
    }
    string s;
    for (int i = 0; i < n; i++) {
        s += to_string(x[i]) + " " + to_string(y[i]) + "\n";
    }
    string fpath = "../out/runge-kutta/n.dat";
    write_to_file(s, fpath);

//    gnuplot で
//    ```set size ratio -1
//       plot 'n.dat' with points pointtype 0```
//    でプロット
    return 0;
}
