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

void solveCase()
{
    int n;
    cin >> n;
    using ld = long double;
    vector<deque<pair<ld, ld>>> paths(2);
    paths[0].resize(n);
    for (auto &x : paths[0])
        cin >> x.first >> x.second;
    int m;
    cin >> m;
    paths[1].resize(m);
    for (auto &x : paths[1])
        cin >> x.first >> x.second;
    ld res = LLONG_MAX;
    const ld EPS = 1e-9;
    auto get_dist = [](pair<ld, ld> a, pair<ld, ld> b) -> ld {
        return sqrtl((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
    };
    auto get_pnt = [&](ld t, int idx) -> pair<ld, ld> {
        if (t <= EPS)
        {
            assert(paths[idx].size());
            return paths[idx][0];
        }
        assert(paths[idx].size() > 1);
        pair<ld, ld> ret;
        ret.first = paths[idx][0].first + t * (paths[idx][1].first - paths[idx][0].first);
        ret.second = paths[idx][0].second + t * (paths[idx][1].second - paths[idx][0].second);
        return ret;
    };
    auto dist = [&](ld t) -> ld {
        auto a = get_pnt(t, 0);
        auto b = get_pnt(t, 1);
        auto d = get_dist(a, b);
        db(t, a, b, d);
        return d;
    };
    while (paths[0].size() && paths[1].size())
    {
        ld now = dist(0);
        res = min(res, now);
        db(paths[0]);
        db(paths[1]);
        db(res, now);
        ld t1 = 0, t2 = 0;
        if (paths[0].size() > 1)
            t1 = get_dist(paths[0][0], paths[0][1]);
        if (paths[1].size() > 1)
            t2 = get_dist(paths[1][0], paths[1][1]);
        ld tmin = min(t1, t2);
        db(t1, t2, tmin);
        ld low = 0, high = tmin;
        now = LLONG_MAX;
        while (high - low >= EPS)
        {
            ld m1 = (low + low + high) / 3;
            ld m2 = (low + high + high) / 3;
            ld d1 = get_dist(get_pnt(m1 / t1, 0), get_pnt(m1 / t2, 1));
            ld d2 = get_dist(get_pnt(m2 / t1, 0), get_pnt(m2 / t2, 1));
            // ld d2 = (dist(m2 / t2));
            // db(low, high);
            // db(m1, d1);
            // db(m2, d2);
            now = min(now, d1);
            now = min(res, d2);
            if (d1 >= d2)
                low = m1;
            else
                high = m2;
        }
        db(low, now);
        res = min(res, now);
        if (abs(t1 - tmin) <= EPS)
            paths[0].pop_front();
        else
        {
            auto p = get_pnt(tmin / t1, 0);
            db(tmin, 0, p);
            paths[0].pop_front();
            paths[0].push_front(p);
        }
        if (abs(t2 - tmin) <= EPS)
            paths[1].pop_front();
        else
        {
            auto p = get_pnt(tmin / t2, 1);
            db(tmin, 1, p);
            paths[1].pop_front();
            paths[1].push_front(p);
        }
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
    // cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}