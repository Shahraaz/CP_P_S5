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

const int NAX = 2e5 + 5, MOD = 1000000007;

int dp[13][1 << 13];
int sum[13][1 << 13];

class Solution
{
public:
    int connectTwoGroups(vector<vector<int>> cost)
    {
        int n = cost.size();
        int m = cost[0].size();
        for (size_t i = 0; i < n; i++)
        {
            sum[i][0] = 0;
            for (size_t j = 1; j < (1 << m); j++)
                for (size_t k = 0; k < m; k++)
                    if (j & (1 << k))
                        sum[i][j] = sum[i][j ^ (1 << k)] + cost[i][k];
        }
        memset(dp, -1, sizeof dp);
        function<int(int, int)> solve = [&](int pos, int mask2) -> int {
            if (pos == n)
                return __builtin_popcount(mask2) == m ? 0 : MOD;
            int &ret = dp[pos][mask2];
            if (ret >= 0)
                return ret;
            ret = MOD;
            int inv = ((1 << m) - 1) ^ mask2;
            for (int submask = inv; submask; submask = (submask - 1) & inv)
                ret = min(ret, sum[pos][submask] + solve(pos + 1, mask2 | submask));
            for (size_t i = 0; i < m; i++)
                ret = min(ret, sum[pos][1 << i] + solve(pos + 1, mask2 | (1 << i)));
            return ret;
        };
        return solve(0, 0);
    }
};

#ifdef LOCAL
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    Solution S;
    for (int i = 1; i <= t; ++i)
    {
        cout << S.connectTwoGroups({}) << '\n';
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif