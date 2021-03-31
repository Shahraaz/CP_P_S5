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
const int NAX = 1000 + 5, MOD = 1000000007;

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

int n, m, q;
int cnt[NAX][NAX], vis[NAX][NAX];

void addstroke(pair<int, int> s, pair<int, int> e)
{
    if (s.first == e.first)
    {
        if (e.second < s.second)
            swap(e, s);
        while (s.second <= e.second)
        {
            cnt[s.first][s.second]++;
            s.second++;
        }
    }
    else if (s.second == e.second)
    {
        if (e.first < s.first)
            swap(e, s);
        while (s.first <= e.first)
        {
            cnt[s.first][s.second]++;
            s.first++;
        }
    }
}

UnionFind white(NAX *NAX), white_dsu(NAX *NAX);
int prevwhite, noofcomponents;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isvalid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void cnt_components()
{
    prevwhite = -1;
    noofcomponents = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (cnt[i][j] == 0)
            {
                if (vis[i][j])
                    continue;
                noofcomponents++;
                if (prevwhite == -1)
                    prevwhite = i * m + j;
                else
                    white.unionSet(i * m + j, prevwhite);

                queue<pair<int, int>> Q;
                Q.push({i, j});
                vis[i][j] = 1;

                while (Q.size())
                {
                    auto top = Q.front();
                    Q.pop();
                    white_dsu.unionSet(top.first * m + top.second, i * m + j);

                    for (int k = 0; k < 4; ++k)
                    {
                        int x = top.first + dx[k];
                        int y = top.second + dy[k];
                        if (isvalid(x, y) && cnt[x][y] == 0 && !vis[x][y])
                        {
                            Q.push({x, y});
                            vis[x][y] = 1;
                            if (prevwhite == -1)
                                prevwhite = x * m + y;
                            else
                                white.unionSet(x * m + y, prevwhite);
                        }
                    }
                }
            }
        }
    }
}

void turn_white(pair<int, int> node)
{
    set<int> neighbours;
    for (int k = 0; k < 4; ++k)
    {
        int x = node.first + dx[k];
        int y = node.second + dy[k];
        if (isvalid(x, y) && cnt[x][y] == 0)
        {
            neighbours.insert(white_dsu.findSet(x * m + y));
        }
    }
    db(node, neighbours, noofcomponents);
    if (neighbours.size() == 0)
    {
        noofcomponents++;
        if (prevwhite == -1)
            prevwhite = node.first * m + node.second;
        else
            white.unionSet(node.first * m + node.second, prevwhite);
    }
    else
        noofcomponents -= neighbours.size() - 1;
    for (int k = 0; k < 4; ++k)
    {
        int x = node.first + dx[k];
        int y = node.second + dy[k];
        if (isvalid(x, y) && cnt[x][y] == 0)
            white_dsu.unionSet(x * m + y, node.first * m + node.second);
    }
}

void undostroke(pair<int, int> s, pair<int, int> e)
{
    if (s.first == e.first)
    {
        if (e.second < s.second)
            swap(e, s);
        while (s.second <= e.second)
        {
            cnt[s.first][s.second]--;
            if (cnt[s.first][s.second] == 0)
                turn_white(s);
            s.second++;
        }
    }
    else if (s.second == e.second)
    {
        if (e.first < s.first)
            swap(e, s);
        while (s.first <= e.first)
        {
            cnt[s.first][s.second]--;
            if (cnt[s.first][s.second] == 0)
                turn_white(s);
            s.first++;
        }
    }
}

void solveCase()
{
    cin >> n >> m >> q;
    vector<pair<int, int>> s(q), e(q);
    for (int i = 0; i < q; ++i)
    {
        cin >> s[i].first >> s[i].second;
        cin >> e[i].first >> e[i].second;
        s[i].first--;
        s[i].second--;
        e[i].first--;
        e[i].second--;
        addstroke(s[i], e[i]);
    }
    vector<int> res(q);
    cnt_components();
    for (int i = q - 1; i >= 0; i--)
    {
        res[i] = noofcomponents;
        undostroke(s[i], e[i]);
    }
    for (int i = 0; i < q; ++i)
        cout << res[i] << ' ';
    cout << '\n';
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