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

const int NAX = 1000 + 5, MOD = 1000000007;

struct Solution
{
    Solution() {}
    void solveCase();
};

string grid[NAX];
int w, h;

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

int A(int x, int y)
{
    return 2 * x * (3 * x + 2 * y) + 2 * (x * y);
}

int B(int x, int y)
{
    return 2 * x * (3 * x + 2 * y) + 3 * (x * y);
}

int C(int x, int y)
{
    return (3 * x + 2 * y) + 2 * (x + y) * x;
}

void Solution::solveCase()
{
    cin >> w >> h;
    for (size_t i = 0; i < h; i++)
    {
        cin >> grid[i];
        db(grid[i]);
    }
    UnionFind U(NAX * NAX);
    int a[] = {0, 0, 1, -1};
    int b[] = {1, -1, 0, 0};
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (grid[i][j] == '#')
                for (size_t k = 0; k < 4; k++)
                {
                    int x = i + a[k];
                    int y = j + b[k];
                    if (0 <= x && x < h && 0 <= y && y < w)
                        if (grid[x][y] == '#')
                            U.unionSet(i * w + j, x * w + y);
                }
    vector<int> vis(NAX * NAX);
    vector<pair<int, int>> northWest;
    vector<pair<int, int>> r_d;
    vector<pair<int, int>> x_y;
    vector<vector<int>> vecc;
    vector<int> invalidated(NAX * NAX);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (grid[i][j] == '#' && !vis[U.findSet(i * w + j)])
            {
                vis[U.findSet(i * w + j)] = 1;
                northWest.pb({i, j});
                int x = i, y = j;
                while (y < w && grid[x][y] == '#')
                    ++y;
                --y;
                r_d.pb({y - j + 1, 0});
                x = i, y = j;
                while (x < h && grid[x][y] == '#')
                    ++x;
                --x;
                r_d.back().s = x - i + 1;
                x_y.pb({2 * r_d.back().f - r_d.back().s, r_d.back().f - 2 * (2 * r_d.back().f - r_d.back().s)});
                x = x_y.back().f;
                y = x_y.back().s;
                if (x > 0 && y > 0)
                {
                    int sz = U.sizeOfSet(i * w + j);
                    invalidated[U.findSet(i * w + j)] = 2;
                    if (sz == A(x, y))
                        vecc.pb({(2 * x + 3 * y) * (2 * x + y), 0, (int)northWest.size() - 1});
                    else if (sz == B(x, y))
                        vecc.pb({(2 * x + 3 * y) * (2 * x + y), 1, (int)northWest.size() - 1});
                    else if (sz == C(x, y))
                        vecc.pb({(2 * x + 3 * y) * (2 * x + y), 2, (int)northWest.size() - 1});
                    else
                    {
                        invalidated[U.findSet(i * w + j)] = 1;
                    }
                }
                else
                {
                    invalidated[U.findSet(i * w + j)] = 1;
                }
            }
    for (size_t i = 0; i < northWest.size(); i++)
    {
        db(i, northWest[i], r_d[i], x_y[i]);
    }
    sort(all(vecc));
    vector<int> cnt(3);
    for (size_t i = 0; i < vecc.size(); i++)
    {
        db(i, vecc[i]);
        int X = x_y[vecc[i][2]].f;
        int Y = x_y[vecc[i][2]].s;
        int x = northWest[vecc[i][2]].f;
        int y = northWest[vecc[i][2]].s;
        if(x+(X+))
        if (vecc[i][1] == 0)
        {
        }
        if (vecc[i][1] == 1)
        {
        }
        if (vecc[i][1] == 2)
        {
        }
    }
    cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << '\n';
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
