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
    ll curr_a = 1;
    for (size_t a = 0;; a++)
    {
        ll b = 0, curr_b = n - curr_a;
        if (curr_b <= 0)
            break;
        while (curr_b % 5 == 0)
        {
            curr_b /= 5;
            ++b;
        }
        if (curr_b == 1 && a > 0 && b > 0)
        {
            cout << a << ' ' << b << '\n';
            return;
        }
        if (curr_a * 3.0 >= LLONG_MAX)
            break;
        curr_a = curr_a * 3;
    }
    cout << -1 << '\n';
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