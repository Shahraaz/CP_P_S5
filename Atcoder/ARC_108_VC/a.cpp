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
    ll s, p;
    cin >> s >> p;
    for (ll i = 1; i * i <= p; i++)
    {
        if (p % i == 0)
        {
            ll n = i;
            ll m = p / i;
            if ((n + m) == s)
            {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
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