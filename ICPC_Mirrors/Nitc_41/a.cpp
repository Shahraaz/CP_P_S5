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

const int kmod = 1000000007;

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

// const int _n = 2e5 + 10;
// vector<int> Fact(_n), Inv(_n);

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

const int N = 61;
int dp[2][N][N];
int s[N];

// const int N = 61;
// int dp[N][N][2];

void solveCase()
{
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> s[i];
        --s[i];
    }

    int now = 0, next = 1;
    memset(dp[now], 0, sizeof dp[now]);
    dp[0][s[0]][s[0]] = 2;

    for (size_t i = 1; i < n; i++)
    {
        memset(dp[next], 0, sizeof dp[next]);

        for (size_t l = 0; l < n; l++)
        {
            for (size_t r = l; r < n; r++)
            {
                if (s[i] < l || r < s[i])
                {
                    dp[next][l][r] = dp[now][l][r];
                    continue;
                }
                for (size_t k = l; k <= s[i]; k++)
                    dp[next][l][r] = add(dp[next][l][r], mul(k > l ? dp[now][l][k - 1] : 1, k < r ? dp[now][k + 1][r] : 1));
                for (size_t k = s[i]; k <= r; k++)
                    dp[next][l][r] = add(dp[next][l][r], mul(k > l ? dp[now][l][k - 1] : 1, k < r ? dp[now][k + 1][r] : 1));
            }
        }
        swap(next, now);
    }
    cout << dp[now][0][n - 1] << '\n';
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
        solveCase();
    return 0;
}