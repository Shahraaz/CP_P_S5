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

inline ll add(ll a, ll b, ll m = MOD)
{
    a += b;
    if (a >= m)
        a -= m;
    return a;
}
inline ll sub(ll a, ll b, ll m = MOD)
{
    a -= b;
    if (a < 0)
        a += m;
    return a;
}
inline int mul(int a, int b, int m = MOD) { return (a * 1LL * b) % m; }
// const ll MOD = 1e9 + 7;

// int power(int base, int index, int mod = MOD)
// {
//     if (index == 0)
//         return 1;
//     int temp = power(base, index / 2, mod);
//     temp = mul(temp, temp, mod);
//     if (index & 1)
//         temp = mul(temp, base, mod);
//     return temp;
// }

const int N = 2e5 + 5;
ll fact[N], ifact[N], inv[N];

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

ll nCr(ll n, ll r)
{
    if (n < 0 || n < r)
        return 0;
    return mul(fact[n], mul(ifact[r], ifact[n - r], MOD), MOD);
}

const int K = 301;
int f[K];
int sub_idx[NAX];

void solveCase()
{
    int n = 2e5, k = 300;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> pow_cache(n, 1);
    vector<int> pow2_cache(n, 1);
    db(n, k);
    for (auto &x : a)
        cin >> x;
    // db(a);
    pre();
    for (size_t j = 0; j <= k; j++)
    {
        for (size_t i = 0; i < n; i++)
        {
            f[j] = add(f[j], mul(ifact[j], pow_cache[i]));
            sub_idx[j] = add(sub_idx[j], pow2_cache[i]);

            pow_cache[i] = mul(pow_cache[i], a[i]);
            pow2_cache[i] = mul(pow2_cache[i], mul(2, a[i]));
        }
        // db(j, f[j], sub_idx[j]);
    }
    for (int j = 1; j <= k; j++)
    {
        int ans = 0;
        for (int i = 0; i <= j; i++)
        {
            ans = add(ans, mul(f[i], f[j - i]));
        }
        ans = mul(fact[j], ans);
        ans = sub(ans, sub_idx[j]);
        ans = mul(ans, inv[2]);
        cout << ans << '\n';
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