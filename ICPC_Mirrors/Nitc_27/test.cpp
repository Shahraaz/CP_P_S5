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

#define int ll

const int p1 = 29, p2 = 34483;
const int p = p1 * p2;

// int ncr_p1[NAX][NAX];
// int ncr_p2[NAX][NAX];
// int ncr_p[NAX][NAX];
int fact_p1[NAX];
int fact_p2[NAX];

int add(int a, int b, int m)
{
    a += b;
    if (a >= m)
        a -= m;
    return a;
}

int sub(int a, int b, int p)
{
    a -= b;
    if (a < 0)
        a += p;
    return a;
}

int mul(int a, int b, int p)
{
    return (a * 1LL * b) % p;
}

vector<int> split_and_send(int x, int p)
{
    // db(x, p);
    vector<int> ret;
    while (x)
    {
        ret.pb(x % p);
        x /= p;
    }
    if (ret.empty())
        ret.pb(0);
    // db(ret);
    return ret;
}

int power(int base, int index, int mod)
{
    if (index == 0)
        return 1;
    int temp = power(base, index / 2, mod);
    temp = mul(temp, temp, mod);
    if (index & 1)
        temp = mul(temp, base, mod);
    return temp;
}

int mod_inv(int x, int p)
{
    assert(__gcd(x, p) <= 1);
    return power(x, p - 2, p);
}

int ncr(int a, int b, int p)
{
    if (b > a)
        return 0;
    if (p == p1)
        return mul(mul(fact_p1[a], mod_inv(fact_p1[b], p1), p1), mod_inv(fact_p1[a - b], p1), p1);
    return mul(mul(fact_p2[a], mod_inv(fact_p2[b], p2), p2), mod_inv(fact_p2[a - b], p2), p2);
}

int calc_ncr(int n, int r, int p_now)
{
    if (r > n || n < 0)
        return 0;
    auto split_n = split_and_send(n, p_now);
    auto split_r = split_and_send(r, p_now);
    while (split_n.size() != split_r.size())
    {
        if (split_n.size() < split_r.size())
            split_n.pb(0);
        else
            split_r.pb(0);
    }
    db(n, r, p_now);
    db(split_n, split_r);
    int ret = 1;
    for (size_t i = 0; i < split_n.size(); i++)
        ret = mul(ret, ncr(split_n[i], split_r[i], p_now), p_now);
    db(n, r, p_now, ret);
    return ret;
}

int combine(int a, int b)
{
    // a = x1 + x2*p1
    // a0 = x1 (mod p1)
    // a1 = x1 + x2*p1 (mod p2)
    int x1 = a;
    int x2 = sub(b, x1, p2);
    x2 = mul(x2, mod_inv(p1, p2), p2);
    return add(x1, mul(x2, p1, p), p);
}

int ncr_mod_p(int n, int r)
{
    return combine(calc_ncr(n, r, p1), calc_ncr(n, r, p2));
}

void solveCase()
{
    fact_p1[0] = fact_p2[0] = 1;
    // ncr_p1[0][0] = ncr_p2[0][0] = ncr_p[0][0] = 1;
    for (size_t i = 1; i < NAX; i++)
    {
        // if (i > 0)
        {
            fact_p1[i] = mul(fact_p1[i - 1], i, p1);
            fact_p2[i] = mul(fact_p2[i - 1], i, p2);
        }
        // ncr_p1[i][0] = ncr_p2[i][0] = ncr_p[i][0] = 1;
        // for (size_t j = 1; j < NAX; j++)
        // {
        //     ncr_p1[i][j] = add(ncr_p1[i - 1][j], ncr_p1[i - 1][j - 1], p1);
        //     ncr_p2[i][j] = add(ncr_p2[i - 1][j], ncr_p2[i - 1][j - 1], p2);
        //     ncr_p[i][j] = add(ncr_p[i - 1][j], ncr_p[i - 1][j - 1], p);
        // }
    }
    // int q;
    // cin >> q;
    // while (q--)
    // {
    //     int n, r;
    //     cin >> n >> r;
    //     db(n, r);

    //     auto ncr_p1_calc = calc_ncr(n, r, p1);
    //     auto ncr_p2_calc = calc_ncr(n, r, p2);

    //     db(ncr_p1[n][r], ncr_p1_calc);
    //     db(ncr_p2[n][r], ncr_p2_calc);
    //     ll ncr_p_calc = combine(ncr_p1_calc, ncr_p2_calc);
    //     db(ncr_p[n][r], ncr_p_calc);
    // }
    int n, m, k;
    cin >> n >> m >> k;
    int res = 0;
    for (int i = 0; i <= n; i++)
    {
        int aux = ncr_mod_p(n, i);
        aux = mul(aux, ncr_mod_p(n + k - 1 - i * (m + 1), n - 1), p);
        if (i & 1)
            res = sub(res, aux, p);
        else
            res = add(res, aux, p);
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
    // cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}