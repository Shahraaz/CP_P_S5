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
const int NAX = 100 + 2, MOD = 1000000007;

vector<int> adj[NAX];
bitset<NAX> equations[NAX];
int ans[NAX];

void solveCase()
{
    int n, m;
    cin >> n >> m;
    for (size_t i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        equations[u].set(v);
        equations[v].set(u);
    }
    for (size_t i = 0; i < n; i++)
        if (equations[i].count() & 1)
            equations[i].set(i);
        else
            equations[i].set(n);
    int col = 0, row = 0;
    vector<int> where(n, -1);
    for (; col < n && row < n; col++)
    {
        for (int i = row; i < n; i++)
            if (equations[i][col])
            {
                swap(equations[row], equations[i]);
                break;
            }
#ifdef LOCAL
        db(row, col);
        for (size_t i = 0; i < n; i++)
        {
            db(i, equations[i]);
        }
#endif
        if (!equations[row][col])
            continue;
        where[col] = row;
        for (size_t i = 0; i < n; i++)
            if (i != row && equations[i][col])
                equations[i] ^= equations[row];
        ++row;
    }
    for (size_t i = 0; i < n; i++)
    {
        if (where[i] != -1)
            ans[i] = equations[where[i]][n] / equations[where[i]][i];
        db(i, ans[i]);
    }
    for (size_t i = 0; i < n; i++)
    {
        int sum = 0;
        for (size_t j = 0; j < n; j++)
            sum += equations[i][j] * ans[j];
        db(i, equations[i]);
        db(sum);
        if (sum != equations[i][n])
        {
            cout << "N\n";
            return;
        }
    }
    cout << "Y\n";
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