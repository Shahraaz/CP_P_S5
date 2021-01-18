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
const int NAX = 2e5 + 5, MOD = 998244353;

// const int _n = 2e5 + 10;
// vector<int> Fact(_n), Inv(_n);
const int kmod = 998244353;

int mul(int a, int b, int mod = kmod)
{
    return (long long)a * b % mod;
}

int add(int a, int b, int mod = kmod)
{
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b, int mod = kmod)
{
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int power(int base, int index, int mod = kmod)
{
    if (index == 0)
        return 1;
    int temp = power(base, index / 2, mod);
    temp = mul(temp, temp, mod);
    if (index & 1)
        temp = mul(temp, base, mod);
    return temp;
}

int mod_inv(int x, int mod = kmod)
{
    return power(x, mod - 2, mod);
}

// void pre()
// {
//     Fact[0] = 1;
//     for (int i = 1; i < _n; ++i)
//         Fact[i] = mul(Fact[i - 1], i);
//     Inv[_n - 1] = mod_inv(Fact[_n - 1]);
//     for (int i = _n - 2; i >= 0; --i)
//         Inv[i] = mul(Inv[i + 1], (1 + i));
// }

// int ncr(int n, int r)
// {
//     if (n < 0 || r < 0 || n - r < 0)
//         return 0;
//     return mul(Fact[n], mul(Inv[r], Inv[n - r]));
// }

// int npr(int n, int r)
// {
//     if (n < 0 || r < 0 || n - r < 0)
//         return 0;
//     return mul(Fact[n], Inv[n - r]);
// }

void solveCase()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> grid(n, vector<char>(m, '.'));
    for (size_t i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        char c;
        cin >> c;
        grid[x][y] = c;
    }

    vector<vector<int>> dp(n, vector<int>(m));
    vector<vector<int>> down(n + 1, vector<int>(m + 1));
    vector<vector<int>> right(n + 1, vector<int>(m + 1));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (grid[i][j] == '.')
                down[i][j] = right[i][j] = 1;

            down[i][j] += down[i + 1][j];
            right[i][j] += right[i][j + 1];
        }
    }

    vector<int> pow3(max(n + 2, m + 2));
    pow3[0] = 1;
    for (size_t i = 1; i < pow3.size(); i++)
        pow3[i] = (3LL * pow3[i - 1]) % kmod;

    dp[0][0] = 1;
    for (size_t i = 0; i < n; i++)
    {
        db(i, grid[i]);
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (i + 1 < n)
            {
                int now = 0;
                if (grid[i][j] == 'X' || grid[i][j] == 'D')
                    now = 1;
                if (grid[i][j] == '.')
                    now = 2;
                now = mul(now, dp[i][j]);
                db(i + 1, j, now, dp[i][j], grid[i][j]);
                dp[i + 1][j] = add(dp[i + 1][j], mul(pow3[right[i][j + 1]], now));
            }
            if (j + 1 < m)
            {
                int now = 0;
                if (grid[i][j] == 'X' || grid[i][j] == 'R')
                    now = 1;
                if (grid[i][j] == '.')
                    now = 2;
                now = mul(now, dp[i][j]);
                db(i, j + 1, now, dp[i][j], grid[i][j]);
                dp[i][j + 1] = add(dp[i][j + 1], mul(pow3[down[i + 1][j]], now));
            }
            db(i, j, dp[i][j]);
        }
    }
    if (grid[n - 1][m - 1] == '.')
        dp[n - 1][m - 1] = mul(dp[n - 1][m - 1], 3);
    cout << dp[n - 1][m - 1] << '\n';
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