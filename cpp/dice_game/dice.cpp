#include <cstdio>
#include <string>
#include "../util2.h"

using namespace std;

int main() {
    const int nPeople = 50, nChip = 500, numExchange = 100000;
    int numsChip[nPeople];
    for (int i = 0; i < nPeople; i++) {
        numsChip[i] = 0;
    }

//    distribute
    for (int i = 0; i < nChip; i++) {
        int giveTo = get_random_0_to_n(nPeople);
        numsChip[giveTo] += 1;
    }

//    count chips
    int histogram[nChip];
    for (int i = 0; i < nChip; i++) {
        histogram[i] = 0;
    }
    for (int i = 0; i < nPeople; i++) {
        int numChip = numsChip[i];
        histogram[numChip] += 1;
    }
    int maxChip = 0;
    for (int i = nChip - 1; i >= 0; i--) {
        if (histogram[i] >= 1) {
            maxChip = i;
            break;
        }
    }

    string s;
    for (int i = 0; i < maxChip + 1; i++) {
        s += to_string(i) + " " + to_string(histogram[i]) + "\n";
    }

    string fpath1 = "../out/dice_game/dice1.dat";
    write_to_file(s, fpath1);

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

//    count chips
    int histogram2[nChip];
    for (int i = 0; i < nChip; i++) {
        histogram2[i] = 0;
    }
    for (int i = 0; i < nPeople; i++) {
        int numChip = numsChip[i];
        histogram2[numChip] += 1;
    }
    int maxChip2 = 0;
    for (int i = nChip - 1; i >= 0; i--) {
        if (histogram2[i] >= 1) {
            maxChip2 = i;
            break;
        }
    }

    string s2;
    for (int i = 0; i < maxChip2 + 1; i++) {
        s2 += to_string(i) + " " + to_string(histogram2[i]) + "\n";
    }

    string fpath2 = "../out/dice_game/dice2.dat";
    write_to_file(s2, fpath2);
//    plot "dice.dat" using 0:2:xtic(1) with boxes notitle
//    でプロット

    return 0;
}
