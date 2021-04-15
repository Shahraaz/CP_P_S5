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
const int NAX = 500 + 5, MOD = 1000000007;

ll dp[NAX][NAX];
ll tt[NAX][NAX];

void solveCase()
{
    int n, m;
    cin >> n >> m;
    int curr, prev = n + 1;
    for (size_t i = 0; i < m; i++)
    {
        cin >> curr;
        tt[prev][curr]++;
        prev = curr;
    }

    for (size_t i = 1; i <= n + 1; i++)
        for (size_t j = 1; j <= n; j++)
            tt[i][j] = tt[i][j] + tt[i][j - 1] + tt[i - 1][j] - tt[i - 1][j - 1];

    auto c = [&](int l1, int r1, int l2, int r2) -> long long { return tt[r1][r2] - tt[r1][l2 - 1] - tt[l1 - 1][r2] + tt[l1 - 1][l2 - 1]; };

    auto cost = [&](int l, int r) -> long long { return c(l, r, 1, n) + c(1, n + 1, l, r) - 2 * c(l, r, l, r); };

    for (int l = n; l >= 1; l--)
        for (int r = l; r <= n; r++)
        {
            long long minc = LLONG_MAX;
            for (int u = l; u <= r; u++)
                minc = min(minc, dp[l][u - 1] + dp[u + 1][r]);
            dp[l][r] = cost(l, r) + minc;
            db(l, r, dp[l][r], minc);
        }

    cout << dp[1][n] - 1 << '\n';
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