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

void NO()
{
    cout << "No\n";
    exit(0);
}

void solveCase()
{
    int n, f;
    cin >> n >> f;
    vector<vector<int>> adj(n), adj2(n);
    for (size_t i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    LeastCommonAncestor lca(adj);
    vector<pair<int, int>> laminars(f);
    vector<vector<pair<int, int>>> aux(n);
    vector<int> dx(n), vis(n), inQ(f);
    for (size_t i = 0; i < f; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;

        if (u == v)
            continue;

        laminars[i] = {u, v};
        aux[u].pb({lca.dist(u, v), i});
        aux[v].pb({lca.dist(u, v), i});

        dx[u]++;
        dx[v]++;
        dx[lca.lca(u, v)] -= 2;
    }
    db(laminars);
    function<void(int, int)> dfs = [&](int node, int par) -> void {
        for (auto &x : adj[node])
            if (x != par)
            {
                dfs(x, node);
                dx[node] += dx[x];
            }
        db(node, par, dx[node]);
        if (node != 0 && dx[node])
        {
            adj2[node].pb(par);
            adj2[par].pb(node);
        }
    };
    dfs(0, 0);
    for (size_t i = 0; i < n; i++)
    {
        db(i, adj2[i]);
        db(i, aux[i]);
        if (adj2[i].size() > 2)
            NO();
    }
    for (size_t i = 0; i < n; i++)
    {
        db(i, vis[i], adj2[i].size() == 1);
        if (vis[i] || adj2[i].size() != 1)
            continue;
        queue<int> Q;
        db("bfs", i);
        Q.push(i);
        vis[i] = 1;
        // vector<int> order;
        stack<int> st;
        while (Q.size())
        {
            auto top = Q.front();
            Q.pop();
            // order.pb(top);
            sort(all(aux[top]));
            int sgn = -1;
            for (auto &x : aux[top])
                if (sgn == -1)
                    sgn = inQ[x.second];
                else if (sgn != inQ[x.second])
                    NO();
            db(top, aux[top], sgn);
            if (sgn == 0)
            {
                reverse(all(aux[top]));
                for (auto &x : aux[top])
                {
                    inQ[x.second] = 1;
                    st.push(x.second);
                }
            }
            else if (sgn == 1)
            {
                for (auto &x : aux[top])
                {
                    if (st.empty() || st.top() != x.second)
                        NO();
                    st.pop();
                }
            }
            for (auto &x : adj2[top])
                if (!vis[x])
                {
                    vis[x] = 1;
                    Q.push(x);
                }
        }
    }
    for (size_t i = 0; i < n; i++)
        if (!vis[i] && adj2[i].size())
            NO();
    cout << "Yes\n";
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