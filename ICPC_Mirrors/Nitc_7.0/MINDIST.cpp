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

const int NAX = 1e5 + 5, MOD = 1000000007;

using ld = long double;
const ld EPS = 1e-15;

bool lt(ld a, ld b)
{
    return (a + EPS) < b;
}

bool eq(ld a, ld b)
{
    return fabsl(a - b) < EPS;
}

bool gt(ld a, ld b)
{
    return (b + EPS) < a;
}

bool lteq(ld a, ld b)
{
    return !gt(a, b);
}

bool gteq(ld a, ld b)
{
    return !lt(a, b);
}

ld a[NAX], b[NAX], c[NAX], d[NAX];
int n;

ld dis(ld *a, ld *b, ld *c, ld *d)
{
    ld ret = 0;
    for (size_t i = 0; i < n; i++)
        ret += (a[i] - b[i]) * (c[i] - d[i]);
    return ret;
}

ld check(ld x, ld y)
{
    ld ret = LDBL_MAX;
    if (lteq(x, 0))
        x = 0;
    if (lteq(1, x))
        x = 1;
    if (lteq(y, 0))
        y = 0;
    if (lteq(1, y))
        y = 1;
    ret = 0;
    for (size_t i = 0; i < n; i++)
    {
        ld x1 = ::a[i] + x * (::b[i] - ::a[i]);
        ld y1 = ::c[i] + y * (::d[i] - ::c[i]);
        ret += (y1 - x1) * (y1 - x1);
    }
    ret = sqrtl(ret);
    db(x, y, ret);
    return ret;
}

ld solve(ld a, ld b, ld c, ld d, ld e, ld f)
{
    ld den = a * e - b * d;
    if (eq(den, 0))
        return LDBL_MAX;
    ld x = c * e - b * f;
    x /= den;
    ld y = a * f - c * d;
    y /= den;
    db(a * x + b * y, c, d * x + e * y, f);
    db(lteq(a * x + b * y, c));
    db(lteq(d * x + e * y, f));
    return check(x, y);
}

ld dis(ld *a, ld *b)
{
    return sqrtl(dis(a, b, a, b));
}

// ld dis_linear(ld *a, ld *b, ld *c, ld *d, ld x)
// {
//     ld ret = 0;
//     for (size_t i = 0; i < n; i++)
//     {
//         ret +=
//     }
//     return ret;
// }

ld solvex(ld x)
{
    ld den = dis(d, c, d, c);
    if (eq(den, 0))
        return LDBL_MAX;
    ld num = 0;
    for (size_t i = 0; i < n; i++)
        num += (d[i] - c[i]) * (a[i] - c[i] + x * b[i] - x * a[i]);
    auto y = num / den;
    db(num, den, x, y);
    ld ret = check(x, y);
    return ret;
}

ld solvey(ld y)
{
    ld den = dis(b, a, b, a);
    if (eq(den, 0))
        return LDBL_MAX;
    ld num = 0;
    for (size_t i = 0; i < n; i++)
        num += (b[i] - a[i]) * (a[i] - c[i] - y * d[i] + y * c[i]);
    auto x = -num / den;
    db(num, den, y, x);
    ld ret = check(x, y);
    return ret;
}

ld solve_trivial()
{
    return min({dis(a, c), dis(a, d), dis(b, c), dis(b, d)});
}

struct Solution
{
    Solution() {}
    void solveCase()
    {
        cin >> n;
        for (size_t i = 0; i < n; i++)
            cin >> a[i];
        for (size_t i = 0; i < n; i++)
            cin >> b[i];
        for (size_t i = 0; i < n; i++)
            cin >> c[i];
        for (size_t i = 0; i < n; i++)
            cin >> d[i];
        ld ans = LDBL_MAX;
        ans = solve(-dis(b, a, b, a), dis(b, a, d, c), dis(b, a, c, a), -dis(d, c, b, a), dis(d, c, d, c), dis(d, c, a, c));
        ans = min(ans, solvex(0));
        ans = min(ans, solvex(1));
        ans = min(ans, solvey(0));
        ans = min(ans, solvey(1));
        ans = min(ans, solve_trivial());
        cout << fixed << setprecision(15);
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
    cin >> t;
    cerr << fixed << setprecision(10);
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
