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
    ll n;
    cin >> n;
    ll g = 0;
    for (ll i = 2; i <= 30; i++)
    {
        if (g == 0)
            g = i;
        else
            g = g * i / __gcd(g, i);
    }
    ++g;
    assert(g <= ll(1e13));
    for (ll i = 2; i <= 30; i++)
    {
        assert(g % i == 1);
    }
    cout << g + 1 << '\n';
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