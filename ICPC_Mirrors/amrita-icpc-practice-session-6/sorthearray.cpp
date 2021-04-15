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

bool isperfsq[NAX];

void pre()
{
    for (long long i = 1; i * i < NAX; i++)
        isperfsq[i * i] = 1;
}

void solveCase()
{
    int n = 2e5;
    cin >> n;

    vector<int> a(n + 1);
    for (size_t i = 1; i <= n; i++)
        cin >> a[i];

    db(n);
    UnionFind u(n + 1);
    int cnt = 0;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; i * j <= n; j++)
            if (isperfsq[i * j])
            {
                db(i, j, isperfsq[i * j]);
                u.unionSet(i, j);
            }
    }
    vector<deque<int>> poses(n + 1);
    for (size_t i = 1; i <= n; i++)
        poses[u.findSet(i)].pb(a[i]);
    db(poses);
    for (auto &x : poses)
        sort(all(x));
    auto b = a;
    for (size_t i = 1; i <= n; i++)
    {
        b[i] = poses[u.findSet(i)].front();
        poses[u.findSet(i)].pop_front();
    }
    if (is_sorted(b.begin() + 1, b.end()))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int32_t main()
{
    pre();
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}