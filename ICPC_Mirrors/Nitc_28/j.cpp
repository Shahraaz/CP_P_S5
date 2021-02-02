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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, ll>>> adj(n);
    for (size_t i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    const ll INF = 1e16;
    vector<vector<ll>> dist(k + 2, vector<ll>(n, INF));
    vector<vector<ll>> vis(k + 2, vector<ll>(n, false));
    dist[0][0] = 0;
    for (int curr_k = 0; curr_k <= k; curr_k++)
    {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pQ;
        for (size_t i = 0; i < n; i++)
            if (dist[curr_k][i] != INF)
            {
                pQ.push({dist[curr_k][i], i});
            }
        db(curr_k, dist[curr_k]);
        while (pQ.size())
        {
            auto top = pQ.top();
            pQ.pop();
            int node = top.second;
            ll d = top.first;
            if (vis[curr_k][node])
                continue;
            db(top);
            vis[curr_k][node] = true;
            for (auto &x : adj[node])
                if (!vis[curr_k][x.first] && (dist[curr_k][x.first] > d + x.second))
                {
                    dist[curr_k][x.first] = d + x.second;
                    pQ.push({dist[curr_k][x.first], x.first});
                }
        }
        db(curr_k, dist[curr_k]);
        for (size_t i = 0; i < n; i++)
            for (auto &x : adj[i])
                dist[curr_k + 1][x.first] = min(dist[curr_k + 1][x.first], dist[curr_k][i]);
    }
    ll res = INF;
    for (size_t i = 0; i <= k; i++)
        res = min(res, dist[i][n - 1]);
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