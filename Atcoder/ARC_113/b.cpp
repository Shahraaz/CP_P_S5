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

ll power(ll b, ll idx, ll M)
{
    if (idx == 0)
        return 1;
    ll temp = power(b, idx / 2, M);
    temp = temp * temp % M;
    if (idx & 1)
        temp = temp * b % M;
    return temp;
}

void solveCase()
{
    ll a, b, c;
    // const int LIM = 5;
    // for (size_t a = 1; a < LIM; a++)
    //     for (size_t b = 1; b < LIM; b++)
    //         for (size_t c = 1; c < LIM; c++)
    {
        cin >> a >> b >> c;
        auto res = powl(a, powl(b, c));
        // b = power(b, c, 4);
        // a = power(a, b, 10);
        // cout << a << '\n';
        ll temp = power(b, c, 4);
        if (temp == 0)
            temp = 4;
        db(a, b, c, res, power(a, temp, 10));
        cout << power(a, temp, 10) << '\n';
        // db(a, b, c, res, power(b, c, 4));
    } // for (size_t i = 0; i < 10; i++)
    // {
    //     set<int> ss;
    //     for (size_t j = 1; j < 100; j++)
    //     {
    //         auto p = power(i, j, 10);
    //         db(i, j, p);
    //         if (ss.count(p))
    //             break;
    //         ss.insert(p);
    //     }
    //     db(i, ss.size(), ss);
    // }
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