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

struct Solution
{
    Solution() {}
    void solveCase();
};

void Solution::solveCase()
{
    ll x, k, d;
    cin >> x >> k >> d;
    // x = k = d = 1e18;
    // --k;
    // x = abs(x);
    ll t = abs(x) / d;
    db(x, t, d, k);
    if (t > k)
    {
        cout << abs(x - ((x > 0) - (x < 0)) * k * d) << '\n';
    }
    else
    {
        db(x, t, d, k);
        x = x - ((x > 0) - (x < 0)) * t * d;
        db(x);
        k -= t;
        ll y = min(abs(x + d), abs(x - d));
        if (k & 1)
            cout << y << '\n';
        else
        {
            cout << abs(x) << '\n';
        }
    }
}

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
