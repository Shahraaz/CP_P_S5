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

ll l, r;

ll dp[20][2][2];
string N;

ll solve(int idx, int lowered, int bit)
{
    if (idx == N.size())
        return 1;
    auto &ret = dp[idx][lowered][bit];
    if (ret >= 0)
        return ret;
    ret = 0;
    if (lowered)
    {
        for (int i = bit; i <= N[idx] - '0'; i += 2)
            ret += solve(idx + 1, i == (N[idx] - '0'), 1 - bit);
    }
    else
    {
        for (int i = bit; i <= 9; i += 2)
            ret += solve(idx + 1, 0, 1 - bit);
    }
    db(idx, lowered, bit, ret);
    return ret;
}

ll solve(ll bound)
{
    if (bound == 0)
        return 0;
    N = to_string(bound);
    ll res = 0;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= N[0] - '0'; i += 2)
        res += solve(1, (i == (N[0] - '0')), 0);
    for (int i = 1; i <= 9; i += 2)
        for (int j = 1; j < N.size(); j++)
            res += solve(j + 1, false, 0);
    db(bound, res);
    return res;
}

void solveCase()
{
    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << '\n';
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
    {
        cout << "Case #" << i << ": ";
        solveCase();
#ifdef TIMER
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}