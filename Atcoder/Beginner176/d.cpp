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

void Solution::solveCase()
{
    int h, w;
    cin >> h >> w;
    pair<int, int> src, dest;
    cin >> src.f >> src.s;
    cin >> dest.f >> dest.s;
    src.f--;
    src.s--;
    dest.f--;
    dest.s--;
    vector<string> matrix(h);
    for (auto &x : matrix)
        cin >> x;
    using elem = pair<int, pair<int, int>>;
    vector<vector<int>> dist(h, vector<int>(w, MOD));
    vector<vector<int>> vis(h, vector<int>(w, 0));
    using type = pair<int, pair<int, int>>;
    priority_queue<type, vector<type>, greater<type>> Q;
    // queue<pair<int, int>> Q;
    Q.push({0, {src.f, src.s}});
    dist[src.f][src.s] = 0;
    // vis[src.f][src.s] = 1;
    int a[] = {0, 0, 1, -1};
    int b[] = {1, -1, 0, 0};
    while (Q.size())
    {
        auto top = Q.top();
        Q.pop();
        // db(top, dist[top.f][top.s]);
        if (vis[top.s.f][top.s.s])
            continue;
        vis[top.s.f][top.s.s] = true;
        for (size_t i = 0; i < 4; i++)
        {
            int x = top.s.f + a[i];
            int y = top.s.s + b[i];
            // db(x, y);
            if (0 <= x && x < h && 0 <= y && y < w)
            {
                if (!vis[x][y] && matrix[x][y] == '.')
                {
                    if (top.f < dist[x][y])
                    {
                        dist[x][y] = top.f;
                        Q.push({dist[x][y], {x, y}});
                    }
                }
            }
        }

        for (int i = -2; i <= 2; i++)
            for (int j = -2; j <= 2; j++)
            {
                int x = top.s.f + i;
                int y = top.s.s + j;
                // db(x, y);
                if (0 <= x && x < h && 0 <= y && y < w)
                {
                    if (!vis[x][y] && matrix[x][y] == '.')
                    {
                        if (top.f + 1 < dist[x][y])
                        {
                            dist[x][y] = 1 + top.f;
                            Q.push({dist[x][y], {x, y}});
                        }
                    }
                }
            }
    }
    if (dist[dest.f][dest.s] == MOD)
        cout << -1 << '\n';
    else
    {
        cout << dist[dest.f][dest.s] << '\n';
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
