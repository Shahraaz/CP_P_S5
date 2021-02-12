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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a)
    {
        cin >> x;
        if (x == k)
        {
            cout << "POSSIBLE\n";
            return;
        }
    }
    sort(all(a));
    ll g = 0;
    for (size_t i = 1; i < n; i++)
        g = __gcd(g, a[i] - a[i - 1]);
    for (size_t i = 0; i < n; i++)
    {
        if (k <= a[i])
            if ((a[i] - k) % g == 0)
            {
                cout << "POSSIBLE\n";
                return;
            }
    }
    cout << "IMPOSSIBLE\n";
    return;
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