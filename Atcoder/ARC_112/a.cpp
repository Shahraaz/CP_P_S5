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
    int L, R;
    cin >> L >> R;
    ll res = 0;
    for (int dx = L; dx <= L; dx++)
    {
        ll left = L, right = R - dx;
        db(dx, left, right, right - left + 1);
        if (left <= right)
            res += (right - left + 1) * (right - left + 2) / 2;
        else
            break;
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
        solveCase();
    return 0;
}