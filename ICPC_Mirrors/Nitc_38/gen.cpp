#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

#define all(v) v.begin(), v.end()
#define pb push_back
using ll = long long;
const int NAX = 2e5 + 5, MOD = 1000000007;

void solveCase()
{
    int n;
    cin >> n;
    using ld = long double;
    vector<vector<ld>> vecc(n + 1);
    for (size_t i = 0; i <= n; i++)
    {
        vecc[i].resize(n);
        for (auto &x : vecc[i])
            cin >> x;
        db(i, vecc[i]);
        for (size_t j = 0; j < i; j++)
        {
            ll d = 0;
            for (size_t k = 0; k < n; k++)
                d += (vecc[i][k] - vecc[j][k]) * (vecc[i][k] - vecc[j][k]);
            d = sqrtl(d);
            db(i, j, d);
        }
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
        solveCase();
    return 0;
}