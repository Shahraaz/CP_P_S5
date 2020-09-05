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

struct Solution
{
    Solution() {}
    void solveCase();
};

void Solution::solveCase()
{
    int n;
    cin >> n;
    if (n <= 2)
    {
        cout << 0 << '\n';
        return;
    }
    vector<pair<pair<ll, ll>, ll>> points(n);
    for (size_t i = 0; i < n; i++)
        cin >> points[i].f.f >> points[i].f.s >> points[i].s;
    auto check = [&](int idx) -> ll {
        vector<pair<pair<ll, ll>, ll>> temp;
        for (size_t j = 0; j < n; j++)
        {
            if (idx == j)
                continue;
            temp.pb({{points[j].f.f - points[idx].f.f, points[j].f.s - points[idx].f.s}, points[j].s});
        }
        // auto sgn = [](ll m) -> int {
        //     return m > 0 - m < 0;
        // };
        auto Quad = [](ll x, ll y) -> int {
            if (x == 0)
            {
                if (y >= 0)
                    return 2;
                else
                    return 4;
            }
            if (y == 0)
            {
                if (x > 0)
                    return 1;
                else
                    return 3;
            }
            if (x > 0)
                if (y > 0)
                    return 1;
            if (x < 0)
                if (y > 0)
                    return 2;
            if (x < 0)
                if (y < 0)
                    return 3;
            if (x > 0)
                if (y < 0)
                    return 4;
            db(x, y, "uff");
            exit(1);
            return 4;
        };

        auto cmp = [&](const pair<pair<ll, ll>, ll> &l, const pair<pair<ll, ll>, ll> &r) -> ll {
            ll a = Quad(l.f.f, l.f.s);
            ll b = Quad(r.f.f, r.f.s);
            if (a == b)
            {
                return l.f.s * r.f.f < l.f.f * r.f.s;
            }
            return a <= b;
        };
        sort(all(temp), cmp);
        db(temp);
        for (size_t i = 1; i < temp.size(); i++)
        {
            int Q = Quad(temp[i].f.f, temp[i].f.s);
            auto a = atan2l(temp[i - 1].f.s, temp[i - 1].f.f);
            auto b = atan2l(temp[i].f.s, temp[i].f.f);
            db(Q, temp[i], temp[i - 1], a, b, a < b);
        }

        vector<ll> mySumUtil;
        for (size_t i = 0; i < temp.size(); i++)
        {
            mySumUtil.pb(temp[i].s);
            if (i > 0)
                mySumUtil.back() += mySumUtil[i - 1];
        }
        for (size_t i = 0; i < temp.size(); i++)
        {
            ll ttemp = mySumUtil.back();
            mySumUtil.pb(temp[i].s);
            mySumUtil.back() += ttemp;
        }
        for (size_t j = 1; j < n; j++)
            temp.pb(temp[j - 1]);

        ll res = LLONG_MAX;
        int lptr = 0, rptr = 0;
        // ll lsum = 0,rsum = 0
        for (size_t i = 0; i < (n - 1); i++)
        {
            if (lptr <= (i + 1))
                lptr = i + 1;
            while (lptr < (i + n - 1))
                if (temp[lptr].f.f * temp[i].f.s <= temp[lptr].f.s * temp[i].f.f)
                    ++lptr;
                else
                    break;
            // db(lptr);
            if (rptr <= lptr)
                rptr = lptr;
            while (rptr < (i + n - 1))
                if (temp[rptr].f.f * temp[i].f.s >= temp[rptr].f.s * temp[i].f.f)
                    ++rptr;
                else
                    break;
            // db(rptr);
            auto compute_sum = [&](int l, int r) -> ll {
                if (l > r)
                    return 0;
                if (l < 0)
                    return mySumUtil[r];
                return mySumUtil[r] - mySumUtil[l - 1];
            };
            ll lsum = compute_sum(i + 1, lptr - 1);
            ll rsum = compute_sum(lptr, rptr - 1);
            res = min(res, abs(lsum - rsum));
            // db(i, lptr, rptr);
        }
        return res;
    };
    ll res = LLONG_MAX;
    for (size_t i = 0; i < n; i++)
        res = min(res, check(i));
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
