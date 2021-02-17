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

#define int ll

void solveCase()
{
    int n;
    cin >> n;
    vector<ll> t(n), dp(n), sz_subtree(n), sum_of_toll_subtree(n), sum_of_edges(n);
    for (auto &x : t)
        cin >> x;
    vector<vector<pair<int, int>>> adj(n);
    for (size_t i = 1; i < n; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        --u, --v;
        adj[u].pb({v, wt});
        adj[v].pb({u, wt});
    }
    vector<int> res(n);
    function<void(int, int)> dfs = [&](int node, int par) -> void {
        sz_subtree[node] = 1;
        sum_of_toll_subtree[node] = t[node];
        sum_of_edges[node] = 0;
        dp[node] = 0;
        for (auto &x : adj[node])
            if (x.first != par)
            {
                dfs(x.first, node);

                sum_of_toll_subtree[node] += sum_of_toll_subtree[x.first];
                sz_subtree[node] += sz_subtree[x.first];

                sum_of_edges[node] += sum_of_edges[x.first];
                sum_of_edges[node] += x.second * sz_subtree[x.first];

                dp[node] += dp[x.first] + x.second * sum_of_toll_subtree[x.first];
            }
    };
    function<void(int, int)> dfs_reroot = [&](int node, int par) -> void {
        res[node] = dp[node] + t[node] * sum_of_edges[node];
        ll dp_node = dp[node];
        ll sum_of_toll_node = sum_of_toll_subtree[node];
        ll sum_of_edges_node = sum_of_edges[node];
        ll sz_subtree_node = sz_subtree[node];
        for (auto &x : adj[node])
            if (x.first != par)
            {
                dp[node] -= dp[x.first] + sum_of_toll_subtree[x.first] * x.second;

                sum_of_edges[node] -= x.second * sz_subtree[x.first];
                sum_of_edges[node] -= sum_of_edges[x.first];

                sz_subtree[node] -= sz_subtree[x.first];
                sum_of_toll_subtree[node] -= sum_of_toll_subtree[x.first];

                // part two
                ll dp_xf = dp[x.first];
                ll sum_of_toll_xf = sum_of_toll_subtree[x.first];
                ll sum_of_edges_xf = sum_of_edges[x.first];
                ll sz_subtree_xf = sz_subtree[x.first];

                sum_of_toll_subtree[x.first] += sum_of_toll_subtree[node];
                sz_subtree[x.first] += sz_subtree[node];
                sum_of_edges[x.first] += sum_of_edges[node];
                sum_of_edges[x.first] += x.second * sz_subtree[node];

                dp[x.first] += dp[node] + sum_of_toll_subtree[node] * x.second;

                dfs_reroot(x.first, node);

                dp[x.first] = dp_xf;
                sum_of_toll_subtree[x.first] = sum_of_toll_xf;
                sum_of_edges[x.first] = sum_of_edges_xf;
                sz_subtree[x.first] = sz_subtree_xf;

                dp[node] = dp_node;
                sum_of_toll_subtree[node] = sum_of_toll_node;
                sum_of_edges[node] = sum_of_edges_node;
                sz_subtree[node] = sz_subtree_node;
            }
    };
    dfs(0, 0);
    dfs_reroot(0, 0);
    for (size_t i = 0; i < n; i++)
        cout << res[i] << '\n';
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