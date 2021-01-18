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

class UnionFind
{ // OOP style
private:
    vector<int> p, rank, setSize; // remember: vi is vector<int>
    int numSets;

public:
    UnionFind(int N)
    {
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    bool unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            numSets--;
            int x = findSet(i), y = findSet(j);
            // rank is used to keep the tree short
            if (rank[x] > rank[y])
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
            return true;
        }
        return false;
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

void solveCase()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    vector<int> side(m, -1);
    vector<int> godown(m, 0);
    /*
        0: f -> s
        1: s -> f
    */
    vector<vector<pair<int, int>>> adj(n);
    vector<vector<pair<int, int>>> adj2(n);
    for (size_t i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        edges.pb({x, y});
        adj[x].pb({y, i});
        adj[y].pb({x, i});
    }
    vector<int> cnt(n), vis(n);
    for (size_t i = 0; i < n; i++)
        cin >> cnt[i];
    UnionFind U(n);
    for (size_t i = 0; i < m; i++)
    {
        if (cnt[edges[i].first] < cnt[edges[i].second])
            side[i] = 1;
        else if (cnt[edges[i].first] == cnt[edges[i].second])
        {
            adj2[edges[i].first].pb({edges[i].second, i});
            adj2[edges[i].second].pb({edges[i].first, i});
            U.unionSet(edges[i].first, edges[i].second);
        }
        else
            side[i] = 0;
    }
    db("one");
    vector<int> level(n);
    auto dir = [&](int idx, int x) {
        db(idx, x);
        db(edges[idx]);
        if (edges[idx].first == x)
            side[idx] = 0;
        else
            side[idx] = 1;
    };
    for (size_t i = 0; i < n; i++)
        if (i == U.findSet(i))
        {
            db(i);
            function<void(int, int)> dfs = [&](int node, int par) -> void {
                db(node, par);
                vis[node] = true;
                if (node != par)
                    level[node] = level[par] + 1;
                for (auto &x : adj2[node])
                    if (!vis[x.first])
                    {
                        dfs(x.first, node);
                        godown[x.second] = 1;
                    }
            };
            level[i] = 0;
            dfs(i, i);
        }
    for (size_t i = 0; i < m; i++)
    {
        if (side[i] == -1)
        {
            if (godown[i])
            {
                if (level[edges[i].first] < level[edges[i].second])
                    side[i] = 0;
                else
                    side[i] = 1;
            }
            else
            {
                if (level[edges[i].first] < level[edges[i].second])
                    side[i] = 1;
                else
                    side[i] = 0;
            }
        }
        if (side[i])
            cout << "<-\n";
        else
            cout << "->\n";
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