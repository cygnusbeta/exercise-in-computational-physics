#include <cstdio>
#include <string>
#include "../../util.h"

using namespace std;

int main() {
    const float g = -9.8, theta = (1.0 / 4.0) * M_PI, v = 20.0;
    double t = 0.0, dt = 0.1, x = 0.0, v_x = v * cos(theta), z = 0.0, v_z = v * sin(theta);
    string s;
    s += to_string(x) + " " + to_string(z) + "\n";
    double tmax = 4.0;
    for (int n = 0; n < tmax / dt; n++) {
        t = dt * double(n + 1);
        z += v_z * dt;
        v_z += g * dt;
        x += v_x * dt;
        v_z += 0 * dt;
        s += to_string(x) + " " + to_string(z) + "\n";
    }
    string fpath = "../out/euler/fall2.dat";
    write_to_file(s, fpath);

    return 0;
}
