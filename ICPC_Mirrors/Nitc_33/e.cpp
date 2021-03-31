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
const int NAX = 1e6 + 5, MOD = 1000000007;

ll freq[NAX], cnt[NAX];
pair<int, vector<int>> queries[NAX];

void solveCase()
{
    int n;
    cin >> n;
    vector<int> ranges;
    for (size_t i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        cnt[i] = 0;
        queries[i].first = t;
        if (t == 1)
        {
            int sz;
            cin >> sz;
            queries[i].second.resize(sz);
            for (auto &x : queries[i].second)
            {
                cin >> x;
                ranges.pb(x);
            }
        }
        else
        {
            queries[i].second.resize(2);
            for (auto &x : queries[i].second)
            {
                cin >> x;
                --x;
            }
        }
    }
    cnt[n - 1] = 1;
    sort(all(ranges));
    db(ranges);
    fill(freq, freq + ranges.size(), 0);
    for (int i = n - 1; i >= 0; i--)
    {
        db(i, cnt[i], queries[i]);
        if (cnt[i] == 0)
            continue;
        if (queries[i].first == 1)
        {
            for (auto &x : queries[i].second)
            {
                x = lower_bound(all(ranges), x) - ranges.begin();
                freq[x] += cnt[i];
                db(x, freq[x], cnt[i]);
            }
        }
        else
        {
            for (auto &x : queries[i].second)
                cnt[x] += cnt[i];
        }
    }
    ll tot = 0;
    for (ll i = 0; i < ranges.size(); i++)
        tot += freq[i];
    ll mx = *max_element(freq, freq + ranges.size());
    ll common = max(0ll, 2 * mx - tot);
    cout << tot - common << "\n";
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