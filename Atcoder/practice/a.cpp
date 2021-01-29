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
const int NAX = 2e5 + 5, MOD = 998244353;

inline int add(int a, int b, int m = MOD)
{
    a += b;
    if (a >= m)
        a -= m;
    return a;
}

inline int sub(int a, int b, int m = MOD)
{
    a -= b;
    if (a < 0)
        a += m;
    return a;
}

inline int mul(int a, int b, int m = MOD)
{
    return (a * 1LL * b) % m;
}

const int N = 1e6 + 5;
int fact[N], ifact[N], inv[N], s[N], wd[N];

void pre()
{
    inv[1] = fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
    for (ll i = 2; i < N; i++)
    {
        inv[i] = mul(MOD - MOD / i, inv[MOD % i], MOD);
        fact[i] = mul(i, fact[i - 1], MOD);
        ifact[i] = mul(inv[i], ifact[i - 1], MOD);
    }
    return;
}

void solveCase()
{
    pre();

    for (int i = 1; i < N; i++)
    {
        wd[i] = add(wd[i], inv[i]);
        for (int j = 2 * i; j < N; j += i)
            wd[j] = sub(wd[j], wd[i]);
    }

    int n;
    cin >> n;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s[x] = add(s[x], x);
        ans = sub(ans, x);
    }

    for (int i = 1; i < N; i++)
    {
        int x = 0;
        for (int j = i; j < N; j += i)
            x = add(x, s[j]);
        ans = add(ans, mul(x, mul(x, wd[i])));
    }

    ans = mul(ans, inv[2]);

    cout << ans << '\n';
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