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

const int NAX = 1e2 + 5, MOD = 998244353;

int ncr[NAX][NAX];
int dp[2][NAX][NAX];

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}

struct Solution
{
    Solution() {}
    void solveCase()
    {
        /*
            // f1 f2 f3 f4

            // F / f1! / f2! / f3!

            ret = dp[roomsRem][lowerLimit][totalPlayersRem]

            for curr in range(lowerLimit,totalPlayersRem):
                ret += ncr(totalPlayersRem,curr) * dp[roomsRem-1][curr][totalPlayersRem-curr]

            dp[0][0][0] = 1

            in main

            ret = x in 1 to r :
                dp_football[x][1][totalFoot]*dp_football[r - x][2][totalCrick]

        */

        int n;
        cin >> n;
        const int LIM = 100;
        ncr[0][0] = 1;
        for (int i = 1; i <= LIM; i++)
        {
            ncr[i][0] = 1;
            for (int j = 1; j <= i; j++)
                ncr[i][j] = add(ncr[i - 1][j], ncr[i - 1][j - 1]);
        }
        memset(dp, -1, sizeof dp);
        function<int(int, int)> dp_1 = [&](int players, int rooms) -> int {
            if (players == 0 && rooms == 0)
                return 1;
            if (players == 0 || rooms == 0)
                return 0;
            int &ret = dp[0][players][rooms];
            if (ret >= 0)
                return ret;
            ret = 0;
            for (int i = 1; i <= players; i++)
                ret = add(ret, mul(ncr[players][i], dp_1(players - i, rooms - 1)));
            return ret;
        };
        function<int(int, int)> dp_2 = [&](int players, int rooms) -> int {
            if (players == 0 && rooms == 0)
                return 1;
            if (players <= 1 || rooms == 0)
                return 0;
            int &ret = dp[1][players][rooms];
            if (ret >= 0)
                return ret;
            ret = 0;
            for (int i = 2; i <= players; i++)
                ret = add(ret, mul(ncr[players][i], dp_2(players - i, rooms - 1)));
            return ret;
        };
        for (size_t i = 0; i < n; i++)
        {
            int p, q, r;
            cin >> p >> q >> r;
            int res = 0;
            for (int x = 1; x < r; x++)
                res = add(res, mul(dp_1(p, x), dp_2(q, r - x)));
            cout << res << '\n';
        }
    }
};

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
