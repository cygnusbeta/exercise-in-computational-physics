//ransu.C
#include <iostream>
#include <cstdlib>
#define RAND()(float(rand())/(RAND_MAX+1.0))

using namespace std;


int main()
{
    for (int i=1; i<=10; ++i){
        double r = RAND();
        cout << r << "\n";
    }
}
