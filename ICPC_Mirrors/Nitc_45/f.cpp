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

int kmod = 1000000007;

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

int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// int mod_inv(int a, int mod = kmod)
// {
//     int x, y;
//     int g = gcd(a, mod, x, y);
//     if (g != 1)
//     {
//         // cout << "No solution!";
//         assert(false);
//         return
//     }
//     else
//     {
//         x = (x % m + m) % m;
//         cout << x << endl;
//     }

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

int ncr[4004][4004];

void solveCase()
{
    int N = 2021, R = 1, M = MOD;
    cin >> R >> N >> M;
    // M = MOD;
    kmod = M;
    --R;

    if (M == 1)
    {
        cout << 0 << '\n';
        return;
    }
    for (size_t i = 0; i < 4004; i++)
    {
        ncr[i][0] = 1;
        if (i > 0)
            for (size_t j = 1; j < 4004; j++)
                ncr[i][j] = add(ncr[i - 1][j], ncr[i][j - 1]);
    }
    if (R == (N - 1))
    {
        if (N == 1)
            cout << 1 % M << '\n';
        else
            cout << 0 % M << '\n';
        return;
    }
    // vector<vector<int>> ways(N + 1, vector<int>(N + 1));
    vector<int> one_ways(N + 1, 0);
    int total_free = 2, alr_picked = 0;
    one_ways[0] = 1;
    for (int i = N - 2; i >= 0; i--)
    {
        vector<int> one_ways_n(N + 1, 0);
        for (int j = 0; j <= N; j++)
        {
            if (one_ways[j])
            {
                int two = total_free - j - alr_picked;
                db(total_free, j, alr_picked, two);
                if (two % 2 == 0 && two >= 0)
                {
                    two /= 2;
                    if (j + 1 <= N && two)
                    {
                        one_ways_n[j + 1] = add(one_ways_n[j + 1], mul(two, one_ways[j]));
                        db(ncr[j + two][two], one_ways[j], mul(ncr[j + two][two], one_ways[j]));
                    }
                    if (j - 1 >= 0 && j)
                    {
                        one_ways_n[j - 1] = add(one_ways_n[j - 1], mul(j, one_ways[j]));
                        db(ncr[j + two][j], one_ways[j], mul(ncr[j + two][j], one_ways[j]));
                    }
                }
            }
        }
        alr_picked++;
        if (i == R)
        {
            one_ways = one_ways_n;
            db(i, one_ways);
            // db(i);
            continue;
        }
        total_free += 2;
        one_ways = one_ways_n;
        db(i, one_ways);
    }
    int res = 0;
    for (size_t i = 0; i <= N; i++)
        res = add(res, one_ways[i]);
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