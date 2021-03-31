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
    int res = 0, res_p = MOD;
    for (size_t i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        string str;
        cin >> str;
        if (count(all(str), '2') >= 2 && count(all(str), '0') >= 1 && count(all(str), '1') >= 1)
        {
            if (res_p > p)
            {
                res_p = p;
                res = i + 1;
            }
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