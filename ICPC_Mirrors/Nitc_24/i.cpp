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

void solveCase(int n, int d)
{
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    using ld = long double;
    const ld PI = acosl(-1);
    ld res = 0;
    for (size_t i = 0; i < n; i++)
    {
        ld x = a[i];
        x = 180 - x / 2;
        db(x);
        x = x / 180 * PI;
        db(sinl(x));
        res += d * d * sinl(x) / 2;
    }
    cout << fixed << setprecision(3);
    cout << res << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    // for (int i = 1; i <= t; ++i)
    int n, d;
    while (cin >> n >> d)
        solveCase(n, d);
    return 0;
}