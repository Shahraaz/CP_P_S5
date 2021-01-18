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
const int NAX = 520 + 5, MOD = 1000000007;
using pii = pair<int, int>;

char G[NAX][NAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m;
pii nxt[NAX][NAX][4];
int posToInt[NAX][NAX];

struct Node
{
    pii nxt[4];
    int vis;
    bool isV;
    bool assignV;
    bool computed;
} nodes[NAX * NAX];
int timestamp;

pii findNext(int x, int y, int enter)
{
    if (posToInt[x][y])
        return {posToInt[x][y], enter};
    int out = enter;
    if (x < 1 || x > n || y < 1 || y > m)
        out = enter ^ 1;
    else if (G[x][y] == '/')
        out = 3 - enter;
    else if (G[x][y] == '\\')
        out = enter ^ 2;
    auto &ret = nxt[x][y][out];
    if (!ret.first)
        ret = findNext(x + dx[out], y + dy[out], out);
    return ret;
}

void fill(int p)
{
    if (p == -1)
        return;
    auto &cur = nodes[p];
    if (cur.computed)
        return;
    cur.computed = 1;
    for (auto x : cur.nxt)
        fill(x.first);
}

int dfs(int node, bool isV)
{
    Node &cur = nodes[node];
    if (cur.vis == timestamp)
    {
        if (isV != cur.assignV)
            return -1;
        return 0;
    }
    cur.vis = timestamp;
    cur.assignV = isV;
    int ret = cur.isV ^ isV;
    for (size_t d = 0; d < 4; d++)
    {
        auto &edge = nodes[node].nxt[d];
        bool shouldTurn = (d > 1) ^ isV;
        if (edge.first == -1)
        {
            if (shouldTurn)
                continue;
            return -1;
        }
        int tmp = dfs(edge.first, shouldTurn ^ (edge.second > 1));
        if (tmp == -1)
            return -1;
        ret += tmp;
    }
    return ret;
}

void solveCase()
{
    cin >> n >> m;
    int cnt = 0;
    for (size_t i = 1; i <= n; i++)
    {
        cin >> (G[i] + 1);
        for (size_t j = 1; j <= m; j++)
            if (G[i][j] == 'V' || G[i][j] == 'H')
                posToInt[i][j] = ++cnt;
            else if (G[i][j] == '#')
                posToInt[i][j] = -1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int id = posToInt[i][j];
            if (id > 0)
            {
                nodes[id].isV = G[i][j] == 'V';
                for (int d = 0; d < 4; d++)
                {
                    nodes[id].nxt[d] = findNext(i + dx[d], j + dy[d], d);
                    db(id, d, i, j, nodes[id].nxt[d]);
                }
            }
        }
    int ans = 0;
    for (size_t i = 1; i <= cnt; i++)
    {
        if (nodes[i].computed)
            continue;
        timestamp++;
        int ans1 = dfs(i, 0);
        db(i, 0, ans1);
        timestamp++;
        int ans2 = dfs(i, 1);
        db(i, 1, ans2);
        fill(i);
        if (max(ans1, ans2) == -1)
        {
            cout << -1 << '\n';
            return;
        }
        if (ans1 == -1)
            ans1 = ans2;
        if (ans2 == -1)
            ans2 = ans1;
        ans += min(ans1, ans2);
    }

    cout << ans << '\n';
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