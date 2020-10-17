#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int k = atoi(argv[3]);

    string chars;
    for (char c = 'A'; c <= 'Z'; c++) chars += c;
    for (int i = 2; i < chars.size(); i++) {
        int j = rnd.next(1, i);
        swap(chars[i], chars[j]);
    }

    vector<vector<char>> a(n, vector<char>(m, '.'));
    for (int i = 0; i < k; i++) {
        int x, y;
        while (true) {
            x = rnd.next(n);
            y = rnd.next(m);
            if (a[x][y] == '.') break;
        }
        a[x][y] = chars[i];
    }

    cout << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << a[i][j];
        cout << "\n";
    }
}