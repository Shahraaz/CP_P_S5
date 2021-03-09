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
    for (size_t i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    db(adj);
    LeastCommonAncestor lca(adj);
    auto find_common_paths = [&](int s_a, int e_a, int s_b, int e_b) -> pair<int, int> {
        pair<int, int> ret(INT_MAX, INT_MAX);
        if (lca.Level[s_a] < lca.Level[e_a])
            swap(s_a, e_a);
        if (lca.Level[s_b] < lca.Level[e_b])
            swap(s_b, e_b);
        if (lca.Level[e_a] < lca.Level[e_b])
        {
            swap(s_a, s_b);
            swap(e_a, e_b);
        }
        int l = lca.lca(s_a, s_b);
        // s_a is lower than s_b
        if (lca.Level[e_a] > lca.Level[l])
            return ret;
        ret.first = l;
        ret.second = e_a;
        return ret;
    };
    auto merge_path = [&](int s_a, int e_a, int s_b, int e_b) -> pair<int, int> {
        pair<int, int> ret;
        if (s_a == INT_MAX || e_a == INT_MAX)
            return {s_b, e_b};
        if (s_b == INT_MAX || e_b == INT_MAX)
            return {s_a, e_a};
        if (lca.Level[s_a] < lca.Level[e_a])
            swap(s_a, e_a);
        if (lca.Level[s_b] < lca.Level[e_b])
            swap(s_b, e_b);
        assert(e_a == e_b);
        if (e_a == e_b)
            return {s_a, s_b};
        return (lca.dist(s_a, e_a) > lca.dist(s_b, e_b)) ? make_pair(s_a, e_a) : make_pair(s_b, e_b);
    };
    int q;
    cin >> q;
    for (size_t i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        db(i, k);
        int a, b, l;
        cin >> a >> b;
        --a, --b;
        l = lca.lca(a, b);
        bool no = false;
        for (size_t j = 1; j < k; j++)
        {
            int c, d, l2;
            cin >> c >> d;
            --c, --d;
            if (no)
                continue;
            l = lca.lca(a, b);
            l2 = lca.lca(c, d);
            // int l_l2 = lca.lca(l, l2);
            db(a, b, l, c, d, l2);
            auto ll = find_common_paths(a, l, c, l2);
            auto lr = find_common_paths(a, l, d, l2);
            auto rl = find_common_paths(b, l, c, l2);
            auto rr = find_common_paths(b, l, d, l2);
            db(ll, lr, rl, rr);
            if (l == l2)
            {
                // ll and rr

                auto one = merge_path(ll.first, ll.second, rr.first, rr.second);

                // lr and rl

                auto two = merge_path(lr.first, lr.second, rl.first, rl.second);

                if (lca.dist(one.first, one.second) > lca.dist(two.first, two.second))
                {
                    a = one.first;
                    b = one.second;
                }
                else
                {
                    a = two.first;
                    b = two.second;
                }
            }
            else
            {
                int c = -1;
                pair<int, int> fin;

                for (auto x : {ll, rr, lr, rl})
                {
                    if (x.first == INT_MAX || x.second == INT_MAX)
                        continue;
                    db(x, lca.dist(x.first, x.second));
                    db(c, fin);
                    if (lca.dist(x.first, x.second) > c)
                        c = lca.dist(x.first, x.second), fin = x;
                }
                db(c, fin);
                if (c == -1)
                {
                    no = true;
                }
                else
                {
                    a = fin.first;
                    b = fin.second;
                }
            }
        }
        db("res", a, b);
        if (no)
            cout << "0\n";
        else
            cout << lca.dist(a, b) + 1 << '\n';
    }
}

int32_t main()
{
#ifndef LOCAL
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case " << i << ":\n";
        solveCase();
    }
    return 0;
}