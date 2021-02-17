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
    vector<ll> t(n), dp(n), sz_subtree(n), sum_of_toll_subtree(n), sum_of_edges(n);
    for (auto &x : t)
        cin >> x;
    vector<vector<pair<int, int>>> adj(n);
    for (size_t i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
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

                // ll a = t[node] * sz_subtree[x.first] * x.second;
                // ll b = (sum_of_toll_subtree[x.first]) * x.second;
                ll a = x.second * sum_of_toll_subtree[x.first];
                // ll b = x.second * sz_subtree[x.first];

                // db(node, x.first, dp[x.first], a);
                dp[node] += dp[x.first];
                dp[node] += a;
                // dp[node] += b;
            }
        // db(node, par, dp[node], sz_subtree[node], sum_of_toll_subtree[node], dp[node] + t[node] * sum_of_edges[node]);
    };
    for (size_t i = 0; i < n; i++)
    {
        dfs(i, i);
        res[i] = dp[i] + t[i] * sum_of_edges[i];
        cout << res[i] << ' ';
    }
    cout << '\n';
    // dfs_reroot(0, 0);
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