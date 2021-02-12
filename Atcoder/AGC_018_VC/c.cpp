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
    int x, y, z;
    cin >> x >> y >> z;
    db(x, y, z);
    ll sum_c = 0;
    vector<pair<ll, ll>> a_b(x + y + z);
    vector<ll> a_(x + y + z), b_(x + y + z);
    for (size_t i = 0; i < x + y + z; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a -= c;
        b -= c;
        sum_c += c;
        a_b[i] = {a - b, i};
        a_[i] = a;
        b_[i] = b;
    }
    sort(all(a_b));
    db(a_b);
    vector<ll> left(x + y + z), right(x + y + z);
    multiset<pair<int, int>> left_, right_;
    ll left_y_greatest = 0, right_x_gratest = 0;
    for (size_t i = 0; i < x + y + z; i++)
    {
        auto idx = a_b[i].second;
        // db(i, idx, a_[idx], b_[idx]);
        left_.insert({b_[idx], i});
        left_y_greatest += b_[idx];
        if (left_.size() > y)
        {
            auto it = left_.begin();
            left_y_greatest -= it->first;
            left_.erase(it);
        }
        if (left_.size() == y)
            left[i] = left_y_greatest;
        db(i, left[i], left_);
    }
    for (int i = x + y + z - 1; i >= 0; i--)
    {
        auto idx = a_b[i].second;
        // db(i, idx, a_[idx], b_[idx]);
        right_.insert({a_[idx], i});
        right_x_gratest += a_[idx];
        if (right_.size() > x)
        {
            auto it = right_.begin();
            right_x_gratest -= it->first;
            right_.erase(it);
        }
        if (right_.size() == x)
            right[i] = right_x_gratest;
        db(i, right[i], right_);
    }
    ll res = LLONG_MIN;
    for (int i = 0; i + 1 < x + y + z; i++)
    {
        int leftcnt = i + 1;
        int rightcnt = x + y + z - leftcnt;
        ll temp = left[i];
        temp += right[i + 1];
        db(i, left[i], right[i + 1], temp, res);
        if (leftcnt >= y && rightcnt >= x)
            res = max(res, temp);
    }
    cout << res + sum_c << '\n';
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