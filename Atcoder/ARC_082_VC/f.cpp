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
    ll X, k;
    cin >> X >> k;
    vector<pair<ll, int>> events;
    for (size_t i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        events.pb({x, -1});
    }
    int q;
    cin >> q;
    vector<ll> Q(q);
    for (size_t i = 0; i < q; i++)
    {
        ll t, a;
        cin >> t >> a;
        Q[i] = a;
        events.pb({t, i});
    }
    sort(all(events));
    vector<ll> As = Q;
    sorta(all(As));
    vector<ll> base_array = As;
    int firstidxwhichiszero = -1;
    int prevtime = 0;
    vector<int> res(q);
    bool dir = 0;
    auto pass_time = [&](int dt) -> void {
        if (!dir)
        {
            
        }
    };
    for (auto &x : events)
    {
        pass_time(x.first - prevtime);
        prevtime = x.first;
        if (x.second == -1)
        {
            flip();
            continue;
        }
        auto idx = lower_bound(all(As), Q[x.second]) - As.begin();
        res[x.second] = get_val(idx);
    }
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