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

const int _n = 2e6 + 10;
vector<int> Fact(_n), Inv(_n);

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

struct Point
{
    int x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    void in() { cin >> x >> y; }
    Point operator+(const Point &rhs)
    {
        auto ret = *this;
        ret.x += rhs.x;
        ret.y += rhs.y;
        return ret;
    }
    Point operator-(const Point &rhs)
    {
        auto ret = *this;
        ret.x -= rhs.x;
        ret.y -= rhs.y;
        return ret;
    }
};

struct L
{
    ll A, B, C;
    int sgn, r;
    L() {}
    L(Point a, Point b, Point c)
    {
        A = (a - b).y;
        B = (b - a).x;
        C = -(A * a.x + B * a.y);
        ll r1 = A * c.x + B * c.y + C;
        ll r2 = A * (a.x - 1) + B * (a.y - 1) + C;
        r1 = (r1 > 0) - (r1 < 0);
        r2 = (r2 > 0) - (r2 < 0);
        r = r1;
        if (r2 == 0)
            sgn = 0;
        else
            sgn = r1 * r2;
    }
};

ll round_down(ll p, ll q)
{
    if (p >= 0)
        return p / q;
    return p % q == 0 ? p / q : (p / q - 1);
}

ll round_up(ll p, ll q)
{
    if (p >= 0)
        return (p + q - 1) / q;
    return p / q;
}

int calc(ll x, int i)
{
    if (x < i)
        return 0;
    if (x > _n)
    {
        db(x, i);
        assert(false);
    }
    return ncr(x + 1, i + 1);
}

int calc(int i, ll l, ll r)
{
    return sub(calc(r, i), calc(l - 1, i));
}

void solveCase()
{
    Point A, B, C;
    A.in();
    B.in();
    C.in();
    vector<L> l(3);
    l[0] = L(A, B, C);
    l[1] = L(B, C, A);
    l[2] = L(C, A, B);
    int ans = 0;
    const int LIM = 1e6+2;
    for (int i = 0; i < LIM; i++)
    {
        ll up = 1LL << 60;
        ll low = -(1LL << 60);
        for (auto &li : l)
            if (li.sgn != 0)
            {
                int sgn = li.sgn;
                ll p = -2LL * li.B * i - li.C;
                ll q = li.A + li.B;
                if (q < 0)
                    p = -p, q = -q;
                db(p, q, li.A, li.B, li.C, li.sgn, li.r);
                if (sgn > 0)
                    up = min(up, round_down(p, q));
                else
                    low = max(low, round_up(p, q));
            }
            else
            {
                ll r = li.A * (-2 * i) + li.C;
                db(r, li.A, li.B, li.C, li.sgn, li.r);
                if (r * li.r < 0)
                {
                    low = 1LL << 60;
                    break;
                }
            }
        db(i, low, up);
        if (low <= up)
            ans = add(ans, calc(i, low + 2 * i, up + 2 * i));
    }
    cout << ans << '\n';
}

int32_t main()
{
    pre();
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