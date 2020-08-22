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

int a[] = {0, 0, 1, -1};
int b[] = {1, -1, 0, 0};
class Solution
{
public:
    bool containsCycle(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        for (char c = 'a'; c <= 'z'; c++)
        {
            // UnionFind U(n * m);
            vector<vector<pair<int, int>>> prev(n, vector<pair<int, int>>(m, {-1, -1}));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] != c)
                        continue;
                    if (prev[i][j].f >= 0)
                        continue;
                    queue<pair<int, int>> Q;
                    Q.push({i, j});
                    prev[i][j] = {i, j};
                    while (Q.size())
                    {
                        auto top = Q.front();
                        Q.pop();
                        for (size_t k = 0; k < 4; k++)
                        {
                            int x = top.f + a[k];
                            int y = top.s + b[k];
                            if (0 <= x && x < n && 0 <= y && y < m)
                            {
                                if (grid[x][y] != c)
                                    continue;
                                if (prev[x][y].f == -1)
                                {
                                    prev[x][y].f = top.f;
                                    prev[x][y].s = top.s;
                                    // U.unionSet(i * m + j, x * m + j);
                                    Q.push({x, y});
                                }
                                else if (prev[top.f][top.s] == make_pair(x, y))
                                {
                                }
                                else
                                {
                                    // cout << "-----\n";
                                    // cout << i << ' ' << j << '\n';
                                    // cout << x << ' ' << y << '\n';
                                    // cout << prev[x][y].f << ' ' << prev[x][y].s << '\n';
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};

#ifdef LOCAL
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    Solution S;
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