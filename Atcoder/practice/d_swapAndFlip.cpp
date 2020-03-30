// Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define MULTI_TEST
#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#define pc(...)
#endif

#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()
auto TimeStart = chrono::steady_clock::now();
auto seed = TimeStart.time_since_epoch().count();
std::mt19937 rng(seed);
using ll = long long;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using Random = std::uniform_int_distribution<T>;

const int NAX = 2e5 + 5, MOD = 1000000007;

const int sz = 20;

int dp[1 << sz][sz];
int a[sz], b[sz];

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int n;
        cin >> n;
        for (size_t i = 0; i < n; i++)
            cin >> a[i];
        for (size_t i = 0; i < n; i++)
            cin >> b[i];
        memset(dp, -1, sizeof dp);
        for (size_t i = 0; i < n; i++)
            dp[1 << i][i] = 0;
        for (int mask = 1; mask < (1 << n); mask++)
        {
            int c = __builtin_popcount(mask);
            for (int i = 0; i < n; i++)
            {
                if (!(mask >> i & 1) || dp[mask][i] == -1)
                    continue;
                int w = (i % 2) == (c % 2) ? b[i] : a[i];
                int cost = c;
                for (int j = 0; j < n; j++)
                    if (mask >> j & 1)
                        cost--;
                    else
                    {
                        int v = j % 2 == c % 2 ? a[j] : b[j];
                        if (w <= v)
                        {
                            int vl = dp[mask][i] + cost;
                            if (dp[mask | 1 << j][j] == -1 || dp[mask | 1 << j][j] > vl)
                                dp[mask | 1 << j][j] = vl;
                        }
                    }
            }
        }
        int ret = -1;
        for (int i = 0; i < n; i++)
            if (dp[(1 << n) - 1][i] != -1)
                if (ret == -1 || ret > dp[(1 << n) - 1][i])
                    ret = dp[(1 << n) - 1][i];
        cout << ret << '\n';
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}