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
typedef long long coord_t;  // coordinate type
typedef long long coord2_t; // must be big enough to hold 2*max(|coordinate|)^2

struct Point
{
    coord_t x, y;
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    bool operator<(const Point &p) const
    {
        return x < p.x || (x == p.x && y < p.y);
    }
};

// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
coord2_t cross(const Point &O, const Point &A, const Point &B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> &P)
{
    size_t n = P.size(), k = 0;
    if (n <= 3)
        return P;
    vector<Point> H(2 * n);
    // Sort points lexicographically
    sort(P.begin(), P.end());
    // Build lower hull
    for (size_t i = 0; i < n; ++i)
    {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0)
            k--;
        H[k++] = P[i];
    }
    // Build upper hull
    for (size_t i = n - 1, t = k + 1; i > 0; --i)
    {
        while (k >= t && cross(H[k - 2], H[k - 1], P[i - 1]) <= 0)
            k--;
        H[k++] = P[i - 1];
    }
    H.resize(k - 1);
    return H;
}

void solveCase()
{
    int n;
    cin >> n;
    vector<Point> points(n);
    for (size_t i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        points[i] = Point(x, y);
    }
    points = convex_hull(points);
    ll res = 0;
    n = points.size();
    for (int lptr = 0; lptr < n; lptr++)
    {
        auto inc = [&](int x) -> int {
            if (x == lptr)
                return x;
            ++x;
            if (x >= n)
                x = lptr;
            return x;
        };
        auto rptr = (lptr + 1) % n;
        int best_ptr = inc(rptr);
        int next_to_best_ptr = inc(best_ptr);
        auto area = [&](int idx) -> ll {
            ll a = points[lptr].x * 1LL * (points[rptr].y - points[idx].y);
            a += points[rptr].x * 1LL * (points[idx].y - points[lptr].y);
            a += points[idx].x * 1LL * (points[lptr].y - points[rptr].y);
            db(lptr, rptr, idx, a);
            return abs(a);
        };
        while (rptr != lptr)
        {
            while (next_to_best_ptr != lptr && area(best_ptr) <= area(next_to_best_ptr))
            {
                best_ptr = inc(best_ptr);
                next_to_best_ptr = inc(next_to_best_ptr);
            }
            res = max(res, area(best_ptr));
            rptr = inc(rptr);
        }
    }
    cout << fixed << setprecision(10) << ((long double)res / 2) << '\n';
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