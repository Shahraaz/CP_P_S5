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

const int SZ = 3;

struct matrix
{
    vector<vector<ll>> grid;
    matrix()
    {
        grid.resize(SZ, vector<ll>(SZ));
    }
    void set(int x, int y, ll v)
    {
        grid[x][y] = v;
    }
};
matrix one;

matrix mul(matrix a, matrix b)
{
    matrix ret;
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            for (size_t k = 0; k < 3; k++)
                ret.grid[i][k] += a.grid[i][j] * b.grid[j][k];
    return ret;
}

void solveCase()
{
    one.set(0, 0, 1);
    one.set(1, 1, 1);
    one.set(2, 2, 1);
    int n;
    cin >> n;
    vector<matrix> points(n);
    for (size_t i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        points[i].set(0, 0, x);
        points[i].set(1, 0, y);
        points[i].set(2, 0, 1);
        db(i, points[i].grid);
    }
    int m;
    cin >> m;
    vector<matrix> cum(m + 1);
    cum[0] = one;
    db(0, cum[0].grid);
    for (size_t i = 1; i <= m; i++)
    {
        int ch, p;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cum[i].set(0, 1, 1);
            cum[i].set(1, 0, -1);
            cum[i].set(2, 2, 1);
            break;
        case 2:
            cum[i].set(0, 1, -1);
            cum[i].set(1, 0, 1);
            cum[i].set(2, 2, 1);
            break;
        case 3:
            cin >> p;
            cum[i].set(0, 0, -1);
            cum[i].set(0, 2, 2 * p);
            cum[i].set(1, 1, 1);
            cum[i].set(2, 2, 1);
            break;
        case 4:
            cin >> p;
            cum[i].set(0, 0, 1);
            cum[i].set(1, 1, -1);
            cum[i].set(1, 2, 2 * p);
            cum[i].set(2, 2, 1);
            break;

        default:
            break;
        }
        cum[i] = mul(cum[i], cum[i - 1]);
        db(i, cum[i].grid);
    }
    int q;
    cin >> q;
    for (size_t i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        --b;
        auto now = mul(cum[a], points[b]);
        cout << now.grid[0][0] << ' ' << now.grid[1][0] << '\n';
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
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}