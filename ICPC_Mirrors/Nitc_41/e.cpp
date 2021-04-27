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
    set<pair<int, int>> ss;
    for (size_t i = 0; i < n; i++)
        ss.insert({adj[i].size(), i});
    set<int> vis;
    vector<int> res;
    while (ss.size())
    {
        auto top = *ss.begin();
        ss.erase(ss.begin());

        int d = top.first;
        int node = top.second;

        if (vis.find(node) != vis.end())
            continue;
        vis.insert(node);
        db(d, node, adj[node]);
        assert(d == adj[node].size());

        if (d == 0)
        {
            res.pb(node);
        }
        else if (d == 1)
        {
            int nnext = -1;
            for (auto &x : adj[node])
            {
                // assert(vis.find(x) == vis.end());
                // adj[x].erase(node);
                nnext = x;
            }
            // adj[node].clear();

            node = nnext;
            vis.insert(node);
            res.pb(node);
            for (auto &x : adj[node])
            {
                // assert(vis.find(x) == vis.end());
                vis.insert(x);

                // auto it = ss.find({adj[x].size(), x});
                // assert(it != ss.end());
                // ss.erase(it);
                // adj[x].clear();
            }
        }
        else
        {
            res.pb(node);
            for (auto &x : adj[node])
            {
                // assert(vis.find(x) == vis.end());
                vis.insert(x);

                // auto it = ss.find({adj[x].size(), x});
                // assert(it != ss.end());
                // ss.erase(it);
                // adj[x].clear();
            }
        }
        adj[node].clear();
    }
    cout << res.size() << '\n';
    for (auto &x : res)
        cout << x + 1 << ' ';
    cout << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}