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

int n;
ll a[NAX], cache[NAX][4];
bool vis[NAX][4];

class Solution
{
private:
    ll dp(int idx, int have)
    {
        if (idx > n)
        {
            if (have <= 1)
                return 0;
            return -1e18;
        }
        auto &ret = cache[idx][have];
        if (vis[idx][have])
            return ret;
        vis[idx][have] = true;
        if (!have)
            ret = a[idx] + dp(idx + 2, have);
        else
            ret = max(a[idx] + dp(idx + 2, have), dp(idx + 1, have - 1));
        return ret;
    }

public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        cin >> n;
        for (size_t i = 0; i < n; i++)
            cin >> a[i + 1];
        ll ans = 0;
        if (n % 2)
            ans = max(dp(1, 2), dp(2, 1));
        else
            ans = max(dp(1, 1), dp(2, 0));
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
