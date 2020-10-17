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

const int _n = 2e5 + 10;
vector<int> Fact(_n), Inv(_n);
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

void pre()
{
    Fact[0] = 1;
    for (int i = 1; i < _n; ++i)
        Fact[i] = mul(Fact[i - 1], i);
    Inv[_n - 1] = mod_inv(Fact[_n - 1]);
    for (int i = _n - 2; i >= 0; --i)
        Inv[i] = mul(Inv[i + 1], (1 + i));
}

int ncr(int n, int r)
{
    if (n < 0 || r < 0 || n - r < 0)
        return 0;
    return mul(Fact[n], mul(Inv[r], Inv[n - r]));
}

int npr(int n, int r)
{
    if (n < 0 || r < 0 || n - r < 0)
        return 0;
    return mul(Fact[n], Inv[n - r]);
}

void solveCase()
{
    int n, m;
    cin >> n >> m;
    vector<ll> row(n), col(m);
    for (auto &x : row)
    {
        cin >> x;
    }
    for (auto &x : col)
    {
        cin >> x;
    }
    sort(all(row));
    sort(all(col));
    db(row);
    db(col);
    ll area = 0, area2 = 0;
    for (size_t i = 0; i + 1 < n; i++)
    // for (size_t j = 0; j + 1 < m; j++)
    {
        ll currArea = row[i + 1] - row[i];
        currArea %= MOD;
        // currArea *= col[j + 1] - col[j];
        // currArea %= MOD;
        ll contrib = mul(currArea, mul(i + 1, n - i - 1));
        // contrib = mul(contrib, mul(j + 1, m - j - 1));
        db(i, area, contrib);
        area = add(area, contrib);
    }
    // for (size_t i = 0; i + 1 < n; i++)
    for (size_t j = 0; j + 1 < m; j++)
    {
        ll currArea = 1;
        // currArea %= MOD;
        currArea *= col[j + 1] - col[j];
        currArea %= MOD;
        // ll contrib = mul(currArea, mul(i + 1, n - i - 1));
        ll contrib = mul(currArea, mul(j + 1, m - j - 1));
        // db(i, j, currArea, contrib);
        db(j, area2, contrib);
        area2 = add(area2, contrib);
    }
    db(area, area2);
    cout << mul(area2, area) << '\n';
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
