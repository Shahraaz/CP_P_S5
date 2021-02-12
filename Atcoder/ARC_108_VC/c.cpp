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
    vector<vector<pair<int, int>>> adj(n);
    UnionFind U(n);
    for (size_t i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        if (U.unionSet(u, v))
        {
            adj[u].pb({v, c});
            adj[v].pb({u, c});
        }
    }
    if (U.sizeOfSet(0) != n)
    {
        cout << "No\n";
        return;
    }
    vector<int> mexes(n), res(n, -1);
    for (size_t i = 0; i < n; i++)
    {
        set<int> ss;
        for (auto &x : adj[i])
            ss.insert(x.second);
        mexes[i] = 1;
        while (ss.count(mexes[i]))
            mexes[i]++;
    }
    function<void(int, int)> dfs = [&](int node, int par) -> void {
        if (res[node] == -1)
            res[node] = mexes[node];
        for (auto &x : adj[node])
            if (x.first != par)
            {
                if (x.second != res[node])
                    res[x.first] = x.second;
                dfs(x.first, node);
            }
        db(node, par, res[node], mexes[node]);
        db(adj[node]);
    };
    dfs(0, 0);
    for (size_t i = 0; i < n; i++)
        cout << res[i] << '\n';
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