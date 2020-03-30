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

const int NAX = 3e2 + 5, MOD = 1000000007;

int a[NAX];
ll dp[NAX][NAX][NAX];

class Solution
{
private:
    int n, k;
    ll solve(int idx, int rem, int prev)
    {
        if (rem < 0)
            return 1e18;
        if (idx > n)
            return 0;
        ll &ans = dp[idx][rem][prev];
        if (ans >= 0)
            return ans;
        ans = 1e18;
        ans = min(solve(idx + 1, rem - 1, prev), max(0, a[idx] - a[prev]) + solve(idx + 1, rem, idx));
        return ans;
    }

public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        cin >> n >> k;
        for (size_t i = 0; i < n; i++)
            cin >> a[i + 1];
        memset(dp, -1, sizeof dp);
        cout << solve(1, k, 0) << '\n';
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