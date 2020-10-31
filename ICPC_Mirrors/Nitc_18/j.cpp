#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pop_b pop_back
#define pf push_front
#define pop_f pop_front
#define mt make_tuple
#define eb emplace_back
#define sf(x) sizeof(x)
#define len(x) x.length()
#define sz(x) x.size()
#define fastio()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

#define LB(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define UB(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
typedef long long ll;
typedef pair<ll, ll> ii;
typedef long double ld;
typedef vector<int> vi;
typedef vector<set<ll>> vset;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef deque<ll> dql;
typedef deque<int> dqi;
typedef unsigned long long ull;
typedef tuple<int, int, int> State;

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
    cerr << *it << " = " << a << ", ";
    err(++it, args...);
    cout << "\n";
}

#define vmax(type) std::numeric_limits<type>::max()
#define vmin(type) std::numeric_limits<type>::min()
#define each(a, x) for (auto &a : (x))
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep2(i, l, r) for (ll i = (l); i < (r); i++)
#define rep2r(i, l, r) for (ll i = (r)-1; i >= (l); i--)
#define range(a) a.begin(), a.end()
#define deb(x) cout << #x << " " << x << endl;
#define cinai(a, n) \
    vi a(n);        \
    rep(i, n) { cin >> a[i]; }
#define cinal(a, n) \
    vl a(n);        \
    rep(i, n) { cin >> a[i]; }
#define coutai(a, n)                   \
    rep(i, n) { cout << a[i] << " "; } \
    ent;
#define coutal(a, n)                   \
    rep(i, n) { cout << a[i] << " "; } \
    ent;
#define ent cout << endl;
#define resize_vec(a) a.resize(unique(a.begin(), a.end()) - a.begin());
#define ms(dp, x) memset(dp, x, sf(dp))
#define endl '\n'

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

const ll mod = 1e9 + 7;
const ll N = 1000005;
const ll inf = 1e9;
vector<int> adj[N];
queue<int> Q;
vector<int> order;
int par[N];
int cnt[N];

void solve()
{
    int n;
    // cin >> n;
    scanf("%d", &n);
    vector<int> to_chk;
    for (int i = 2; i * 1LL * i <= n; i++)
        if (n % i == 0)
        {
            to_chk.pb(i);
            int next = n / i;
            if (next != i)
                to_chk.pb(next);
        }
    to_chk.pb(1);
    rep(i, n - 1)
    {
        int x, y;
        scanf("%d", &x);
        scanf("%d", &y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    Q.push(1);
    while (Q.size())
    {
        auto top = Q.front();
        Q.pop();
        order.pb(top);
        for (auto &x : adj[top])
            if (x != par[top])
            {
                Q.push(x);
                par[x] = top;
            }
    }
    reverse(range(order));
    vector<int> ans;
    rep(i, to_chk.size())
    {
        bool ok = true;
        int chk = to_chk[i];
        fill(cnt, cnt + n + 1, 1);
        for (auto &x : order)
            if (cnt[x] == chk)
                ;
            else if (cnt[x] > chk)
            {
                ok = false;
                break;
            }
            else
                cnt[par[x]] += cnt[x];
        if (ok)
            ans.pb(n / to_chk[i] - 1);
    }
    sort(range(ans));
    for (auto &x : ans)
        printf("%d ", x);
}

// #define _DEBUG
// #define testCases
signed main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    // cout << fixed << setprecision(15);
    int tc = 1;
#ifdef testCases
    cin >> tc;
#endif
    for (int t = 1; t <= tc; t++)
    {
#ifdef _DEBUG
        int tt = clock();
#endif
        // cout<<"Case #"<<t<<": ";
        solve();

#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
#endif
    }
    return 0;
}