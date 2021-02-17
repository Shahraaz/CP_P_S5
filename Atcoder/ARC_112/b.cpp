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
    ll B, C;
    cin >> B >> C;
    vector<pair<ll, ll>> ways;
    function<void(ll, ll, int)> weird = [&](ll b, ll c, int cnt) -> void {
        if (c < 0 || cnt < 0)
            return;
        weird(-b, c - 1, cnt - 1);
        weird(b - 1, c - 2, cnt - 1);

        if (c >= 2)
        {
            ways.pb({b, b + (c - 2) / 2});
            weird(b + (c - 2) / 2, (c - 2) % 2, cnt - 1);

            ways.pb({b - (c - 2) / 2, b});
            weird(b - (c - 2) / 2, 2 + c % 2, cnt - 1);
        }
        ways.pb({b - c / 2, b});
        weird(b - c / 2, c % 2, cnt - 1);
    };
    weird(B, C, 5);
    sort(all(ways));
    db(ways);
    ll res = 0;
    ll prevlptr = LLONG_MIN;
    ll prevrptr = LLONG_MIN;
    vector<pair<ll, ll>> res_ways;
    for (auto &x : ways)
    {
        if (prevrptr < x.first)
        {
            if (prevrptr != LLONG_MIN)
            {
                res_ways.pb({prevlptr, prevrptr});
                res += prevrptr - prevlptr + 1;
            }
            prevlptr = x.first;
            prevrptr = x.second;
        }
        else
            prevrptr = max(prevrptr, x.second);
    }
    if (prevrptr != LLONG_MIN)
    {
        res_ways.pb({prevlptr, prevrptr});
        res += prevrptr - prevlptr + 1;
    }
    db(res_ways);
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