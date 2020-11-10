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

const int NAX = 50 + 5, MOD = 998244353;

int mat[NAX][NAX];
// int swapr[NAX];
vector<int> swapr(NAX);
vector<int> swapc(NAX);
// int swapc[NAX];

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
    int n, k;
    cin >> n >> k;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            cin >> mat[i][j];
    int res1 = 0;
    UnionFind r(n + 1), c(n + 1);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t i2 = i + 1; i2 < n; i2++)
        {
            if (i == i2)
                continue;
            bool ok = true;
            for (size_t j = 0; j < n; j++)
                ok = ok && (mat[i][j] + mat[i2][j] <= k);
            swapr[i] += ok;
            if (ok)
            {
                r.unionSet(i, i2);
                db(i, i2);
            }
        }
        // swapr[i]++;
        // cout << i << ' ' << swapr[i] << '\n';
    }
    // db(swapr);
    // cout << '\n';
    for (size_t j = 0; j < n; j++)
    {
        for (size_t j2 = j + 1; j2 < n; j2++)
        {
            if (j == j2)
                continue;
            bool ok = true;
            for (size_t i = 0; i < n; i++)
                ok = ok && (mat[i][j] + mat[i][j2] <= k);
            swapc[j] += ok;
            if (ok)
            {
                c.unionSet(j, j2);
                db(j, j2);
            }
        }
        // swapc[j]++;
        // cout << j << ' ' << swapc[j] << '\n';
    } // db(swapc);
    // for (size_t i = 0; i < n; i++)
    //     for (size_t j = 0; j < n; j++)
    //         db(swapr[i] * swapc[j]);
    int res = 1;
    vector<int> fact(n + 1);
    fact[0] = 1;
    for (size_t j = 1; j <= n; j++)
        fact[j] = (j * 1LL * fact[j - 1]) % MOD;
    for (size_t j = 0; j < n; j++)
    {
        if (r.findSet(j) == j)
            res = (res * 1LL * fact[r.sizeOfSet(j)]) % MOD;
        if (c.findSet(j) == j)
            res = (res * 1LL * fact[c.sizeOfSet(j)]) % MOD;
    }
    cout << res << '\n';
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
    {
        solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
