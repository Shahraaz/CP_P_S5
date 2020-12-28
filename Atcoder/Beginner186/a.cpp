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

// int a[101][101];

#define int __int128_t
#define ll __int128_t

__int128_t myabs(__int128_t x)
{
    if (x < 0)
        return -x;
    return x;
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

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g)
{
    g = gcd(myabs(a), myabs(b), x0, y0);
    if (c % g)
    {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)
        x0 = -x0;
    if (b < 0)
        y0 = -y0;
    return true;
}

std::ostream &
operator<<(std::ostream &dest, __int128_t value)
{
    std::ostream::sentry s(dest);
    if (s)
    {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);
        do
        {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0)
        {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len)
        {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

void solveCase()
{
    int32_t n1, s1, k1;
    cin >> n1 >> s1 >> k1;
    ll n = n1, s = s1, k = k1;
    // cin >> n >> s >> k;
    db(n, s, k);
    ll x0, y0, g;
    if (find_any_solution(n, -k, s, x0, y0, g))
    {
        if (!(n * x0 + (-k) * y0) == s)
        {
            exit(1);
        }
        db(n * x0 + (-k) * y0, s);
        db(x0, y0, g);
        ll dx = k / g;
        ll dy = n / g;
        // assert(dx > 0 && dy > 0);
        if (!(dx > 0 && dy > 0))
        {
            exit(1);
        }
        db(dx, dy);
        bool ok = false;
        if (x0 < 0)
        {
            auto t = (-x0 + dx - 1) / dx;
            db("a", x0, y0, t);
            x0 += t * dx;
            y0 += t * dy;
            db(x0, y0);
        }
        else if (x0 >= dx)
        {
            auto t = x0 / dx;
            db("a", x0, y0, t);
            x0 -= t * dx;
            y0 -= t * dy;
            db(x0, y0);
            ok = true;
        }
        if (y0 < 0)
        {
            auto t = (-y0 + dy - 1) / dy;
            db("a", x0, y0, t);
            x0 += t * dx;
            y0 += t * dy;
            db(x0, y0);
        }
        // else if (y0 >= dy)
        // {
        //     auto t = y0 / dy;
        //     db("a", x0, y0, t);
        //     x0 -= t * dx;
        //     y0 -= t * dy;
        //     db(x0, y0);
        // }
        if (y0 > 0)
            cout << y0 << '\n';
        else
            cout << "-1\n";
    }
    else
        cout << "-1\n";
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int32_t t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}