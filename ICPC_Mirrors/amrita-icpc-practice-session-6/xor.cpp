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
    long long k;
    cin >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    ll low = 0, high = INT_MAX;
    ll ans = high;
    db(n, k, a);
    function<ll(ll, int, vector<int>)> cnt_less = [&](ll curr, int idx, vector<int> a) -> ll {
        if (a.empty())
            return 0;
        if (idx == -1)
            return 0;
        auto p = (curr >> idx) & 1;
        ll ret = 0;
        if (p == 0)
        {
            vector<int> a0, a1;
            for (auto &x : a)
            {
                if (x >> idx & 1)
                    a0.pb(x);
                else
                    a1.pb(x);
            }
            ret += cnt_less(curr, idx - 1, a0);
            ret += cnt_less(curr, idx - 1, a1);
        }
        else
        {
            ll o = 0, t = 0;
            for (auto &x : a)
            {
                if (x >> idx & 1)
                    ++o;
                else
                    ++t;
            }
            ret += o * (o - 1);
            ret += t * (t - 1);
            map<int, vector<int>> mp;
            for (auto &x : a)
                mp[x >> (idx + 1)].pb(x);
            for (auto &x : mp)
                ret += cnt_less(curr, idx - 1, x.second);
            db(mp);
        }
        db(ret, curr, idx, a);
        return ret;
    };
    while (low <= high)
    {
        auto mid = (low + high) / 2;
        if (cnt_less(mid, 31, a) < k)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
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
        solveCase();
    return 0;
}