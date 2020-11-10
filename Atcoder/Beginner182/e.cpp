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

const int NAX = 1500 + 5, MOD = 1000000007;

int H, W;
int vis[NAX][NAX][4];
int blocked[NAX][NAX];
// int vis[NAX][NAX];

void solveCase()
{
    cin >> H >> W;
    int N;
    cin >> N;
    int M;
    cin >> M;
    queue<pair<pair<int, int>, int>> Q;
    for (size_t i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        for (size_t i = 0; i < 4; i++)
        {
            vis[x][y][i] = 1;
            Q.push({{x, y}, i});
        }
    }
    for (size_t i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        blocked[x][y] = 1;
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (Q.size())
    {
        auto top = Q.front();
        Q.pop();
        int next_x = top.f.f + dx[top.s];
        int next_y = top.f.s + dy[top.s];
        if (0 <= next_x && next_x < H)
            if (0 <= next_y && next_y < W)
                if (!blocked[next_x][next_y])
                    if (!vis[next_x][next_y][top.s])
                    {
                        vis[next_x][next_y][top.s] = 1;
                        Q.push({{next_x, next_y}, top.s});
                    }
    }
    int res = 0;
    for (size_t i = 0; i < H; i++)
    {
        for (size_t j = 0; j < W; j++)
        {
            for (size_t k = 0; k < 4; k++)
            {
                if (vis[i][j][k])
                {
                    res++;
                    break;
                }
            }
        }
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
