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
    int h;
    cin >> h;
    vector<ll> neg, pos;
    for (size_t i = 0; i < h; i++)
    {
        ll x;
        cin >> x;
        if (x >= 0)
            pos.pb(x);
        else
            neg.pb(x);
    }
    sort(all(pos));
    sort(all(neg));
    ll acc_pos = accumulate(all(pos), 0LL);
    ll acc_neg = -accumulate(all(neg), 0LL);
    ll res = LLONG_MAX;
    auto solve = [&](ll x, vector<ll> &pos) -> ll {
        ll ret = 0;
        for (auto &y : pos)
            ret += min(abs(y), abs(x - y));
        db(x, ret, pos);
        return ret;
    };
    if (pos.size())
    {
        ll low = 0, high = pos.back();
        while (high - low > 500)
        {
            ll m1 = (low + low + high) / 3;
            ll m2 = (low + high + high) / 3;
            ll a = solve(m1, pos), b = solve(m2, pos);
            if (a <= b)
            {
                res = min(res, acc_neg + a);
                high = m2;
            }
            else
            {
                res = min(res, acc_neg + b);
                low = m1;
            }
        }
        while (low <= high)
        {
            res = min(res, acc_neg + solve(low, pos));
            ++low;
        }
    }
    // swap(pos, neg);
    if (neg.size())
    {
        ll low = neg.front(), high = 0;
        while (high - low > 500)
        {
            ll m1 = (low + low + high) / 3;
            ll m2 = (low + high + high) / 3;
            ll a = acc_pos + solve(m1, neg), b = acc_pos + solve(m2, neg);
            if (a <= b)
            {
                res = min(res, a);
                high = m2;
            }
            else
            {
                res = min(res, b);
                low = m1;
            }
        }
        while (low <= high)
        {
            res = min(res, acc_pos + solve(low, neg));
            ++low;
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