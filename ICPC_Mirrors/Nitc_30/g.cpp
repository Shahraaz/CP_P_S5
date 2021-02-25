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

void solveCase()
{
    int n;
    cin >> n;
    using ld = long double;
    vector<ld> log1010(365 * 100 + 1), fact(365 * 100 + 1);
    for (size_t i = 1; i < log1010.size(); i++)
    {
        log1010[i] = log10l(i);
        fact[i] = fact[i - 1] + log1010[i];
        // cerr << fixed << setprecision(10);
        // db(i, log1010[i], fact[i]);
    }
    ll res = 0;

    vector<ll> X(n);
    ll total = 0;
    map<int, int> mp;
    for (auto &x : X)
    {
        cin >> x;
        mp[x]++;
        total += x;
        res -= fact[x];
    }
    db(X);
    res += fact[total];

    db(res, pow(10, res));

    res -= log1010[365] * total;

    res += fact[365] - fact[n] - fact[365 - n];

    total = 0;
    for (auto &x : mp)
    {
        total += x.second;
        res -= fact[x.second];
    }
    res += fact[total];
    db(pow(10, res));
    cout << fixed << setprecision(10) << res << '\n';
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