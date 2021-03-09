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
    vector<vector<int>> dist(n, vector<int>(n, MOD));
    for (size_t i = 0; i < n; i++)
        dist[i][i] = 0;
    for (size_t i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        dist[u][v] = w;
        dist[v][u] = w;
    }
    for (size_t k = 0; k < n; k++)
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    UnionFind U(n);
    ll res = 1;
    for (size_t i = 0; i < n; i++)
    {
        dist[i][i] = MOD;
        int mini = *min_element(all(dist[i]));
        db(i, mini, dist[i]);
        int cnt = 0;
        for (size_t j = 0; j < n; j++)
            if (dist[i][j] == mini)
            {
                U.unionSet(i, j);
                cnt++;
            }
        if (cnt > 1)
        {
            res *= 2;
        }
    }
    res *= 1LL << (U.numDisjointSets());
    cout << res << '\n';
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
    {
        cout << "Case #" << i << ": ";
        solveCase();
    }
    return 0;
}