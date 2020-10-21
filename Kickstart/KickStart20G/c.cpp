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

void solveCase()
{
    int w, n;
    cin >> w >> n;
    vector<ll> poses;
    for (size_t i = 0; i < w; i++)
    {
        int x;
        cin >> x;
        poses.pb(x);
        poses.pb(n + x);
        // poses.pb(n + x);
    }
    sort(all(poses));
    auto pref = poses;
    for (size_t i = 1; i < poses.size(); i++)
        pref[i] += pref[i - 1];
    db(poses);
    db(pref);
    ll res = LLONG_MAX;
    auto check = [&](int lptr, int rptr, int m) -> ll {
        if (m < 0)
            return LLONG_MAX;
        ll left = pref[m];
        if (lptr > 0)
            left -= pref[lptr - 1];
        ll right = pref[rptr];
        right -= pref[m];
        ll ret = poses[m] * (m - lptr + 1) - left + right - poses[m] * (rptr - m);
        db(lptr, rptr, m, ret);
        db(left, right);
        return ret;
    };
    for (int lptr = 0; lptr < w; ++lptr)
    {
        int rptr = lptr + w - 1;
        int midPtr = (lptr + rptr) / 2;
        res = min(res, check(lptr, rptr, midPtr));
        res = min(res, check(lptr, rptr, midPtr + 1));
        res = min(res, check(lptr, rptr, midPtr - 1));
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
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
