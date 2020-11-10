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

void solveCase()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<ll>> dp(n, vector<ll>(4, -1));
    function<ll(int, int)> solve = [&](int idx, int cidx) -> ll {
        if (idx == (n - 1))
            return 0;
        auto &ret = dp[idx][cidx];
        if (ret >= 0)
            return ret;
        ret = MOD;
        for (int j = 0; j < 4; j++)
        {
            if (a[idx] < a[idx + 1])
                ret = min(ret, (cidx >= j) + solve(idx + 1, j));
            else if (a[idx] == a[idx + 1])
                ret = min(ret, (cidx != j) + solve(idx + 1, j));
            else if (a[idx] > a[idx + 1])
                ret = min(ret, (cidx <= j) + solve(idx + 1, j));
        }
        db(idx, cidx, ret);
        return ret;
    };
    cout << min({solve(0, 0),
                 solve(0, 1),
                 solve(0, 2),
                 solve(0, 3)})
         << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
