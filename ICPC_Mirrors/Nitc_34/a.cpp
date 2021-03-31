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
    int n, m;
    cin >> n >> m;
    vector<string> vecc(n);
    vector<vector<int>> dist(n + 1, vector<int>(m, MOD));
    queue<pair<int, int>> Q;
    for (size_t i = 0; i < n; i++)
    {
        cin >> vecc[i];
        for (size_t j = 0; j < m; j++)
            if (vecc[i][j] == 'G')
            {
                dist[i][j] = 0;
                Q.push({i, j});
            }
    }
    vecc.pb(string(m, '.'));
    db(vecc);
    assert(Q.size());
    vector<pair<int, int>> dirs;
    while (Q.size())
    {
        auto top = Q.front();
        Q.pop();
        int x = top.first, y = top.second;
        int dd = dist[x][y];
        db(top, dd, Q.size());
        // left
        if (vecc[x][(y - 1 + m) % m] == '.' && vecc[x][(y - 2 + m) % m] == '.')
            if (dist[x][(y - 2 + m) % m] == MOD)
            {
                dist[x][(y - 2 + m) % m] = 1 + dd;
                Q.push({x, (y - 2 + m) % m});
            }
        // up
        if (x > 0 && vecc[x - 1][y] == '.' && vecc[x - 1][(y - 1 + m) % m] == '.')
            if (dist[x - 1][(y - 1 + m) % m] == MOD)
            {
                dist[x - 1][(y - 1 + m) % m] = dd + 1;
                Q.push({x - 1, (y - 1 + m) % m});
            }
        // down
        if (x + 1 <= n && vecc[x + 1][y] == '.' && vecc[x + 1][(y - 1 + m) % m] == '.')
            if (dist[x + 1][(y - 1 + m) % m] == MOD)
            {
                dist[x + 1][(y - 1 + m) % m] = dd + 1;
                Q.push({x + 1, (y - 1 + m) % m});
            }
        // stay
        if (vecc[x][(y - 1 + m) % m] == '.')
            if (dist[x][(y - 1 + m) % m] == MOD)
            {
                dist[x][(y - 1 + m) % m] = 1 + dd;
                Q.push({x, (y - 1 + m) % m});
            }
        db(Q.size());
    }
    int res = *min_element(all(dist[n]));
    if (res >= MOD)
        res = -1;
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
        solveCase();
    return 0;
}