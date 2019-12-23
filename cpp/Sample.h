#include "util.h"

class Sample {
private:

    int d;
    double x_j;
    util mt;

public:
    ~Sample();

    bool run();

    double r2;

    Sample(int d, util mt);
};
