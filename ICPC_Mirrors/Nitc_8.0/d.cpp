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

const int NAX = 8, MOD = 1000000007;

int dp[NAX][NAX][NAX];
struct Solution
{
    Solution() {}
    void solveCase()
    {
        /*
            | val | ri | ri | | |
            |  d  | rd |    | 
            |     |    | 

            l       r
            x x x x y y y y y 
                    y+1
            // 1 1 1 1 -- x1 1 2 2 2 2 x2 2 
            x[] = {x1,x2,x3,--- xn};
            y[] = {y1,y2,y3,--- yn};

            

            for all i:
                X_sum[i] >= Y_sum[i]

            x+1 to y+1
            no of increasing arrays of size r - l + 1:
                x+1 to y+1

            dp[i][j][x] = pos i , j pe has value == x
            dp[i][j][x] = dp[i+1][j][x+1] + dp[i][j+1][x] - 
            for down from (x+1) to k:
                for right from x to k:
                    for rightdown from 1 to min(right+1,down) - 1:
                        dp[i][j][x] += dp[i+1][j][down] + dp[i][j+1][right] - dp[i+1][j+1][rightdown]
            
        */
        int k;
        while (cin >> k)
        {
            memset(dp, -1, sizeof dp);
            vector<int> l(k);
            for (auto &x : l)
                cin >> x;
            int n;
            cin >> n;
            auto isValid = [&](int x, int y) {
                return 0 <= x && x < k && 0 <= y && y < l[x];
            };
            function<int(int, int, int)> solve = [&](int x, int y, int val) -> int {
                int temp = isValid(x + 1, y) + isValid(x, y + 1);
                if (val > n)
                    return 0;
                if (temp == 0)
                    return 1;
                int &ret = dp[x][y][val];
                if (ret >= 0)
                    return ret;
                ret = 0;
                if (temp == 2)
                {
                    if (!isValid(x + 1, y + 1))
                    {
                        for (int right = val; right <= n; right++)
                            for (int down = val + 1; down <= n; down++)
                                ret += solve(x + 1, y, down) * solve(x, y + 1, right);
                    }
                    else
                    {
                        for (int right = val; right <= n; right++)
                            for (int down = val + 1; down <= n; down++)
                                ret += solve(x + 1, y, down) * solve(x, y + 1, right);
                    }
                }
                else if (isValid(x + 1, y))
                {
                    for (int down = val + 1; down <= n; down++)
                        ret += solve(x + 1, y, down);
                }
                else
                {
                    for (int right = val; right <= n; right++)
                        ret += solve(x, y + 1, right);
                }
                return ret;
            };
            int ret = 0;
            for (size_t i = 1; i <= n; i++)
                ret += solve(0, 0, i);
            cout << ret << '\n';
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
