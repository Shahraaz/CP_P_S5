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

using ld = long double;
const ld EPS = 1e-7;

void solveCase()
{
    int n;
    cin >> n;
    vector<int> c(n);
    for (auto &x : c)
        cin >> x;
    sort(all(c));
    ld res = 1;
    for (size_t i = 0; i < n; i++)
    {
        if (c[i] > (i + 1))
        {
            cout << -1 << '\n';
            return;
        }
        res = min(res, c[i] / (i + (ld)1));
    }
    cout << fixed << res << '\n';
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
