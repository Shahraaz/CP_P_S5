#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int MAX = 1000;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int k = atoi(argv[3]);

    n *= 4;
    m *= 4;

    string chars;
    for (char c = 'A'; c <= 'Z'; c++) chars += c;
    for (int i = 2; i < chars.size(); i++) {
        int j = rnd.next(1, i);
        swap(chars[i], chars[j]);
    }
    swap(chars[0], chars[4]);

    vector<vector<char>> a(n, vector<char>(m, '.'));
    int q = 0;
    for (int i = 0; i < n / 4; i++) {
        for (int j = 0; j < m / 4; j++) {
            int x;
            if (k == 0) x = 0;
            if (k == 1) x = 1;
            if (k == 2) x = (i + j) % 2;
            if (k == 3) x = rnd.next(2);
            if (x == 0) {
                a[i * 4 + 0][j * 4 + 0] = chars[q++];
                a[i * 4 + 0][j * 4 + 3] = chars[q++];
                a[i * 4 + 2][j * 4 + 0] = chars[q++];
                a[i * 4 + 3][j * 4 + 2] = chars[q++];
                a[i * 4 + 3][j * 4 + 3] = chars[q++];
            } else {
                a[i * 4 + 0][j * 4 + 0] = chars[q++];
                a[i * 4 + 3][j * 4 + 0] = chars[q++];
                a[i * 4 + 0][j * 4 + 2] = chars[q++];
                a[i * 4 + 2][j * 4 + 3] = chars[q++];
                a[i * 4 + 3][j * 4 + 3] = chars[q++];
            }
        }
    }

    int nn = MAX / n * n;
    int mm = MAX / m * m;
    vector<vector<char>> aa(nn, vector<char>(mm, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            aa[MAX / n * i][MAX / m * j] = a[i][j];
        }
    }
    n = nn;
    m = mm;
    a = aa;

    cout << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << a[i][j];
        cout << "\n";
    }

}