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
    vector<vector<int>> gridN(R, vector<int>(C));
    vector<vector<int>> gridE(R, vector<int>(C));
    vector<vector<int>> gridW(R, vector<int>(C));
    vector<vector<int>> gridS(R, vector<int>(C));
    for (auto &x : grid)
        for (auto &y : x)
            cin >> y;
    for (size_t i = 0; i < R; i++)
        for (size_t j = 0; j < C; j++)
            if (grid[i][j])
            {
                gridN[i][j] = grid[i][j];
                gridW[i][j] = grid[i][j];
                if (i > 0)
                    gridN[i][j] += gridN[i - 1][j];
                if (j > 0)
                    gridW[i][j] += gridW[i][j - 1];
            }
    for (int i = R - 1; i >= 0; i--)
        for (int j = C - 1; j >= 0; j--)
            if (grid[i][j])
            {
                gridE[i][j] = grid[i][j];
                gridS[i][j] = grid[i][j];
                if (i + 1 < R)
                    gridS[i][j] += gridS[i + 1][j];
                if (j + 1 < C)
                    gridE[i][j] += gridE[i][j + 1];
            }
    ll res = 0;
    for (size_t i = 0; i < R; i++)
    {
        for (size_t j = 0; j < C; j++)
        {
            db(i, j, res, gridN[i][j], gridS[i][j], gridE[i][j], gridW[i][j]);
            int cnt = gridN[i][j];
            if (cnt >= 4)
            {
                res += max(0, min(cnt / 2 - 1, gridW[i][j] - 1));
                res += max(0, min(cnt / 2 - 1, gridE[i][j] - 1));
            }
            db(res);
            cnt = gridS[i][j];
            if (cnt >= 4)
            {
                res += max(0, min(cnt / 2 - 1, gridW[i][j] - 1));
                res += max(0, min(cnt / 2 - 1, gridE[i][j] - 1));
            }
            db(res);

            cnt = gridE[i][j];
            if (cnt >= 4)
            {
                res += max(0, min(cnt / 2 - 1, gridN[i][j] - 1));
                res += max(0, min(cnt / 2 - 1, gridS[i][j] - 1));
            }
            db(res);

            cnt = gridW[i][j];
            if (cnt >= 4)
            {
                res += max(0, min(cnt / 2 - 1, gridN[i][j] - 1));
                res += max(0, min(cnt / 2 - 1, gridS[i][j] - 1));
            }
            db(res);
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
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solveCase();
    }
    return 0;
}