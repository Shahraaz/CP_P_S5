// Optimise
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()

const int NAX = 2e5 + 5, MOD = 1000000007;

ll power(int base, int idx, int mod)
{
    if (idx == 0)
        return 1;
    auto temp = power(base, idx / 2, mod);
    temp *= temp;
    temp %= mod;
    int ret = 1;
    if (idx & 1)
        temp = (temp * base) % mod;
    return temp;
}

void solveCase()
{
    ll n, p, r;
    cin >> n >> p >> r;
    if (n == 2)
    {
        if (r == 1)
            cout << 2 << ' ' << 1 << '\n';
        else
            cout << -1 << ' ' << -1 << '\n';
        return;
    }
    if (r == 0)
    {
        if (n > p)
        {
            cout << n << ' ' << p << '\n';
        }
        else if (n == p)
        {
            cout << 2 << ' ' << 1 << '\n';
        }
        else
        {
            cout << -1 << ' ' << -1 << '\n';
        }
        return;
    }
    if (n >= 2 * p)
    {
        cout << -1 << ' ' << -1 << '\n';
        return;
    }
    else if (n >= p)
    {
        assert(r > 0);
        ll fact = 1;
        for (size_t i = 1; i <= n; i++)
            if (i != p)
                fact = (fact * i) % p;
        for (int i = 1; i < p; i++)
        {
            auto nval = (fact * i) % p;
            if (nval == r)
            {
                cout << p << ' ' << i << '\n';
                return;
            }
        }
    }
    else
    {
        ll fact = 1;
        for (size_t i = 1; i <= n; i++)
            fact = (fact * i) % p;
        ll fact_inv = power(fact, p - 2, p);
        ll temp = r * fact_inv % p;
        for (int i = 1; i <= n; i++)
        {
            auto nval = (temp * i) % p;
            if (0 < nval && nval < i)
            {
                cout << i << ' ' << nval << '\n';
                return;
            }
        }
    }
    cout << -1 << ' ' << -1 << '\n';
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
    {
        solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
