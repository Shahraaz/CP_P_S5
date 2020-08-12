// Optimise
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()

const int NAX = 8, MOD = 1000000007;

int k, n, b[NAX][NAX], l[NAX];
int t[7 * 7 * 7 * 7 * 7 * 7 * 7 + 5];
const int MAGICROW = 2;
int key = 0;

int rec(int row, int col)
{
    db(row, k);
    if (row >= k)
        return 1;
    db(col, l[row]);
    if (col >= l[row])
        return rec(row + 1, 0);
    // cout << row << ' ' << col << '\n';

    if (row == MAGICROW && col == 0)
    {
        key = 0;
        for (size_t i = 0; i < l[row - 1]; i++)
            key = key * n + b[row - 1][i] - 1;
        if (t[key] >= 0)
            return t[key];
    }
    int ret = 0;
    int s = 1;
    if (row > 0)
        s = max(s, 1 + b[row - 1][col]);
    if (col > 0)
        s = max(s, b[row][col - 1]);
    for (size_t i = s; i <= n; i++)
    {
        b[row][col] = i;
        ret += rec(row, col + 1);
    }
    if (row == MAGICROW && col == 0)
    {
        // cout << key << ' ' << ret << '\n';
        t[key] = ret;
    }
    return ret;
}

struct Solution
{
    Solution() {}
    void solveCase()
    {
        k;
        while (cin >> k)
        {
            memset(t, -1, sizeof t);
            for (size_t i = 0; i < k; i++)
                cin >> l[i];
            cin >> n;
            // cout << n << ' ' << k << '\n';
            int total = 0;
            for (size_t i = 1; i <= n; i++)
            {
                b[0][0] = i;
                total += rec(0, 1);
            }
            cout << total << '\n';
        }
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
