// Optimise
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()

const int NAX = 3000 + 5, MOD = 998244353;

int dp[NAX][NAX];

int solve(int targ, int num)
{
    if (targ == 0 || num == 0)
        return targ == num;
    if (targ > num)
        return 0;
    auto &ret = dp[targ][num];
    if (ret != -1)
        return ret;
    ret = (solve(targ - 1, num - 1) + solve(2 * targ, num));
    if (ret >= MOD)
        ret -= MOD;
    return ret;
}

void solveCase()
{
    int n, k;
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    cout << solve(k, n) << '\n';
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
    {
        solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
