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

vector<ll> split(ll n)
{
    vector<ll> ret;
    for (ll i = ceil(sqrtl(n)); i >= 2; i--)
    {
        if (i == n)
            continue;
        if (n % i == 0)
        {
            ret.pb(i);
            ret.pb(n / i);
            break;
        }
    }
    return ret;
}

void wassert(int b)
{
    if (!b)
    {
        cout << "Forced wa\n";
        exit(0);
    }
}

void solveCase()
{
    int l = 20, q = 4523;
    cin >> l >> q;
    kmod = q;
    db(l, q, kmod);
    vector<int> fact(q), ifact(q);
    fact[0] = 1;
    for (size_t i = 1; i < q; i++)
        fact[i] = mul(i, fact[i - 1]);
    ifact[q - 1] = mod_inv(fact[q - 1]);
    // db(mul(fact[q - 1], ifact[q - 1]));
    for (int i = q - 2; i >= 0; i--)
    {
        ifact[i] = mul(ifact[i + 1], i + 1);
        // db(i, fact[i], ifact[i], mul(fact[i], ifact[i]));
    }
    for (size_t i = 0; i < l; i++)
    {
        ll n = 908993 * 1LL * 909023;
        db(n <= 1e12);
        cin >> n;
        int res = 0;
        auto partition = split(n);
        db(n, partition);
        // wassert(partition.size() == 2);
        partition.pb(1);
        partition.pb(n);

        sort(all(partition));
        partition.erase(unique(all(partition)), partition.end());

        db(n, partition);
        function<int(ll, ll)> ncr = [&](ll n, ll r) -> int {
            if (n == r || r == 0)
                return 1;
            if (n >= q)
                return mul(ncr(n % q, r % q), ncr(n / q, r / q));
            if (n < 0 || r < 0 || n - r < 0)
                return 0;
            auto ret = mul(fact[n], mul(ifact[r], ifact[n - r]));
            // db(n, r, ret);
            return ret;
        };
        function<int(ll, ll)> compute = [&](ll n, ll sz) -> int {
            if (n % sz)
                return 0;
            int ret = 1;
            while (n > 0)
            {
                ret = mul(ret, ncr(n - 1, sz - 1));
                if (ret == 0)
                    break;
                n -= sz;
            }
            return ret;
        };
        for (auto &teamsize : partition)
        {
            db(teamsize);
            if (teamsize == 1 || teamsize == n)
                res = add(res, 1);
            else
                res = add(res, compute(n, teamsize));
        }
        cout << res << '\n';
    }
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 5;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case " << i << ":\n";
        solveCase();
    }
    return 0;
}