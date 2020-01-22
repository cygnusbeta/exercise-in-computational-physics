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
        double k0 = f_dx_dt(t[i], x[i], y[i], v_x[i], v_y[i]);
        double l0 = g_dy_dt(t[i], x[i], y[i], v_x[i], v_y[i]);
        double m0 = h_dv_x_dt(t[i], x[i], y[i], v_x[i], v_y[i]);
        double n0 = i_dv_y_dt(t[i], x[i], y[i], v_x[i], v_y[i]);
        double k1 = f_dx_dt(t[i] + dt / 2.0, x[i] + dt / 2.0 * k0, y[i] + dt / 2.0 * l0, v_x[i] + dt / 2.0 * m0, v_y[i] + dt / 2.0 * n0);
        double l1 = g_dy_dt(t[i] + dt / 2.0, x[i] + dt / 2.0 * k0, y[i] + dt / 2.0 * l0, v_x[i] + dt / 2.0 * m0, v_y[i] + dt / 2.0 * n0);
        double m1 = h_dv_x_dt(t[i] + dt / 2.0, x[i] + dt / 2.0 * k0, y[i] + dt / 2.0 * l0, v_x[i] + dt / 2.0 * m0, v_y[i] + dt / 2.0 * n0);
        double n1 = i_dv_y_dt(t[i] + dt / 2.0, x[i] + dt / 2.0 * k0, y[i] + dt / 2.0 * l0, v_x[i] + dt / 2.0 * m0, v_y[i] + dt / 2.0 * n0);
        double k2 = f_dx_dt(t[i] + dt / 2.0, x[i] + dt / 2.0 * k1, y[i] + dt / 2.0 * l1, v_x[i] + dt / 2.0 * m1, v_y[i] + dt / 2.0 * n1);
        double l2 = g_dy_dt(t[i] + dt / 2.0, x[i] + dt / 2.0 * k1, y[i] + dt / 2.0 * l1, v_x[i] + dt / 2.0 * m1, v_y[i] + dt / 2.0 * n1);
        double m2 = h_dv_x_dt(t[i] + dt / 2.0, x[i] + dt / 2.0 * k1, y[i] + dt / 2.0 * l1, v_x[i] + dt / 2.0 * m1, v_y[i] + dt / 2.0 * n1);
        double n2 = i_dv_y_dt(t[i] + dt / 2.0, x[i] + dt / 2.0 * k1, y[i] + dt / 2.0 * l1, v_x[i] + dt / 2.0 * m1, v_y[i] + dt / 2.0 * n1);
        double k3 = f_dx_dt(t[i] + dt, x[i] + dt * k2, y[i] + dt * l2, v_x[i] + dt * m2, v_y[i] + dt * n2);
        double l3 = g_dy_dt(t[i] + dt, x[i] + dt * k2, y[i] + dt * l2, v_x[i] + dt * m2, v_y[i] + dt * n2);
        double m3 = h_dv_x_dt(t[i] + dt, x[i] + dt * k2, y[i] + dt * l2, v_x[i] + dt * m2, v_y[i] + dt * n2);
        double n3 = i_dv_y_dt(t[i] + dt, x[i] + dt * k2, y[i] + dt * l2, v_x[i] + dt * m2, v_y[i] + dt * n2);
        t[i + 1] = t[i] + dt;
        x[i + 1] = x[i] + (dt / 6.0) * (k0 + 2.0 * k1 + 2.0 * k2 + k3);
        y[i + 1] = y[i] + (dt / 6.0) * (l0 + 2.0 * l1 + 2.0 * l2 + l3);
        v_x[i + 1] = v_x[i] + (dt / 6.0) * (m0 + 2.0 * m1 + 2.0 * m2 + m3);
        v_y[i + 1] = v_y[i] + (dt / 6.0) * (n0 + 2.0 * n1 + 2.0 * n2 + n3);
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
