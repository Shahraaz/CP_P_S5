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

void Solution::solveCase()
{
    int n;
    cin >> n;
    vector<int> adj[n];
    vector<int> elems;
    for (size_t i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (size_t j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            adj[i].pb(x);
            elems.pb(x);
        }
    }
    sort(all(elems));
    vector<int> adj2[elems.size()];
    for (size_t i = 0; i < n; i++)
        for (auto &x : adj[i])
            adj2[lower_bound(all(elems), x) - elems.begin()].pb(i);
    UnionFind U(n);
    vector<pair<pair<int, int>, int>> ret;
    for (size_t i = 0; i < elems.size(); i++)
    {
        for (size_t j = 0; j + 1 < adj2[i].size(); j++)
        {
            if (U.unionSet(adj2[i][j], adj2[i][j + 1]))
                ret.pb({{adj2[i][j], adj2[i][j + 1]}, elems[i]});
        }
    }
    db(ret);
    if (U.numDisjointSets() == 1)
    {
        for (auto &x : ret)
        {
            cout << x.f.f + 1 << ' ' << x.f.s + 1 << ' ' << x.s << '\n';
        }
    }
    else
    {
        cout << "impossible\n";
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
