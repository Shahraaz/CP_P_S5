#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, 10, "t");
    inf.readEoln();
    forn(tt, t) {
        int n = inf.readInt(3, 2000, "n");
        inf.readEoln();
        inf.readInts(n, 1, 1000000000, "a");
        inf.readEoln();
    }
    inf.readEof();
}
