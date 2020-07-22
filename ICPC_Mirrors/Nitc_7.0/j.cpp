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

const int NAX = 1e2 + 5, MOD = 1000000007;

int adj[NAX][NAX];
// vector<pair<int, int>> adj[NAX];
vector<pair<int, pair<int, int>>> edges;
ll noOfPaths[NAX][NAX][5][NAX];
ll dp[NAX];

struct Solution
{
    Solution() {}
    void solveCase()
    {
        int n, m;
        cin >> n >> m;
        for (size_t i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u][v] = w;
            adj[v][u] = w;
            edges.pb({u, {v, w}});
            edges.pb({v, {u, w}});
            noOfPaths[u][v][1][w]++;
            noOfPaths[v][u][1][w]++;
        }
        const int LIM = n;
        for (int edgeCnt = 2; edgeCnt <= 4; edgeCnt++)
        {
            for (auto &e : edges)
            {
                int src = e.f;
                int dest = e.s.f;
                int wt = e.s.s;
                for (int v = 1; v <= n; v++)
                    for (int w = 1; w <= LIM; w++)
                        noOfPaths[src][v][edgeCnt][max(wt, w)] += noOfPaths[dest][v][edgeCnt - 1][w];
            }
            db(edgeCnt);
            for (int w = 1; w <= LIM; w++)
            {
                db(w);
                for (size_t u = 1; u <= n; u++)
                    for (size_t v = 1; v <= n; v++)
                    {
                        db(u, v, w, noOfPaths[u][v][edgeCnt][w]);
                    }
            }
            db("-----------");
        }
        for (int w = 1; w <= LIM; w++)
            for (size_t u = 1; u <= n; u++)
                for (size_t v = 1; v <= n; v++)
                {
                    dp[w] += noOfPaths[u][v][4][w];
                    db(u, v, w, noOfPaths[u][v][4][w]);
                }
        int q;
        cin >> q;
        while (q--)
        {
            int x;
            cin >> x;
            cout << dp[x] << '\n';
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
