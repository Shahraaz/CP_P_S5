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

struct Solution
{
    Solution() {}
    void solveCase();
};

void Solution::solveCase()
{
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> adj(n);
    set<int> incoming;
    for (size_t i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y == t)
            incoming.insert(x);
        else
        {
            adj[y].pb(x);
        }
    }
    vector<set<int>> omk(n);
    function<void(int, int)> dfs = [&](int x, int node) -> void {
        if (omk[x].count(node))
            return;
        if (omk[x].size() >= 2)
            return;
        omk[x].insert(node);
        for (auto &child : adj[x])
            dfs(child, node);
    };
    for (auto &x : incoming)
        dfs(x, x);
    vector<int> ret;
    for (auto &x : incoming)
        if (omk[x].size() == 1)
            ret.pb(x);
    cout << ret.size() << '\n';
    for (auto &x : ret)
    {
        cout << x << '\n';
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
