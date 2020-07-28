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

const int NAX = 2e5 + 5, MOD = 1000000007;

int adj[451][451];
vector<int> adj_list[451];
int cost[451];
struct Solution
{
    Solution() {}
    void solveCase()
    {
        int n, m;
        while (cin >> n >> m)
        {
            memset(adj, 0, sizeof adj);
            for (size_t u = 1; u <= n; u++)
            {
                cin >> cost[u];
                adj_list[u].clear();
            }
            for (size_t i = 0; i < m; i++)
            {
                int u, v;
                cin >> u >> v;
                adj_list[u].pb(v);
                adj_list[v].pb(u);
                adj[u][v] = 1;
                adj[v][u] = 1;
            }
            int totalCost = 0;
            auto introvert = [&](vector<int> v) {
                sort(all(v), [&](int x, int y) {
                    return adj_list[x].size() < adj_list[y].size();
                });
                return v[0];
            };
            for (int u = 1; u <= n; u++)
            {
                totalCost = max(totalCost, cost[u]);
                for (int x = u + 1; x <= n; x++)
                {
                    if (!adj[u][x])
                        continue;
                    db(u, x, cost[u] + cost[x]);
                    totalCost = max(totalCost, cost[u] + cost[x]);
                    int temp = introvert({u, x});
                    for (auto &w : adj_list[temp])
                        if (adj[u][w] && adj[x][w])
                        {
                            db(u, x, w, cost[u] + cost[x] + cost[w]);
                            totalCost = max(totalCost, cost[u] + cost[x] + cost[w]);
                            auto next = introvert({temp, w});
                            for (auto &y : adj_list[next])
                                if (adj[y][u] && adj[y][x] && adj[y][w])
                                {
                                    db(u, x, w, y, cost[u] + cost[x] + cost[w] + cost[y]);
                                    totalCost = max(totalCost, cost[u] + cost[x] + cost[w] + cost[y]);
                                }
                        }
                }
            }
            cout << totalCost << '\n';
        }
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
