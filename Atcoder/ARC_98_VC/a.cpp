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
    string str;
    cin >> str;
    int ER = count(all(str), 'E'), WR = n - ER;
    int EL = 0, WL = 0;
    int res = MOD;
    for (size_t i = 0; i < n; i++)
    {
        if (str[i] == 'E')
            ER--;
        else
            WR--;
        res = min(res, ER + WL);
        if (str[i] == 'E')
            EL++;
        else
            WL++;
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