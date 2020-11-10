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
#define int ll

void solveCase()
{
    int n;
    cin >> n;
    ll x;
    cin >> x;
    vector<ll> a(n);
    for (size_t i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> req(n);
    for (size_t i = 0; i + 1 < n; i++)
        req[i] = a[i + 1] / a[i];
    vector<ll> X(n);
    for (int i = n - 1; i >= 0; i--)
    {
        X[i] = x / a[i];
        x %= a[i];
    }
    vector<vector<int>> dp(n, vector<int>(2, -1));
    function<int(int, int)> solve = [&](int idx, int carry) -> int {
        if (idx == n)
            return carry == false;
        auto &ret = dp[idx][carry];
        if (ret >= 0)
            return ret;
        int now = X[idx] + carry;
        if (now == 0)
            ret = solve(idx + 1, 0);
        else if (now == req[idx])
            ret = solve(idx + 1, 1);
        else
            ret = solve(idx + 1, 1) + solve(idx + 1, 0);
        db(__LINE__, idx, carry, ret);
        return ret;
    };
    cout << solve(0, 0) << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
