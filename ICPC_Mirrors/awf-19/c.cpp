#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define deb(x) cout << #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define setbits(n) __builtin_popcountll(n)
#define mkunique(a) a.resize(unique(a.begin(), a.end()) - a.begin()); //need to sort
#define print(s)          \
    for (ll u : s)        \
        cout << u << " "; \
    cout << "\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

const int kmod = 1000000007;

int mul(int a, int b, int mod = kmod)
{
    return (long long)a * b % mod;
}

int add(int a, int b, int mod = kmod)
{
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b, int mod = kmod)
{
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int power(int base, int index, int mod = kmod)
{
    if (index == 0)
        return 1;
    int temp = power(base, index / 2, mod);
    temp = mul(temp, temp, mod);
    if (index & 1)
        temp = mul(temp, base, mod);
    return temp;
}

int mod_inv(int x, int mod = kmod)
{
    return power(x, mod - 2, mod);
}

// const int _n = 2e5 + 10;
// vector<int> Fact(_n), Inv(_n);

// void pre()
// {
//     Fact[0] = 1;
//     for (int i = 1; i < _n; ++i)
//         Fact[i] = mul(Fact[i - 1], i);
//     Inv[_n - 1] = mod_inv(Fact[_n - 1]);
//     for (int i = _n - 2; i >= 0; --i)
//         Inv[i] = mul(Inv[i + 1], (1 + i));
// }

// int ncr(int n, int r)
// {
//     if (n < 0 || r < 0 || n - r < 0)
//         return 0;
//     return mul(Fact[n], mul(Inv[r], Inv[n - r]));
// }

// int npr(int n, int r)
// {
//     if (n < 0 || r < 0 || n - r < 0)
//         return 0;
//     return mul(Fact[n], Inv[n - r]);
// }

ll mpow(ll x, ll y)
{
    ll res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

ll modInv(ll n)
{
    return mpow(n, mod - 2);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll TT = clock();

    ll t = 20;

    // cin >> t;
    cout << t << '\n';

    while (t--)
    {
        ll n = 1e6, s, t;
        t = rand() % int(1e9) + 10;
        s = rand() % t;
        // cin >> n >> s >> t;
        ll p = s * modInv(t) % mod;
        ll pn = p * modInv(n) % mod;
        // db(n, s, t, p, pn);
        cout << n << ' ' << s << ' ' << t << '\n';
        continue;
        pair<int, int> v;
        v = {0, 0};
        for (int i = n - 1; i >= 0; i--)
        {
            pair<ll, ll> u;
            int temp = add(sub(1, p), mul(pn, n - i - 1));
            u.ff = mul(temp, v.ff);
            u.ss = mul(temp, v.ss);

            u.ff = (u.ff + 1) % mod;
            u.ss = (u.ss + pn) % mod;
            ll num = mul(n, modInv(sub(n, mul(p, i))));

            u.ff = mul(u.ff, num);
            u.ss = mul(u.ss, num);

            v = u;
            db(i, temp, v);
        }
        // cout << v.ff << " " << v.ss << " ";
        cout << v.ff * modInv((1 - v.ss + mod) % mod) % mod << "\n";
        cout.flush();
    }

    cerr << "\n\nTIME: " << (long double)(clock() - TT) / CLOCKS_PER_SEC << " sec\n";
    TT = clock();
    return 0;
}