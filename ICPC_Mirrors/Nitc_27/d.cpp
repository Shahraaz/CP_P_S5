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

int n, m;
vector<vector<pair<int, int>>> adj;
bool isBridge[NAX];
int st_time[NAX], mn_time[NAX], curr = 1;

void dfs(int node, int par)
{
    st_time[node] = mn_time[node] = curr++;
    for (auto &x : adj[node])
    {
        if (st_time[x.first] > 0)
        {
            if (x.first != par)
            {
                mn_time[node] = min(st_time[x.first], mn_time[node]);
                isBridge[x.second] = false;
            }
        }
        else
        {
            dfs(x.first, node);
            mn_time[node] = min(mn_time[node], mn_time[x.first]);
            if (mn_time[x.first] <= st_time[node])
                isBridge[x.second] = false;
        }
        db(node, x, isBridge[x.second]);
    }
}

void solveCase()
{
    cin >> n >> m;
    adj.resize(n);
    fill(isBridge, isBridge + m, 1);
    for (size_t i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
        // --u, --v;
    }
    dfs(0, 0);
    int cnt = 1;
    vector<int> vis(n);
    queue<int> Q;
    Q.push(0);
    vis[0] = 1;
    while (Q.size())
    {
        auto top = Q.front();
        Q.pop();
        for (auto &x : adj[top])
            if (!vis[x.first] && !isBridge[x.second])
            {
                cnt++;
                vis[x.first] = 1;
                Q.push(x.first);
            }
    }
    cout << cnt << '\n';
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