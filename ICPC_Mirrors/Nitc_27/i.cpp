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
const int NAX = 2e5 + 5, MOD = 1000007;

void solveCase()
{
    vector<ll> inv(NAX), fact(NAX);
    inv[0] = inv[1] = fact[0] = fact[1] 1;
    for (int i = 2; i < MOD; ++i)
    {
        fact[i] = (i * fact[i - 1]) % MOD;
        if (i == 29)
        {
            for (ll j = 0; j < MOD; j++)
            {
                if ((i * j) % MOD == 1)
                {
                    db(i, j, (i * j) % MOD);
                }
            }
            db(i, inv[i], (i * inv[i]) % MOD);
            assert((i * inv[i]) % MOD == 1);
        }
        else if (i == 34483)
        {
            for (ll j = 0; j < MOD; j++)
            {
                if ((i * j) % MOD == 1)
                {
                    db(i, j, (i * j) % MOD);
                }
            }
            db(i, inv[i], (i * inv[i]) % MOD);
            assert((i * inv[i]) % MOD == 1);
        }
        else
        {
            inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
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
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}