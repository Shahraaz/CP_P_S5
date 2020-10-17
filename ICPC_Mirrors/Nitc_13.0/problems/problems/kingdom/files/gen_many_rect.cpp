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

    string chars;
    for (char c = 'A'; c <= 'Z'; c++) chars += c;
    for (int i = 2; i < chars.size(); i++) {
        int j = rnd.next(1, i);
        swap(chars[i], chars[j]);
    }

    vector<pair<pair<int, int>, pair<int, int>>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            q.push_back({{i * j, rnd.next(1000000000)}, {i, j}});
        }
    }

    int p = (k - 1) / 2 + 1;

    sort(q.begin(), q.end());
    double mind = 1e100;
    int ii = 0;
    int jj = 0;
    int j = 0;
    for (int i = 0; ; i++) {
        while (j < q.size() && q[j].first.first <= q[i].first.first) j++;
        if (j == q.size()) break;
        if (j - i + 1 >= p) {
            double d = 1.0 * q[j].first.first / q[i].first.first;
            if (d < mind) {
                mind = d;
                ii = i;
                jj = j;
            }
        }
    }

    vector<pair<int, int>> w;
    for (int i = 0; i < p; i++) {
        auto x = q[ii + i];
        if (i == p - 1) x = q[jj];
        w.push_back(x.second);
    }
    sort(w.begin(), w.end());

//    for (auto x : w) {
//        cerr << x.first << " " << x.second << " " << x.first * x.second << "\n";
//    }

    vector<int> x(p);
    vector<int> y(p);
    for (int i = 1; i < p; i++) {
        x[i] = rnd.next(x[i - 1] + w[i - 1].first - w[i].first, x[i - 1] );
        y[i] = rnd.next(y[i - 1], y[i - 1] + w[i - 1].second - w[i].second);
    }
    for (int i = 0; i < p; i++) {
        x[i] -= x[p - 1];
    }

    n = w[p - 1].first;
    m = w[0].second;

    vector<vector<char>> a(n, vector<char>(m, '.'));
    a[rnd.next(x[0], x[0] + w[0].first - 1)]
     [rnd.next(y[p - 1], y[p - 1] + w[p - 1].second - 1)] = 'A';
    j = 1;
    for (int i = 1; i < p; i++) {
        if (x[i - 1] - 1 >= 0 && y[i] - 1 >= 0)
            a[x[i - 1] - 1][y[i] - 1] = chars[j++];
        if (x[i - 1] + w[i - 1].first < n && y[i] + w[i].second < m)
            a[x[i - 1] + w[i - 1].first][y[i] + w[i].second] = chars[j++];
    }
    assert(j <= k);

    cout << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << a[i][j];
        cout << "\n";
    }
}