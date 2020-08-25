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

//Add Dummy Comment
//https://github.com/Shahraaz/CP/blob/master/SCC.cpp

typedef vector<int> _vi;
typedef vector<_vi> _graph;
// int getConj(int x)
// {
//     return x ^ 1;
// }
// auto add = [&](int a, int b) {
//     adj[a].pb(b);
//     adj[getConj(b)].pb(getConj(a));
// };
// auto addXor = [&](int a, int b) {
//     add(a, getConj(b));
//     add(getConj(a), b);
// };
// auto addOr = [&](int a, int b) {
//     add(getConj(a), b);
// };

// auto addand = [&](int u, int v) {
//     add(getConj(u), u);
//     add(getConj(v), v);
// };

class SCC
{
public:
    int _n, _m, CompC;
    _graph G, RevG, SccG;
    stack<int> St;
    _vi Vis, Comp;
    SCC()
    {
    }
    void fillOrder(int i)
    {
        Vis[i] = true;
        for (int x : G[i])
            if (!Vis[x])
                fillOrder(x);
        St.push(i);
    }
    void Dfs(int u, int c)
    {
        Vis[u] = true;
        Comp[u] = c;
        for (int x : RevG[u])
            if (!Vis[x])
                Dfs(x, c);
    }
    void MakeScc()
    {
        for (int i = 0; i < _n; ++i)
            if (!Vis[i])
                fillOrder(i);
        fill(Vis.begin(), Vis.end(), false);
        CompC = 0;
        while (!St.empty())
        {
            auto v = St.top();
            St.pop();
            if (!Vis[v])
                Dfs(v, CompC++);
        }
        SccG.resize(CompC);
        for (int i = 0; i < _n; ++i)
            for (auto y : G[i])
                if (Comp[i] != Comp[y])
                    SccG[Comp[i]].pb(Comp[y]);
        for (int i = 0; i < CompC; ++i)
        {
            sort(SccG[i].begin(), SccG[i].end());
            SccG[i].erase(unique(SccG[i].begin(), SccG[i].end()), SccG[i].end());
        }
    }
    SCC(_graph _G)
    {
        G = _G;
        _n = G.size();
        _m = 0;
        Vis.resize(_n);
        Comp.resize(_n);
        RevG.resize(_n);
        for (int i = 0; i < _n; ++i)
            for (auto y : G[i])
            {
                _m++;
                RevG[y].pb(i);
            }
        MakeScc();
    }
    pair<_graph, _vi> GetScc()
    {
        return {SccG, Comp};
    }
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
        if (x == t || y == t)
            continue;
        adj[x].pb(y);
    }
    for (auto &x : adj)
    {
        db(x);
    }
    SCC s(adj);
    auto ret = s.GetScc();
    db(ret.s);
    vector<int> inmates[n];
    vector<int> indegree(n);
    for (size_t i = 0; i < n; i++)
        inmates[ret.s[i]].pb(i);
    for (size_t i = 0; i < n; i++)
        db(i, inmates[i]);
    vector<int> rev[n];
    int ctr = 0;
    for (auto &x : ret.f)
    {
        db(ctr, x);
        for (auto &y : x)
        {
            indegree[ctr]++;
            rev[y].pb(ctr);
        }
        ++ctr;
    }
    queue<pair<int, int>> Q;
    for (size_t i = 0; i < s.CompC; i++)
        if (indegree[i] == 0)
            Q.push({i, 0});
    set<int> res;
    db(incoming);
    while (Q.size())
    {
        auto top = Q.front();
        Q.pop();
        vector<int> cnt;
        db(top);
        db(inmates[top.f]);
        for (auto &x : inmates[top.f])
            if (incoming.find(x) != incoming.end())
                cnt.pb(x);
        db(cnt);
        if (top.s == 0 && cnt.size() == 1)
            res.insert(cnt[0]);
        top.s = top.s || (cnt.size() >= 1);
        for (auto &x : rev[top.f])
        {
            indegree[x]--;
            if (indegree[x] == 0)
                Q.push({x, top.s});
        }
    }
    cout << res.size() << '\n';
    for (auto &x : res)
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
