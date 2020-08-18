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

const int NAX = 3000 + 5, MOD = 1000000007;

struct Solution
{
    Solution() {}
    void solveCase();
};

int grid[NAX][NAX];
ll dp[NAX][NAX][4];
int r, c;

ll solve(int ridx, int cidx, int rem)
{
    if (ridx == (r - 1) && cidx == (c - 1))
        return rem > 0 ? (grid[ridx][cidx] > 0 ? grid[ridx][cidx] : 0) : 0;
    if (ridx == r)
        return -1e18;
    if (cidx == c)
        return -1e18;
    ll &ret = dp[ridx][cidx][rem];
    if (ret >= 0)
        return ret;
    ret = -1e18;
    if (rem == 0)
        ret = max(solve(ridx + 1, cidx, 3), solve(ridx, cidx + 1, 0));
    else
    {
        ll temp = max(solve(ridx + 1, cidx, 3), solve(ridx, cidx + 1, rem));
        ret = max(ret, temp);
        temp = max(grid[ridx][cidx] + solve(ridx + 1, cidx, 3), grid[ridx][cidx] + solve(ridx, cidx + 1, rem - 1));
        ret = max(ret, temp);
    }
    return ret;
}

void Solution::solveCase()
{
    memset(dp, -1, sizeof dp);
    cin >> r >> c;
    int k;
    cin >> k;
    for (size_t i = 0; i < k; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        grid[x - 1][y - 1] = v;
    }
    cout << solve(0, 0, 3) << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
