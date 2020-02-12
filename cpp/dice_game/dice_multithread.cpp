#include <iostream>
#include <thread>
#include <iomanip>
#include <mutex>
#include "../util2.h"

using namespace std;
mutex mtx_;

const int nPeople = 100000, nChip = 10000000;
const long nExchange = 1000000000;
int numsChip[nPeople] = {};
int nCpuThread = int(thread::hardware_concurrency());

void changeCounter(int giveFrom, int giveTo) {
    // lock_guard<mutex> lock(mtx_);
    numsChip[giveFrom] -= 1;
    numsChip[giveTo] += 1;
}

void worker(int iThread)
{
    for (long i = iThread; i < nExchange; i += nCpuThread) {
        int giveFrom, giveTo;
        do {
            giveFrom = get_random_0_to_n(nPeople);
            giveTo = get_random_0_to_n(nPeople);
        } while (giveTo == giveFrom || numsChip[giveFrom] == 0);
        changeCounter(giveFrom, giveTo);
        if (i % long(double(nExchange - 1) * 0.1) == 0) {
            cout << setprecision(3) << 100.0 * double(i) / double(nExchange) << "% " << flush;
        }
    }
}

int main() {
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
    vector<thread> threads(nCpuThread);
    // spawn n threads:
    for (int iThread = 0; iThread < nCpuThread; iThread++) {
        threads[iThread] = thread(worker, iThread);
    }
    for (auto& t : threads) {
        t.join();
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
