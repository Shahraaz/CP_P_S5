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
    int n = 300, m = 1e4, k = 1e4;

    cin >> n >> m >> k;

    int src = 1, dest = n;

    cin >> src >> dest;
    --src, --dest;

    vector<int> disc(k);
    for (auto &x : disc)
    {
        x = rand() % 1000;
        cin >> x;
    }
    k = min(k, n + 1);
    sort(all(disc));
    reverse(all(disc));
    vector<vector<pair<int, int>>> adj(n);
    for (size_t i = 0; i < m; i++)
    {
        int u = rand() % n, v = rand() % n, w = rand() % MOD + 1000;

        cin >> u >> v >> w;
        --u, --v;

        adj[u].pb({v, w});
        // adj[v].pb({u, w});
    }
    const ll INF = 1e15;
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> Q;
    vector<vector<int>> vis(n, vector<int>(k + 1));
    vector<vector<ll>> dist(n, vector<ll>(k + 1, INF));
    dist[src][0] = 0;
    Q.push({0, {src, 0}});
    while (Q.size())
    {
        auto top = Q.top();
        Q.pop();
        ll d = top.first;
        int node = top.second.first;
        int idx = top.second.second;
        db(d, node, idx);
        if (vis[node][idx] || d > dist[node][idx])
            continue;
        vis[node][idx] = 1;
        for (auto &c : adj[node])
        {
            if (vis[c.first][idx] == false)
            {
                if (dist[c.first][idx] > d + c.second)
                {
                    dist[c.first][idx] = d + c.second;
                    Q.push({dist[c.first][idx], {c.first, idx}});
                }
            }
            if (idx < k && vis[c.first][idx + 1] == false)
            {
                if (dist[c.first][idx + 1] > d + c.second - disc[idx])
                {
                    dist[c.first][idx + 1] = d + c.second - disc[idx];
                    Q.push({dist[c.first][idx + 1], {c.first, idx + 1}});
                }
            }
        }
    }
    ll best = INF;
    for (size_t i = 0; i <= k; i++)
        best = min(best, dist[dest][i]);
    if (best >= INF)
        best = -1;
    cout << best << '\n';
    // cout.flush();
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 20;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}