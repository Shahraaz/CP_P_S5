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

void solveCase()
{
    int R, C;
    cin >> R >> C;
    vector<vector<int>> grid(R, vector<int>(C));
    for (auto &x : grid)
        for (auto &y : x)
            cin >> y;
    ll res = 0, convered = MOD;
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (true)
    {
        db(grid);
        int maxi = -1;
        for (size_t i = 0; i < R; i++)
        {
            for (size_t j = 0; j < C; j++)
            {
                db(i, j, grid[i][j], maxi, grid[i][j] < convered);
                if (grid[i][j] < convered)
                {
                    maxi = max(maxi, grid[i][j]);
                }
            }
        }
        db(maxi, convered);
        if (maxi == -1)
            break;
        bool ok = false;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (grid[i][j] == maxi)
                    for (auto &d : dirs)
                    {
                        int x = i + d.first;
                        int y = j + d.second;
                        if (x >= 0 && x < R && y >= 0 && y < C)
                        {
                            if (grid[x][y] < grid[i][j] - 1)
                            {
                                ok = 1;
                                res += grid[i][j] - 1 - grid[x][y];
                                grid[x][y] = max(grid[x][y], grid[i][j] - 1);
                            }
                        }
                    }
        db(ok, convered, maxi);
        convered = maxi;
    }
    db(grid);
    cout << res << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solveCase();
    }
    return 0;
}