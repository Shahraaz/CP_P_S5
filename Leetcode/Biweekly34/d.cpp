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

int dp[201][101];
class Solution
{
public:
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        memset(dp, 0, sizeof dp);
        // queue<int> Q[fuel + 1];
        set<int> vis[fuel + 1];
        vis[fuel].insert(start);
        dp[fuel][start] = 1;
        int res = 0;
        for (int i = fuel; i >= 0; i--)
        {
            for (auto &x : vis[i])
            {
                for (size_t j = 0; j < locations.size(); j++)
                    if (x != j)
                    {
                        int temp = locations[x] - locations[j];
                        temp = abs(temp);
                        if (i - temp >= 0)
                        {
                            vis[i - temp].insert(j);
                            dp[i - temp][j] += dp[i][x];
                            if (dp[i - temp][j] >= MOD)
                                dp[i - temp][j] -= MOD;
                        }
                    }
            }
            res += dp[i][finish];
            if (res >= MOD)
                res -= MOD;
        }
        return res;
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
        ;
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif