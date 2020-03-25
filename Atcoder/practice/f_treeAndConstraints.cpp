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

int n;
int dp[55][55];

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        cin >> n;
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < n; j++)
            {
                if (i == j)
                    dp[i][j] = 0;
                else
                    dp[i][j] = MOD;
            }
        int a[55], b[55];
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a[i] >> b[i];
            --a[i], --b[i];
            dp[a[i]][b[i]] = 1;
            dp[b[i]][a[i]] = 1;
        }
        for (size_t k = 0; k < n; k++)
            for (size_t i = 0; i < n; i++)
                for (size_t j = 0; j < n; j++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                    // db(i, j, dp[i][j]);
                }
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < n; j++)
            {
                // dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                db(i, j, dp[i][j]);
            }
        int m;
        cin >> m;
        int u[22], v[22];
        for (size_t i = 0; i < m; i++)
        {
            cin >> u[i] >> v[i];
            --u[i], --v[i];
        }
        ll e[22] = {};
        memset(e, 0, sizeof e);
        for (size_t i = 0; i < m; i++)
        {
            db(u[i], v[i], dp[u[i]][v[i]]);
            for (int j = 0; j < n - 1; j++)
            {
                db(a[j], dp[u[i]][a[j]], dp[v[i]][a[j]]);
                if (dp[u[i]][v[i]] == dp[u[i]][a[j]] + dp[v[i]][a[j]])
                {
                    db(b[j], dp[u[i]][b[j]], dp[v[i]][b[j]]);
                    if (dp[u[i]][v[i]] == dp[u[i]][b[j]] + dp[v[i]][b[j]])
                    {
                        db(i, j, e[i]);
                        e[i] |= 1LL << j;
                        db(i, j, e[i]);
                    }
                }
            }
            db(i, e[i], u[i], v[i]);
        }
        ll ans = 0;
        for (size_t i = 0; i < (1 << m); i++)
        {
            ll b1 = 0;
            for (size_t j = 0; j < m; j++)
                if (i & (1LL << j))
                    b1 |= e[j];
            int c = __builtin_popcountll(b1);
            int c1 = __builtin_popcountll(i);
            if (c1 & 1)
                ans -= 1LL << (n - 1 - c);
            else
                ans += 1LL << (n - 1 - c);
        }
        cout << ans << '\n';
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