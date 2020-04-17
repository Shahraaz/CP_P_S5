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

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int n;
        cin >> n;
        set<pair<int, int>> s;
        UnionFind U(n);
        for (size_t i = 0; i < n; i++)
            s.insert({1, i});
        ll res = 0;
        int coinsRem = 1e4;
        auto ask = [&](int id) -> pair<pair<int, int>, int> {
            id = U.findSet(id);
            coinsRem -= U.sizeOfSet(id);
            // assert(coinsRem >= 0);
            cout << 1 << ' ' << U.sizeOfSet(id) << ' ' << n - U.sizeOfSet(id) << endl;
            for (size_t i = 0; i < n; i++)
                if (U.findSet(i) == id)
                    cout << i + 1 << ' ';
            cout << endl;
            for (size_t i = 0; i < n; i++)
                if (U.findSet(i) != id)
                    cout << i + 1 << ' ';
            cout << endl;
            pair<pair<int, int>, int> ret;
            cin >> ret.f.f >> ret.f.s >> ret.s;
            ret.f.f--;
            ret.f.s--;
            return ret;
        };
        while (U.numDisjointSets() > 1)
        {
            db(s);
            auto it = *s.begin();
            int node = it.s;
            auto temp = ask(node);
            db(temp);
            res += temp.s;
            s.erase({U.sizeOfSet(temp.f.f), U.findSet(temp.f.f)});
            s.erase({U.sizeOfSet(temp.f.s), U.findSet(temp.f.s)});
            U.unionSet(temp.f.f, temp.f.s);
            s.insert({U.sizeOfSet(temp.f.f), U.findSet(temp.f.f)});
        }
        cout << 2 << ' ' << res << endl;
    }
};

int32_t main()
{
#ifndef LOCAL
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
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
