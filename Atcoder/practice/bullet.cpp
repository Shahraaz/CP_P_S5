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

class Solution
{
private:
    pair<ll, ll> get(ll a, ll b)
    {
        if (a == 0 && b == 0)
            return {a, b};
        ll g = __gcd(a, b);
        a /= g, b /= g;
        if (b < 0)
            a *= -1, b *= -1;
        if (a == 0)
            b = 1;
        if (b == 0)
            a = 1;
        return {a, b};
    }
    pair<ll, ll> opp(pair<ll, ll> a)
    {
        ll x = -a.s, y = a.f;
        if (x == 0 && y == 0)
            return {x, y};
        if (y < 0)
            x *= -1, y *= -1;
        if (x == 0)
            y = 1;
        if (y == 0)
            x = 1;
        return {x, y};
    }

public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        pre();
        int n;
        cin >> n;
        map<pair<ll, ll>, int> cnt;
        for (size_t i = 0; i < n; i++)
        {
            ll a, b;
            cin >> a >> b;
            cnt[get(a, b)]++;
        }
        db(cnt);
        ll ans = 1;
        map<pair<ll, ll>, int> vis;
        for (auto &x : cnt)
        {
            if (vis[x.f])
                continue;
            pair<ll, ll> t = {0, 0};
            if (x.f == t)
                continue;
            auto p = opp(x.f);
            db(x.f, p);
            if (cnt.count(p))
            {
                vis[p] = 1;
                ll it = x.s, y = cnt[p];
                ans = mul(ans, add(power(2, it), sub(power(2, y), 1)));
            }
            else
                ans = mul(ans, power(2, x.s));
            db(x, ans);
            db("----------");
        }
        ans = add(ans, cnt[{0, 0}]);
        ans = sub(ans, 1);
        cout << ans << '\n';
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
