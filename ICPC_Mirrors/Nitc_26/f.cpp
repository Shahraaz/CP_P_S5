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
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> poses(k);
    vector<vector<int>> dist(n, vector<int>(n));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            --x;
            poses[x].pb({i, j});
            dist[i][j] = MOD;
            if (x == 0)
                dist[i][j] = 0;
            // dist[x].back() = 0;
        }
    }
    int mini = MOD;
    for (int i = 0; i + 1 < k; i++)
    {
        for (auto &x : poses[i])
        {
            for (auto &y : poses[i + 1])
            {
                dist[y.first][y.second] = min(dist[y.first][y.second], dist[x.first][x.second] + abs(x.first - y.first) + abs(x.second - y.second));
                // if (i + 1 == k - 1)
                //     mini = min(mini, dist[y.first][y.second]);
            }
        }
    }
    for (auto &y : poses[k - 1])
    {
        mini = min(mini, dist[y.first][y.second]);
    }

    if (mini == MOD)
        mini = -1;
    cout << mini << '\n';
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