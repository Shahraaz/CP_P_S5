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

vector<char> meow;

// pair<int,int> f number of ) followed by s number of (

pair<int, int> merge_paran(pair<int, int> l, pair<int, int> r)
{
    pair<int, int> ret = {l.first + r.first - min(r.first, l.second), l.second + r.second - min(r.first, l.second)};
    // db(l, r, ret);
    return ret;
}

//Here it is an unweighted tree
//If you want to solve for thath then
//You have to go for Dist(a,b) = Dist(a) + Dist(b) - 2*Dist(lca(a,b))
// where Dist(a) is distance from Root to a;
struct LeastCommonAncestor
{
    vector<int> Level;
    vector<vector<int>> dp;
    vector<vector<pair<int, int>>> params;
    vector<vector<pair<int, int>>> params_2;
    vector<vector<int>> Adj;
    int Log;
    LeastCommonAncestor() {}
    LeastCommonAncestor(vector<vector<int>> &Tree) : Adj(Tree)
    {
        int n = Tree.size();
        Log = ceil(log2(n)) + 1;
        dp.assign(Log, vector<int>(n));
        params.assign(Log, vector<pair<int, int>>(n, {-1, -1}));
        params_2.assign(Log, vector<pair<int, int>>(n, {-1, -1}));
        Level.assign(n, 0);
        dfs(0, 0, 0);
        for (int i = 1; i < Log; ++i)
            for (int j = 0; j < n; ++j)
            {
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
                // if (dp[i - 1][j] != dp[])
                params[i][j] = merge_paran(params[i - 1][j], params[i - 1][dp[i - 1][j]]);
                // // else
                // //     params[i][j] = params[i - 1][j];
                // if (dp[i - 1][j] != j)
                params_2[i][j] = merge_paran(params_2[i - 1][dp[i - 1][j]], params_2[i - 1][j]);
                // else
                //     params_2[i][j] = params_2[i - 1][j];
                // db(i, j, dp[i][j], params[i][j]);
            }
    }
    void dfs(int node, int parent, int level)
    {
        dp[0][node] = parent;
        params_2[0][node] = params[0][node] = {meow[node] == ')', meow[node] == '('};
        // db(node, meow[node], params[0][node]);

        Level[node] = level;
        for (auto child : Adj[node])
            if (child != parent)
                dfs(child, node, level + 1);
    }
    pair<int, pair<int, int>> lca(int a, int b)
    {
        bool ok = false;
        if (Level[a] > Level[b])
            swap(a, b), ok = true;
        int d = Level[b] - Level[a];
        for (int i = 0; i < Log; ++i)
            if (d & (1 << i))
                b = dp[i][b];
        if (a == b)
            return {a, {MOD, MOD}};
        for (int i = Log - 1; i >= 0; --i)
            if (dp[i][a] != dp[i][b])
            {
                a = dp[i][a];
                b = dp[i][b];
            }
        if (ok)
            swap(a, b);
        return {dp[0][a], {a, b}};
    }
    pair<int, int> params_magic(int node, int l)
    {
        if (node == l)
            return params[0][node];

        int d = Level[node] - Level[l];
        // db(node, l, d);
        pair<int, int> ret;
        for (int i = 0; i < Log; ++i)
            if (d & (1 << i))
            {
                ret = merge_paran(ret, params[i][node]);
                // db(i, node, ret, params[i][node]);
                node = dp[i][node];
            }
        ret = merge_paran(ret, params[0][node]);
        // db(node, ret, params[0][node]);
        // db(ret);
        return ret;
    }
    pair<int, int> params_magic_up(int node, int l)
    {
        if (node == l)
            return params_2[0][node];

        int d = Level[node] - Level[l];
        // db(node, l, d);
        pair<int, int> ret;
        for (int i = 0; i < Log; ++i)
            if (d & (1 << i))
            {
                ret = merge_paran(params_2[i][node], ret);
                // db(i, node, ret, params[i][node]);
                node = dp[i][node];
            }
        ret = merge_paran(params_2[0][node], ret);
        // db(node, ret, params[0][node]);
        // db(ret);
        return ret;
    }
    // int dist(int a, int b)
    // {
    //     return Level[a] + Level[b] - 2 * Level[lca(a, b)];
    // }
};

void solveCase()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    for (size_t i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    meow.resize(n);
    for (auto &x : meow)
        cin >> x;
    db(n, meow);

    LeastCommonAncestor lca(adj);

    auto check = [&](int l, int r) -> bool {
        auto lc = lca.lca(l, r);
        db(l, r, lc);
        if (lc.first == l)
        {
            auto now = lca.params_magic_up(r, lc.first);
            db(now);
            return now.first == 0 && now.second == 0;
        }
        else if (lc.first == r)
        {
            auto now = lca.params_magic(l, lc.first);
            db(now);
            return now.first == 0 && now.second == 0;
        }
        else
        {
            auto left = lca.params_magic(l, lc.first);
            assert(lc.second.second != MOD);
            auto right = lca.params_magic_up(r, lc.second.second);
            // swap(right.first, right.second);
            db(left, right);
            left = merge_paran(left, right);
            db(left);
            return left.first == 0 && left.second == 0;
        }
        assert(false);
        return 0;
    };

    // int q;
    // cin >> q;
    for (size_t i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;
        db(l, r, meow[l], meow[r]);
        if (meow[l] == '(' && meow[r] == ')' && check(l, r))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
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