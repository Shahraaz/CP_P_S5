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

const int NAX = 501, MOD = 1000000007;

ll dp[2][NAX][NAX], INF = 1e16;
int n, S1, S2;
int x[NAX], t[NAX], y[NAX], r[NAX];

void self_min(ll &a, ll b)
{
    a = min(a, b);
}

void solveCase()
{
    cin >> n >> S1 >> S2;
    vector<vector<int>> vecc;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> t[i] >> y[i] >> r[i];
        vecc.pb({x[i], t[i], y[i], r[i]});
    }
    sort(all(vecc));
    // reverse(all(vecc));
    for (int i = 0; i < n; i++)
    {
        x[i] = vecc[i][0];
        t[i] = vecc[i][1];
        y[i] = vecc[i][2];
        r[i] = vecc[i][3];
    }
    int curr = 0, next = 1;
    for (size_t i = 0; i < NAX; i++)
        for (size_t j = 0; j < NAX; j++)
            dp[curr][i][j] = INF;
    dp[curr][0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < NAX; j++)
            for (int k = 0; k < NAX; k++)
                dp[next][j][k] = INF;
        for (int j = 0; j < NAX; j++)
            for (int k = 0; k < NAX; k++)
            {
                self_min(dp[next][j][k], dp[curr][j][k]);
+
                if (j < S1)
                {
                    int maxj = j + x[i];
                    int diff = 0;
                    if (maxj >= S1)
                    {
                        diff = maxj - S1;
                        maxj = S1;
                    }
                    int maxk = k + diff;
                    if (maxk >= NAX)
                        maxk = 500;
                    self_min(dp[next][maxj][maxk], dp[curr][j][k] + t[i]);
                }
                int maxk = k + y[i];
                maxk = min(maxk, 500);
                self_min(dp[next][j][maxk], dp[curr][j][k] + r[i]);
            }
        curr = 1 - curr;
        next = 1 - next;
        db(i);
        // for (size_t i = 0; i < NAX; i++)
        // {
        //     for (size_t j = 0; j < NAX; j++)
        //         cout << dp[curr][i][j] << ' ';
        //     cout << '\n';
        // }
    }
    ll res = INF;
    for (size_t i = S1; i < NAX; i++)
        for (size_t j = S2; j < NAX; j++)
            res = min(res, dp[curr][i][j]);
    if (res >= INF)
        res = -1;
    cout << res << '\n';
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
