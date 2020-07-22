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

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep2(i, l, r) for (ll i = (l); i < (r); i++)
#define rep2r(i, l, r) for (ll i = (r)-1; i >= (l); i--)

void solve()
{
    ll n, a, b, c, d, p, q, y;
    cin >> n >> a >> b >> c >> d >> p >> q >> y;
    ll x[n];
    rep(i, n) cin >> x[i];
    a--, b--, c--, d--;
    ll ans = (x[b] - x[a]) * p;
    if ((abs(x[a] - x[c])) * p < y)
    {
        ans = min(ans, (ll)(y + (abs(x[c] - x[d])) * q + (abs(x[d] - x[b])) * p));
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}