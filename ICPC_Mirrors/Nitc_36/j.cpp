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
    int n1, n2;
    cin >> n1 >> n2;
    int res = MOD;
    for (auto x : {n2 - n1, n2 + 360 - n1, n2 - 360 - n1})
    {
        if (abs(res) >= abs(x))
        {
            if (abs(x) == 180)
                res = 180;
            else
                res = x;
        }
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