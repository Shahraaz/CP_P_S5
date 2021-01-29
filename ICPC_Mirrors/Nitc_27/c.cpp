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
const int NAX = 200 + 5, MOD = 1000000007;

int n;
string s;
int dp[NAX][NAX][NAX];

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

/*

A 1 2 3 4 
S 1 2 3 4 5 6 7 8
*/

int solve(int pos, int lptr, int rptr)
{
    int remcnt = rptr - lptr + 1;
    if (pos == n)
    {
        db(pos, lptr, rptr, remcnt);
        return remcnt <= 0;
    }
    int &ret = dp[pos][lptr][rptr];
    if (ret >= 0)
        return ret;
    ret = 0;
    if (remcnt > 0)
    {
        for (char c = 0; c < 26; c++)
        {
            if (c == s[lptr] - 'A')
            {
                if (c == s[rptr] - 'A')
                    ret = add(ret, solve(pos + 1, lptr + 1, rptr - 1));
                else
                    ret = add(ret, solve(pos + 1, lptr + 1, rptr));
            }
            else if (c == s[rptr] - 'A')
                ret = add(ret, solve(pos + 1, lptr, rptr - 1));
            else
                ret = add(ret, solve(pos + 1, lptr, rptr));
        }
    }
    else
    {
        for (char c = 0; c < 26; c++)
        {
            // if (c == s[lptr] - 'A')
            // {
                // if (c == s[rptr] - 'a')
                //     ret = add(ret, solve(pos + 1, lptr + 1, rptr - 1));
                // else
                //     ret = add(ret, solve(pos + 1, lptr + 1, rptr));
            // }
            // else if (c == s[rptr] - 'A')
            // {
            //     // ret = add(ret, solve(pos + 1, lptr, rptr - 1));
            // }
            // else
                ret = add(ret, solve(pos + 1, lptr, rptr));
        }
    }
    db(pos, lptr, rptr, ret);
    return ret;
}

void solveCase()
{
    cin >> n >> s;
    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }
    s += '$';
    s += '$';
    memset(dp, -1, sizeof dp);
    int res = solve(0, 0, n - 1);
    s.pop_back();
    s.pop_back();
    s += s;
    // auto srev = s;
    // reverse(all(srev));
    // if (s == srev)
    //     res++;
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