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

//Add Dummy Comment
//https://github.com/Shahraaz/CP/blob/master/SCC.cpp

typedef vector<int> _vi;
typedef vector<_vi> _graph;
int getConj(int x)
{
    return x ^ 1;
}

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

void solveCase(int n, int m, int x, int y)
{
    vector<vector<int>> adj(2 * n);
    auto add = [&](int a, int b) {
        adj[a].pb(b);
        adj[getConj(b)].pb(getConj(a));
    };
    auto addXor = [&](int a, int b) {
        add(a, getConj(b));
        add(getConj(a), b);
    };
    auto addOr = [&](int a, int b) {
        add(getConj(a), b);
    };

    auto addand = [&](int u, int v) {
        add(getConj(u), u);
        add(getConj(v), v);
    };
    vector<int> used(n);
    for (size_t i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        used[x] = used[y] = 1;
        addXor(2 * x, 2 * y);
    }
    for (size_t i = 0; i < x; i++)
    {
        int p;
        cin >> p;
        --p;
        used[p] = 1;
        addOr(2 * p, 2 * p);
    }
    for (size_t i = 0; i < y; i++)
    {
        int p;
        cin >> p;
        --p;
        used[p] = 1;
        addOr(2 * p + 1, 2 * p + 1);
    }
    for (size_t i = 0; i < n; i++)
        if (!used[i])
        {
            cout << "NO\n";
            return;
        }
    SCC scc(adj);
    auto assignment = scc.GetScc().second;
    for (size_t i = 0; i < 2 * n; i += 2)
    {
        if (assignment[i] == assignment[i + 1])
        {
            cout << "NO\n";
            return;
        }
        db(i, assignment[i] > assignment[i + 1]);
    }
    cout << "YES\n";
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    int n, m, x, y;
    while (cin >> n >> m >> x >> y)
        solveCase(n, m, x, y);
    return 0;
}