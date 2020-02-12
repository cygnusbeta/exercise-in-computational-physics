#include <string>
#include <iostream>
#include <iomanip>
#include "../util2.h"

using namespace std;

int main() {
    const int nPeople = 100000, nChip = 10000000;
    const long nExchange = 1000000000;
    int numsChip[nPeople] = {};

//    distribute
    for (int i = 0; i < nChip; i++) {
        int giveTo = get_random_0_to_n(nPeople);
        numsChip[giveTo] += 1;
    }
    string s1;
    for (int v : numsChip) {
        s1 += to_string(v) + "\n";
    }
    string fpath1 = "../out/dice_game/data1.dat";
    write_to_file(s1, fpath1);
//    filter(x,y)=int(x/y)*y; plot "data1.dat" u (filter($1,0.001)):(1) smooth frequency with boxes
//    でプロット

//    exchange
    cout << "Exchanging... " << flush;
    for (long i = 0; i < nExchange; i++) {
        int giveFrom, giveTo;
        do {
            giveFrom = get_random_0_to_n(nPeople);
            giveTo = get_random_0_to_n(nPeople);
        } while (giveTo == giveFrom || numsChip[giveFrom] == 0);
        numsChip[giveFrom] -= 1;
        numsChip[giveTo] += 1;
        if (i % long(double(nExchange - 1) * 0.1) == 0) {
            cout << setprecision(2) << 100.0 * double(i) / double(nExchange) << "% "<< flush;
        }
    }
    string s2;
    for (int v : numsChip) {
        s2 += to_string(v) + "\n";
    }
    string fpath2 = "../out/dice_game/data2.dat";
    write_to_file(s2, fpath2);
//    binwidth=1.0; set boxwidth binwidth; bin(x,width)=width*floor(x/width); plot 'data2.dat' using (bin($1,binwidth)):(1.0) smooth freq with boxes
//    でプロット
    return 0;
}
