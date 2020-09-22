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

int n;
vector<ll> inp, pref;

map<ll, int> cache;

int check(ll sum)
{
    auto it = cache.find(sum);
    if (it != cache.end())
        return it->s;
    ll curr = 0;
    int i = 0;
    int ret = 0;
    while (i < n)
    {
        ll prev = (i > 0) ? (pref[i - 1]) : 0;
        ll next = prev + sum;
        int j = upper_bound(all(pref), next) - pref.begin();
        ret++;
        i = j;
    }
    db(sum, ret);
    return cache[sum] = ret;
}

void solveCase()
{
    cin >> n;
    inp.resize(n);
    for (auto &x : inp)
        cin >> x;
    pref = inp;
    for (size_t i = 1; i < n; i++)
        pref[i] += pref[i - 1];
    vector<pair<ll, int>> vecc;
    ll maxi = accumulate(all(inp), 0LL);
    ll mini = *max_element(all(inp));
    vecc.pb({mini - 1, MOD});
    int target = check(mini);
    db(inp);
    while (target > 1)
    {
        ll low = mini, high = maxi;
        ll ans = low;
        while (low <= high)
        {
            ll mid = ((__int128_t)low + high) / 2;
            if (check(mid) >= target)
            {
                low = mid + 1;
                // if (check(mid) == target)
                ans = max(ans, mid);
            }
            else
            {
                high = mid - 1;
            }
        }
        if (check(ans) == target)
            vecc.pb({ans, target});
        mini = ans + 1;
        target = check(mini);
    }
    db(vecc);
    int q;
    cin >> q;
    while (q--)
    {
        ll l;
        cin >> l;
        auto it = lower_bound(all(vecc), make_pair(l, 0));
        if (it->s == MOD)
            cout << "Impossible\n";
        else
            cout << it->s << '\n';
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
    {
        solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
