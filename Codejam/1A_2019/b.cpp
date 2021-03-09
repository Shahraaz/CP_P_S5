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
const int NAX = 1e6 + 5, MOD = 1000000007;

ll euclid(ll a, ll b, ll &x, ll &y)
{
    if (b)
    {
        ll d = euclid(b, a % b, y, x);
        return y -= a / b * x, d;
    }
    return x = 1, y = 0, a;
}

ll crt(ll a, ll m, ll b, ll n)
{
    if (n > m)
        swap(a, b), swap(m, n);
    if (n == 1)
        return a;
    ll x, y, g = euclid(m, n, x, y);
    if ((a - b) % g != 0)
        return LLONG_MAX;
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m * n / g : x;
}

pair<ll, ll> crt(const vector<ll> &r, const vector<ll> &m)
{
    ll r0 = 0, m0 = 1;
    assert(r.size() == m.size());
    for (size_t i = 0; i < r.size(); i++)
    {
        auto rem = crt(r0, m0, r[i], m[i]);
        // db(r0, m0, r[i], m[i], rem);
        if (rem == LLONG_MAX)
            return {LLONG_MAX, LLONG_MAX};
        r0 = rem;
        m0 = m0 / __gcd(m0, m[i]) * m[i];
    }
    return {r0, m0};
}
int n, m;

void solveCase()
{

    db(n);
    vector<ll> p = {5, 7, 9, 11, 13, 16, 17};
    vector<ll> r = {5, 7, 9, 11, 13, 16, 17};
    assert(p.size() <= n);
    for (size_t i = 0; i < p.size(); i++)
    {
        for (size_t j = 0; j < 18; j++)
            cout << p[i] << ' ';
        cout << endl;
        ll rem = 0, x;
        for (size_t j = 0; j < 18; j++)
        {
            cin >> x;
            assert(x != -1);
            rem += x;
        }
        r[i] = rem % p[i];
    }
    auto res = crt(r, p);
    db(res, r, p);
    for (size_t i = 0; i < p.size(); i++)
    {
        db(r[i], res.first % p[i]);
        assert(r[i] == (res.first % p[i]));
    }

    cout << res.first << endl;
    ll verdict;
    cin >> verdict;
    assert(verdict == 1);
}

int32_t main()
{
#ifndef LOCAL
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
#endif
    int t = 100;
    cin >> t >> n >> m;
    db(t);
    for (int i = 1; i <= t; ++i)
    {
        // cout << "Case #" << i << ": ";
        solveCase();
    }
    return 0;
}