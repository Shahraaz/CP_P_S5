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

//Here it is an unweighted tree
//If you want to solve for thath then
//You have to go for Dist(a,b) = Dist(a) + Dist(b) - 2*Dist(lca(a,b))
// where Dist(a) is distance from Root to a;
struct LeastCommonAncestor
{
    vector<int> Level;
    vector<vector<int>> dp;
    vector<vector<int>> Adj;
    int Log;
    LeastCommonAncestor() {}
    LeastCommonAncestor(vector<vector<int>> &Tree) : Adj(Tree)
    {
        int n = Tree.size();
        Log = ceil(log2(n)) + 1;
        dp.assign(Log, vector<int>(n));
        Level.assign(n, 0);
        dfs(0, 0, 0);
        for (int i = 1; i < Log; ++i)
            for (int j = 0; j < n; ++j)
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
    }
    void dfs(int node, int parent, int level)
    {
        dp[0][node] = parent;
        Level[node] = level;
        for (auto child : Adj[node])
            if (child != parent)
                dfs(child, node, level + 1);
    }
    int lca(int a, int b)
    {
        if (Level[a] > Level[b])
            swap(a, b);
        int d = Level[b] - Level[a];
        for (int i = 0; i < Log; ++i)
            if (d & (1 << i))
                b = dp[i][b];
        if (a == b)
            return a;
        for (int i = Log - 1; i >= 0; --i)
            if (dp[i][a] != dp[i][b])
            {
                a = dp[i][a];
                b = dp[i][b];
            }
        return dp[0][a];
    }
    int dist(int a, int b)
    {
        return Level[a] + Level[b] - 2 * Level[lca(a, b)];
    }
};

void solveCase()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> val(n), lmin(n), rmax(n);
    vector<pair<int, int>> vecc;
    for (size_t i = 0; i < n; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        val[i] = k;
        vecc.pb({k, i});
        if (l)
            adj[i].pb(l - 1);
        if (r)
            adj[i].pb(r - 1);
    }
    LeastCommonAncestor lca(adj);
    function<void(int, int)> dfs = [&](int node, int par) -> void {
        lmin[node] = rmax[node] = val[node];
        for (auto &x : adj[node])
        {
            dfs(x, node);
            lmin[node] = min(lmin[node], lmin[x]);
            rmax[node] = max(rmax[node], rmax[x]);
        }
        db(node, lmin[node], rmax[node]);
    };
    dfs(0, 0);
    int q;
    sort(all(vecc));
    db(vecc);
    cin >> q;
    for (size_t i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        auto itl = lower_bound(all(vecc), make_pair(l, 0));
        auto itu = lower_bound(all(vecc), make_pair(r + 1, 0));
        if (itl == vecc.end())
            itl--;
        if (itu != vecc.begin())
            itu--;
        assert(itl != vecc.end());
        assert(itu != vecc.end());
        db(l, r);
        db(*itl, *itu);
        int u = itl->second;
        int v = itu->second;

        function<int(int)> lift = [&](int node) -> int {
            for (int i = lca.Log - 1; i >= 0; --i)
            {
                int b = lca.dp[i][node];
                // if v.max < L or R < v.min :
                if ((l <= lmin[b] && rmax[b] <= r) || (rmax[b] < l) || (r < lmin[b]))
                    node = b;
            }
            return node;
        };

        db(u, lift(u));
        db(v, lift(v));

        u = lift(u);
        v = lift(v);

        db(lca.dist(u, v) + 1);
        db(lca.dist(0, lca.lca(u, v)));

        int d = lca.dist(0, lca.lca(u, v)) + lca.dist(u, v) + 1;
        d = d * 2 + 1;
        if ((l <= lmin[u] && rmax[u] <= r) || (rmax[u] < l) || (r < lmin[u]))
            d -= 2;
        if (u != v)
            if ((l <= lmin[v] && rmax[v] <= r) || (rmax[v] < l) || (r < lmin[v]))
                d -= 2;
        cout << d << '\n';
    }
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