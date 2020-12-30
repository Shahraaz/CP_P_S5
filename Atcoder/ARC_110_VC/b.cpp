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
    string t;
    cin >> t;
    string s = "";
    while (s.length() <= 3 * n)
        s += "110";
    db(s);
    ll truelen = 3;
    for (size_t i = 0; i < 10; i++)
        truelen = truelen * 10;
    db(truelen);
    db(n, t);
    ll res = 0;
    for (size_t i = 0; i < 3; i++)
        if (s.substr(i, n) == t)
        {
            int lptr = i, rptr = lptr + n - 1;
            ll t = (truelen - i - n) / 3;
            db(i, lptr, rptr, t);
            // cout << t << '\n';
            // return;
            res += t + 1;
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