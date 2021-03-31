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

using ld = long double;

struct Point
{
    ld x, y, z;
    Point(ld _x = 0, ld _y = 0, ld _z = 0) : x(_x), y(_y), z(_z) {}
    Point operator+(Point rhs)
    {
        return Point(x + rhs.x, y + rhs.y, z + rhs.z);
    }
    Point operator-(Point rhs)
    {
        return Point(x - rhs.x, y - rhs.y, z - rhs.z);
    }
    Point operator*(ld c)
    {
        return Point(x * c, y * c, z * c);
    }
    Point operator/(ld c)
    {
        return Point(x / c, y / c, z / c);
    }
    ld abs()
    {
        return sqrtl(x * x + y * y + z * z);
    }
    Point dig()
    {
        return *this / abs();
    }
};

Point cross(Point a, Point b)
{
    return Point(a.y * b.z - b.y * a.z, b.x * a.z - a.x * b.z, a.x * b.y - a.y * b.x);
}

ld dot(Point a, Point b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

ld dist(Point a, Point b)
{
    return (a - b).abs();
}

ld dist(Point a, Point b, Point c)
{
    ld x = dist(b, c);
    ld y = dist(a, c);
    ld z = dist(a, b);
    if (x * x + z * z < y * y)
        return x;
    if (y * y + z * z < x * x)
        return y;
    ld h = (z * z + y * y - x * x) / (2 * z);
    return sqrtl(y * y - h * h);
}

ld dist(Point a, Point b, Point c, Point d)
{
    Point pla = cross(b - a, c - a).dig();
    bool in = 1;
    if (dot(cross(b - a, pla), d - a) > 0)
        in = 0;
    if (dot(cross(c - b, pla), d - b) > 0)
        in = 0;
    if (dot(cross(a - c, pla), d - c) > 0)
        in = 0;
    if (in)
        return abs(dot(d - a, pla));
    return min({dist(a, b, d), dist(b, c, d), dist(c, a, d)});
}

ld dist(Point a, Point b, Point c, Point d, Point e)
{
    ld l = 0, r = 1;
    int tot = 100;
    ld res = 1e18;
    while (tot--)
    {
        auto m1 = (l + l + r) / 3;
        auto m2 = (l + r + r) / 3;
        ld tmp1 = dist(a, b, c, d + (e - d) * m1);
        ld tmp2 = dist(a, b, c, d + (e - d) * m2);
        if (tmp1 <= tmp2)
            res = tmp2, r = m2;
        else
            res = tmp1, l = m1;
    }
    return res;
}

void solveCase()
{
    vector<Point> a(6);
    for (auto &x : a)
        cin >> x.x >> x.y >> x.z;
    ld res = 1e18;
    for (size_t i = 0; i < 3; i++)
    {
        int j = (i + 1) % 3;
        int k = (j + 1) % 3;
        res = min(res, dist(a[3], a[4], a[5], a[j], a[k]));
        j += 3, k += 3;
        res = min(res, dist(a[0], a[1], a[2], a[j], a[k]));
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
    cin >> t;
    cout << fixed << setprecision(12);
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}