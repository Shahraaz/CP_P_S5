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
const int NAX = 1e5 + 5, MOD = 1000000007;

void solveCase()
{
    using ld = long double;
    const ld EPS = 1e-7;
    vector<ld> dp(NAX);
    dp[1] = 0.5;
    for (size_t i = 2; i < NAX; i++)
    {
        ld curr = (1 / ld(i));
        dp[i] = curr + (1 - curr) * (1 - dp[i - 1]);
    }
    int x;
    while (cin >> x)
    {
        db(x, dp[x]);
        if (abs(dp[x] - 0.5) <= EPS)
            cout << "0\n";
        else if (dp[x] >= 0.5)
            cout << "1\n";
        else
            cout << "2\n";
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