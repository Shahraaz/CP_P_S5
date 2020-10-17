#include "testlib.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    registerValidation();
    int n = inf.readInt(1, 1000);
    inf.readSpace();
    int m = inf.readInt(1, 1000);
    inf.readEoln();
    vector<bool> z(256);
    for (int i = 0; i < n; i++) {
        string s = inf.readLine();
        ensure(s.size() == m);
        for (int j = 0; j < m; j++) {
            char c = s[j];
            if (c != '.') {
                ensure(c >= 'A' && c <= 'Z');
                ensure(!z[c]);
                z[c] = true;
            }
        }
    }
    ensure(z['A']);
    inf.readEof();
}