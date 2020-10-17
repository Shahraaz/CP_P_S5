#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int t = atoi(argv[1]);
    int n = atoi(argv[2]);
    int m = atoi(argv[3]);
    println(t);
    forn(tt, t) {
        int n_ = rnd.next(3, n);
        int m_ = rnd.next(1, m);
        println(n_);
        vector<int> a(n_);
        forn(i, n_)
            a[i] = rnd.next(1, m_);
        println(a);
    }
}
