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
const double EPS = 1e-8;

class Solution
{
private:
    const double pi = acos(-1);
    double correct(double ang)
    {
        while (ang >= pi)
            ang -= pi;
        while (ang < 0)
            ang += pi;
        return ang;
    }

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
        double l = 0, r = 4000, ans = r;

        auto intersect = [&](pair<double, double> C1, double R1, pair<double, double> C2, double R2) {
            vector<pair<double, double>> res;
            auto x1 = C1.first;
            auto y1 = C1.second;
            auto x2 = C2.first;
            auto y2 = C2.second;

            double a = 2 * (x1 - x2);
            double b = 2 * (y1 - y2);
            double c = R2 * R2 - R1 * R1 - (x2 * x2 - x1 * x1) - (y2 * y2 - y1 * y1);

            if (abs(b) < EPS)
            {
                double x = c / a;
                double d = R1 * R1 - (x - x1) * (x - x1);
                if (d + EPS >= 0)
                {
                    if (d < EPS)
                    {
                        d = 0;
                    }
                    d = sqrt(d);
                    res.emplace_back(x, y1 + d);
                    res.emplace_back(x, y1 - d);
                }
            }
            else
            {
                double aa = a / b;
                double bb = y1 - c / b;

                double A = 1 + aa * aa;
                double B = 2 * (aa * bb - x1);
                double C = -(R1 * R1 - x1 * x1 - bb * bb);

                double d = B * B - 4 * A * C;
                if (d + EPS >= 0)
                {
                    if (d < 0)
                    {
                        d = 0;
                    }
                    d = sqrt(d);
                    for (int i = -1; i < 2; i += 2)
                    {
                        double x = (-B + d * i) / (2 * A);
                        double y = (c - a * x) / b;
                        res.emplace_back(x, y);
                    }
                }
            }
            return res;
        };
        auto getIntersection = [&](int idx1, int idx2, double rad) -> pair<point, point> {
            auto ret = intersect({points[idx1].real(), points[idx1].imag()}, rad, {points[idx2].real(), points[idx2].imag()}, rad);
            if (ret.size() == 0)
                return {point(-1), point(-1)};
            return {point(ret.front().f, ret.front().s), point(ret.back().f, ret.back().s)};
        };

        auto check = [&](double rad) -> bool {
            for (size_t i = 0; i < n; i++)
            {
                bool ok = true;
                for (size_t k = 0; k < n; k++)
                    ok = ok && (rad >= (abs(points[k] - points[i])) - EPS);
                if (ok)
                    return true;
                for (size_t j = i + 1; j < n; j++)
                {
                    auto centres = getIntersection(i, j, rad);
                    // db(centres, rad);
                    if (centres.f.real() < 0)
                        continue;
                    // if (fabs(abs(centres.f - points[i])) > EPS || fabs(abs(centres.f - points[j])) > EPS)
                    // {
                    //     db(points[i], points[j], centres, rad);
                    //     db(i, j, abs(centres.f - points[i]), abs(centres.f - points[j]));
                    //     // getIntersection(i, j, rad, true);
                    //     assert(false);
                    // }
                    // if (fabs(abs(centres.s - points[i])) > EPS || fabs(abs(centres.s - points[j])) > EPS)
                    // {
                    //     db(points[i], points[j], centres, rad);
                    //     // db(i, j, abs(centres.f - points[i]), abs(centres.s - points[j]));
                    //     // getIntersection(i, j, rad, true);
                    //     assert(false);
                    // }
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
            }
            return false;
        };
        int cnt = 200;
        while (cnt--)
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
        cout << fixed << setprecision(10) << ans << '\n';
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