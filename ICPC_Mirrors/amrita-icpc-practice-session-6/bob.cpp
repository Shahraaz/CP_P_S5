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

void solveCase()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &x : grid)
        cin >> x;
    int p, q;
    cin >> p >> q;
    p = mul(p, mod_inv(q));
    int inv_p = sub(1, p);
    vector<int> res;
    db(grid);
    db(p, inv_p);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != '1')
                continue;
            vector<vector<int>> prob(n, vector<int>(m));
            prob[i][j] = 1;
            int a = 1;
            int b = 0;
            for (int k = i; k < n; k++)
            {
                for (int l = j; l < m; l++)
                {
                    auto d = [&]() -> int {
                        return k - i + l - j;
                    };
                    auto temp = mul(d(), prob[k][l]);
                    db(k, l, grid[k][l], prob[k][l], d(), temp);
                    if (grid[k][l] == '2')
                    {
                        // res = dist(k,l) * prob[k][l]
                        // db("a");
                        b = add(b, temp);
                    }
                    else if (grid[k][l] == 'x')
                    {
                        // res += (d()+res) * prob[k][l]
                        // res - res * (dist(k,l) * prob[k][l]) = dist(k,l) * prob[k][l]
                        // db("b");
                        // auto temp = mul(d(), prob[k][l]);
                        a = sub(a, prob[k][l]);
                        b = add(b, temp);
                    }
                    else
                    {
                        prob[k][l + 1] = add(prob[k][l + 1], mul(p, prob[k][l]));
                        prob[k + 1][l] = add(prob[k + 1][l], mul(inv_p, prob[k][l]));
                        // db("c", prob[k][l + 1], prob[k + 1][l]);
                    }
                }
            }
            auto p = mul(b, mod_inv(a));
            res.pb(p);
            // db(i, j, a, b, mul(b, mod_inv(a)));
        }
    }
    db("test end");
    int ret = 0;
    if (res.size())
    {
        for (auto &x : res)
            ret = add(ret, x);
        ret = mul(ret, mod_inv(res.size()));
    }
    cout << ret << '\n';
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