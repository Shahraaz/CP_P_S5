// Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define MULTI_TEST
#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#define pc(...)
#endif

#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()
auto TimeStart = chrono::steady_clock::now();
auto seed = TimeStart.time_since_epoch().count();
std::mt19937 rng(seed);
using ll = long long;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using Random = std::uniform_int_distribution<T>;

const int NAX = 2e5 + 5, MOD = 1000000007;
using point = complex<double>;
const double EPS = 1e-7;

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int n;
        vector<point> points;
        cin >> n;
        for (size_t i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            points.pb(point(x, y));
        }
        double l = 1, r = 2000, ans = r;
        auto getIntersection = [&](int idx1, int idx2, double rad, bool print = false) {
            point a = points[idx1];
            point b = points[idx2];
            if (a.imag() > b.imag() || (fabs(a.imag() - b.imag()) < EPS && a.real() > b.real()))
                swap(a, b);
            pair<point, point> ret;
            ret.f = point(-1.0, -1.0);
            auto dist = abs(b - a) / 2;
            if (dist > rad)
                return ret;
            auto ang1 = acos(dist / rad);
            auto ang2 = arg(b - a);
            // if (ang2 < 0)
            //     ang2 += 3.1415926535897;
            ret.f = polar(rad, ang2 - ang1);
            ret.s = polar(rad, ang2 + ang1);
            ret.f += a;
            ret.s += a;
            if (print)
            {
                db(rad, ang1, ang2, idx1, a, idx2, b, b - a, rad, dist, dist / rad);
            }
            return ret;
        };
        auto check = [&](double rad) -> bool {
            for (size_t i = 0; i < n; i++)
                for (size_t j = i + 1; j < n; j++)
                {
                    auto centres = getIntersection(i, j, rad);
                    // db(centres, rad);
                    if (centres.f.real() < 0)
                        continue;
                    if (fabs(abs(centres.f - points[i])) > EPS || fabs(abs(centres.f - points[j])) > EPS)
                    {
                        db(points[i], points[j], centres, rad);
                        // db(i, j, abs(centres.f - points[i]), abs(centres.f - points[j]));
                        getIntersection(i, j, rad, true);
                        assert(false);
                    }
                    if (fabs(abs(centres.s - points[i])) > EPS || fabs(abs(centres.s - points[j])) > EPS)
                    {
                        db(points[i], points[j], centres, rad);
                        // db(i, j, abs(centres.f - points[i]), abs(centres.s - points[j]));
                        getIntersection(i, j, rad, true);
                        assert(false);
                    }
                    bool ok = true;
                    for (size_t k = 0; k < n; k++)
                        if (k == i || j == i)
                            ;
                        else
                            ok = ok && (rad >= (abs(points[k] - centres.f)) - EPS);
                    if (ok)
                        return true;
                    ok = true;
                    for (size_t k = 0; k < n; k++)
                        if (k == i || j == i)
                            ;
                        else
                            ok = ok && (rad >= (abs(points[k] - centres.s) - EPS));
                    if (ok)
                        return true;
                }
            return false;
        };
        while (fabs(r - l) > EPS)
        {
            auto findMin = [](double x, double y) {
                if (x < 1 || y < 1)
                    return (x + y) / 2;
                return sqrt(x * y);
            };
            auto mid = findMin(l, r);
            auto res = check(mid);
            db(l, r, mid, res);
            if (res)
                r = mid,
                ans = min(ans, mid);
            else
                l = mid;
        }
        cout << fixed << setprecision(9) << ans << '\n';
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}