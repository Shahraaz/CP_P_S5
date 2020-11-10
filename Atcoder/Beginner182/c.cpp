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

const int NAX = 2e5 + 5, MOD = 1000000007;

void solveCase()
{
    string str;
    cin >> str;
    vector<int> cnt(3);
    for (auto &x : str)
        cnt[(x - '0') % 3]++;
    if (cnt[0] == 0)
    {
        if (cnt[2] == 0)
            if (cnt[1] % 3)
            {
                cout << -1 << '\n';
                return;
            }
        if (cnt[1] == 0)
            if (cnt[2] % 3)
            {
                cout << -1 << '\n';
                return;
            }
    }
    int now = (1 * cnt[1] + 2 * cnt[2]) % 3;
    if (now == 0)
        cout << 0 << '\n';
    else if (now == 1)
    {
        if (cnt[1])
            cout << 1 << '\n';
        else
            cout << 2 << '\n';
    }
    else if (now == 2)
    {
        if (cnt[2])
            cout << 1 << '\n';
        else
            cout << 2 << '\n';
    }
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
