#include "Mt.h"

class Sample {
private:

    int d;
    double x_j;
    Mt mt;

public:
    ~Sample();

    bool run();

    double r2;

    Sample(int d, Mt mt);
};
