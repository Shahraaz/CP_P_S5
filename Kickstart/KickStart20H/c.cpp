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
const long long NAX = 2e5 + 5, MOD = 2e9 + 7;

void solveCase()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> locs(n);
    for (auto &x : locs)
        cin >> x.first >> x.second;
    ll once = LLONG_MAX;
    sort(all(locs));
    {
        ll low = -MOD, high = MOD;
        auto compute = [&](ll xx) -> ll {
            ll ret = 0;
            for (auto &x : locs)
            {
                ret += abs(x.first - xx);
                ++xx;
            }
            return ret;
        };
        while (low + 500 <= high)
        {
            ll m1 = (low + low + high) / 3;
            ll m2 = (low + high + high) / 3;
            db(low, m1, m2, high);
            if (compute(m1) >= compute(m2))
                low = m1;
            else
                high = m2;
        }
        while (low <= high)
        {
            auto temp = compute(low);
            once = min(once, temp);
            db(low, temp);
            ++low;
        }
    }
    db(once);
    auto compute = [&](ll y) -> ll {
        ll ret = 0;
        for (auto &x : locs)
            ret += abs(y - x.second);
        return ret + once;
    };
    ll low = -MOD, high = MOD, ans = LLONG_MAX;
    while (low + 500 <= high)
    {
        ll m1 = (low + low + high) / 3;
        ll m2 = (low + high + high) / 3;
        db(low, m1, m2, high);
        if (compute(m1) >= compute(m2))
            low = m1;
        else
            high = m2;
    }
    while (low <= high)
    {
        auto temp = compute(low);
        ans = min(ans, temp);
        db(low, temp);
        ++low;
    }
    cout << ans << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solveCase();
#ifdef TIMER
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}