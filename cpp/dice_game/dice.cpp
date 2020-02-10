#include <cstdio>
#include <string>
#include "../util2.h"

using namespace std;

int main() {
    const int nPeople = 6, nChip = 30, numExchange = 100;
    int numsChip[nPeople];
    for (int i = 0; i < nPeople; i++) {
        numsChip[i] = 0;
    }

//    distribute
    for (int i = 0; i < nChip; i++) {
        int giveTo = get_random_0_to_n(nPeople);
        numsChip[giveTo] += 1;
    }

//    exchange
    for (int i = 0; i < numExchange; i++) {
        int giveFrom, giveTo;
        do {
            giveFrom = get_random_0_to_n(nPeople);
            giveTo = get_random_0_to_n(nPeople);
        } while (giveTo == giveFrom || numsChip[giveFrom] <= 0);
        numsChip[giveFrom] -= 1;
        numsChip[giveTo] += 1;
    }

    int histogram[nChip];
    for (int i = 0; i < nChip; i++) {
        histogram[i] = 0;
    }
    for (int i = 0; i < nPeople; i++) {
        int numChip = numsChip[i];
        histogram[numChip] += 1;
    }

    string s;
    for (int i = 0; i < nChip; i++) {
        s += to_string(i) + " " + to_string(histogram[i]) + "\n";
    }
    string fpath = "../out/dice_game/dice.dat";
    write_to_file(s, fpath);
//    plot "dice.dat" using 0:2:xtic(1) with boxes notitle
//    でプロット

    return 0;
}
