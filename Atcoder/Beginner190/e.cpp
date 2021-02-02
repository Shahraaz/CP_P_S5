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
#define int ll
const int NAX = 2e5 + 5, MOD = 10000000007LL;

const int K = 17;

int dp[2 << K][K];

void solveCase()
{
    memset(dp, -1, sizeof dp);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (size_t i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int k;
    cin >> k;
    vector<int> c(k);
    vector<vector<int>> dist(k, vector<int>(n, MOD));
    for (size_t i = 0; i < k; i++)
    {
        cin >> c[i];
        --c[i];
        dist[i][c[i]] = 0;
        queue<int> Q;
        Q.push(c[i]);
        while (Q.size())
        {
            auto top = Q.front();
            Q.pop();
            for (auto &x : adj[top])
                if (dist[i][x] == MOD)
                {
                    dist[i][x] = dist[i][top] + 1;
                    Q.push(x);
                }
        }
        db(i, c[i], dist[i]);
    }
    int res = MOD;
    for (int mask = 1; mask < (1 << k); mask++)
    {
        int cnt = __builtin_popcount(mask);
        if (cnt == 1)
        {
            for (size_t i = 0; i < k; i++)
            {
                if (mask & (1 << i))
                    dp[mask][i] = 0;
            }
            // continue;
        }
        for (size_t i = 0; i < k; i++)
        {
            // db(bitset<10>(mask), i, dp[mask][i]);
            if (dp[mask][i] == -1)
                continue;

            db(bitset<10>(mask), i, dp[mask][i]);

            for (size_t j = 0; j < k; j++)
            {
                if (mask & (1 << j))
                {
                }
                else
                {
                    auto &now = dp[mask | (1 << j)][j];
                    ll newcost = dp[mask][i] + dist[i][c[j]];
                    if (now == -1 || now > newcost)
                        now = newcost;
                }
            }

            if (mask + 1 == (1 << k))
            {
                res = min(res, dp[mask][i]);
            }
        }
    }
    if (res == MOD)
        res = -1;
    else
        res++;
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
        solveCase();
    return 0;
}