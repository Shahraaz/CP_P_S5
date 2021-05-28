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
    int n, l, r;
    cin >> n >> l >> r;
    --l, --r;

    vector<int> a(n);
    int al = 0;
    for (auto &x : a)
    {
        cin >> x;
        al ^= x;
    }
    a.pb(al);

    if (r - l + 1 >= (n + 1))
    {
        cout << *max_element(all(a)) << '\n';
        return;
    }
    int res = 0;
    for (size_t i = l; i <= r; i++)
        res = max(res, a[i % (n + 1)]);
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