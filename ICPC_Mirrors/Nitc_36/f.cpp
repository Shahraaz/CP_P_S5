#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

#define all(v) v.begin(), v.end()
#define pb push_back
using ll = long long;
const int NAX = 2e5 + 5, MOD = 1000000007;

using ld = long double;

void solve()
{
    int n, p;
    cin >> n >> p;
    const int LIM = 5 * n + 1;
    ld fact[LIM], lg2[LIM];
    fact[0] = 0;
    lg2[0] = 0;
    for (int i = 1; i < LIM; ++i)
    {
        lg2[i] = log2l(i);
        fact[i] = fact[i - 1] + lg2[i];
    }
    ld ans = -MOD;
    auto nCr = [&](int n, int r) -> ld {
        // db(n, r, n - r, LIM);
        if (n < 0 || n - r < 0 || n >= LIM)
            return -MOD;
        return fact[n] - fact[n - r] - fact[r];
    };
    auto s1 = [&](int k) -> ld {
        return lg2[k] + nCr(n, p - 1) - nCr(n + k, p);
    };
    for (int i = 1; i < LIM - n; i++)
    {
        // if (s1(i) > s2(i))
        {
            // db(i, s1(i));
            ans = max(ans, s1(i));
            // ld vv = pow(2, s1(i));
            // db(i, ans, s1(i), vv);
        }
    }
    cout << fixed << setprecision(10);
    cout << pow(2, ans) << endl;
}

void solveCase()
{
    solve();
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
        solveCase();
    return 0;
}