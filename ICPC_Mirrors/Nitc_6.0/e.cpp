#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pop_b pop_back
#define pf push_front
#define pop_f pop_front

typedef long long ll;
typedef pair<ll, ll> ii;
typedef long double ld;
typedef vector<int> vi;

#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

// #define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep2(i, l, r) for (ll i = (l); i < (r); i++)
#define rep2r(i, l, r) for (ll i = (r)-1; i >= (l); i--)

ll mod = 1e9 + 7;

ll powm(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

typedef complex<double> C;
typedef vector<double> vd;
#define sz(a) a.size()
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define trav(x, a) for (auto &x : a)
#define all(x) x.begin(), x.end()

void fft(vector<C> &a)
{
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1); // (ˆ 10% f a s t e r i f double )
    for (static int k = 2; k < n; k *= 2)
    {
        R.resize(n);
        rt.resize(n);
        auto x = polar(1.0L, M_PIl / k); // M PI, lower−case L
        rep(i, k, 2 * k) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
    }
    vi rev(n);
    rep(i, 0, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k)
            rep(j, 0, k)
            {
                C z = rt[j + k] * a[i + j + k]; // (25% f a s t e r i f hand−r o l l e d )
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
}
typedef vector<ll> vl;

const int M = mod;
vl convMod(const vl &a, const vl &b)
{
    if (a.empty() || b.empty())
        return {};
    vl res(sz(a) + sz(b) - 1);
    int B = 32 - __builtin_clz(sz(res)), n = 1 << B, cut = int(sqrt(M));
    vector<C> L(n), R(n), outs(n), outl(n);
    rep(i, 0, sz(a)) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
    rep(i, 0, sz(b)) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
    fft(L), fft(R);
    rep(i, 0, n)
    {
        int j = -i & (n - 1);
        outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
        outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / C(0, 1);
    }
    fft(outl), fft(outs);
    rep(i, 0, sz(res))
    {
        ll av = ll(real(outl[i]) + .5), cv = ll(imag(outs[i]) + .5);
        ll bv = ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5);
        res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
    }
    return res;
}

ll n, k;
#undef rep
#define rep(i, n) for (ll i = 0; i < (n); i++)

ll ans(vi v)
{
    ll val = 0;
    int n = v.size();
    vector<ll> a(n), b(n);
    for (size_t i = 0; i < n; i++)
    {
        a[i] = v[i];
        b[i] = v[n - i - 1];
    }
    auto res = convMod(a, b);
    // cout << n << ' ';
    // cout << "res ";
    // for (size_t i = 0; i < res.size(); i++)
    //     cout << res[i] << ' ';
    // cout << '\n';
    for (size_t i = 0; i + 1 < v.size(); i++)
    {
        ll cur = 0;
        // for (int j = 0; i + j + 1 < v.size(); j++)
        // {
        //     cur += 1ll * v[i + j + 1] * v[j];
        //     cur %= mod;
        //     cur += mod;
        //     cur %= mod;
        // }
        // cout << cur << ' ' << res[i + n] << '\n';
        cur = res[i + n];
        val += cur * powm(i + 1, k, mod);
        val %= mod;
        val += mod;
        val %= mod;
        // cout << cur << ' ';
    }
    // cout << '\n';
    return val;
}
int main()
{
    cin >> n >> k;
    ll a[n + 1];

    rep(i, n) cin >> a[i];
    vi adj[n + 2];
    rep(i, n + 1)
        adj[i]
            .pb(-1);
    rep(i, n)
        adj[a[i]]
            .pb(i);
    rep(i, n + 1)
        adj[i]
            .pb(n);
    ll sum = 0;
    rep2(i, 1, n + 1)
    {
        vi v;
        rep(j, adj[i].size() - 1)
        {
            v.pb(adj[i][j + 1] - adj[i][j]);
        }
        sum += ans(v);
        sum %= mod;
        sum += mod;
        sum %= mod;
    }
    cout << sum << endl;
}