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

class RailwayMaster
{
public:
    int maxProfit(int N, int M, int K, vector<int> a, vector<int> b, vector<int> v)
    {
        UnionFind U(N);
        vector<int> temp(M);
        for (size_t i = 0; i < M; i++)
            temp[i] = i;
        sort(all(temp), [&](int x, int y) {
            return v[x] < v[y];
        });
        ll ret = 0;
        vector<int> ch;
        for (size_t i = 0; i < M; i++)
        {
            int idx = temp[i];
            if (U.unionSet(a[idx], b[idx]))
            {
                // ret += v[idx];
            }
            else
            {
                ch.pb(v[idx]);
                // v.pb(v[idx]);
            }

            if (U.numDisjointSets() == 1)
            {
                int j = v.size() - 1;
                // sort(v.begin() + i + 1, v.end());
                while (j > i && K > 0)
                {
                    ch.pb(v[temp[j]]);
                    // ret += v[temp[j]];
                    // K--;
                    j--;
                }
                break;
            }
        }
        sort(all(ch));
        while (ch.size() && K--)
        {
            ret += ch.back();
            ch.pop_back();
        }

        return ret;
    }
};

#ifndef LOCAL
//<%:testing-code%>
#endif

#ifdef LOCAL
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    // Solution S;
    for (int i = 1; i <= t; ++i)
    {
        ;
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!