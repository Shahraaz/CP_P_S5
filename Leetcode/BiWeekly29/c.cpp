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

vector<int> adj[15];
int dp[1 << 16];
class Solution
{
    int k, n;
    int solve(int mask)
    {
        if (mask == 0)
            return 0;
        int &ret = dp[mask];
        if (ret >= 0)
            return ret;
        ret = MOD;
        for (int thisSemester = mask; thisSemester; thisSemester = (thisSemester - 1) & mask)
        {
            if (__builtin_popcount(thisSemester) > k)
                continue;
            bool ok = true;
            for (size_t i = 0; i < n; i++)
                if (thisSemester & (1 << i))
                    for (auto &pre : adj[i])
                    {
                        if (mask & (1 << pre))
                        {
                            ok = false;
                            break;
                        }
                    }
            if (ok)
                ret = min(ret, 1 + solve(mask ^ thisSemester));
        }
        return ret;
    }

public:
    int minNumberOfSemesters(int n, vector<vector<int>> &dependencies, int k)
    {
        this->k = k;
        this->n = n;
        for (auto &x : dependencies)
        {
            int u = x[0];
            int v = x[1];
            adj[u].pb(v);
        }
        memset(dp, -1, sizeof dp);
        return solve((1 << (n + 1)) - 1);
    }
};

/*
9
[[4,8],[3,6],[6,8],[7,6],[4,2],[4,1],[4,7],[3,7],[5,2],[5,9],[3,4],[6,9],[5,7]]
2
*/

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