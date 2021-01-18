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
    vector<ll> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    ll res = 0;
    for (int bit = 0; bit < 32; bit++)
    {
        auto a_t = a, b_t = b;
        auto t = 1LL << bit;

        for (auto &x : a_t)
            x %= 2 * t;
        for (auto &x : b_t)
            x %= 2 * t;

        sort(all(a_t));
        sort(all(b_t));

        auto count_range = [&](ll low, ll high) -> ll {
            if (low > high)
                return 0;
            low = max(0LL, low);
            high = max(0LL, high);
            return upper_bound(all(b_t), high) - lower_bound(all(b_t), low);
        };
        ll cnt = 0;
        for (auto &x : a_t)
        {
            // for bit t to be one
            // t <= x+y < 2*t or 3*t <= x+y < 4*t;
            cnt += count_range(t - x, 2 * t - 1 - x);
            cnt += count_range(3 * t - x, 4 * t - 1 - x);
        }
        if (cnt & 1)
        {
            res += t;
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