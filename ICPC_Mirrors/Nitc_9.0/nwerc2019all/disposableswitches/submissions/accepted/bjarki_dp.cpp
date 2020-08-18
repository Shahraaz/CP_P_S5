#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const ll DINF = 1000000000000000000LL;

template <class T> struct fraction {
  T gcd(T a, T b) { return b == T(0) ? a : gcd(b, a % b); }
  T n, d;
  fraction(T n_=T(0), T d_=T(1)) {
    assert(d_ != 0);
    n = n_, d = d_;
    if (d < T(0)) n = -n, d = -d;
    T g = gcd(abs(n), abs(d));
    n /= g, d /= g; }
  fraction(const fraction<T>& other)
    : n(other.n), d(other.d) { }
  fraction<T> operator +(const fraction<T>& other) const {
    return fraction<T>(n * other.d + other.n * d,
                       d * other.d);}
  fraction<T> operator -(const fraction<T>& other) const {
    return fraction<T>(n * other.d - other.n * d,
                       d * other.d); }
  fraction<T> operator *(const fraction<T>& other) const {
    return fraction<T>(n * other.n, d * other.d); }
  fraction<T> operator /(const fraction<T>& other) const {
    return fraction<T>(n * other.d, d * other.n); }
  bool operator <(const fraction<T>& other) const {
    return n * other.d < other.n * d; }
  bool operator <=(const fraction<T>& other) const {
    return !(other < *this); }
  bool operator >(const fraction<T>& other) const {
    return other < *this; }
  bool operator >=(const fraction<T>& other) const {
    return !(*this < other); }
  bool operator ==(const fraction<T>& other) const {
    return n == other.n && d == other.d; }
  bool operator !=(const fraction<T>& other) const {
    return !(*this == other); } };

typedef fraction<ll> rat;

vii adj[2010];
ll mem[2010][2010];
bool safe[2010],
     vis[2010][2010];

int n;
ll dp(int at, int k) {
    if (k == 0) {
        return at == n-1 ? 0 : DINF;
    }
    if (mem[at][k] != -1) {
        return mem[at][k];
    }

    ll mn = DINF;
    iter(it,adj[at]) {
        mn = min(mn, it->second + dp(it->first, k-1));
    }
    return mem[at][k] = mn;
}

void bt(int at, int k) {
    safe[at] = false;
    if (k == 0) {
        assert(at == n-1);
        return;
    }

    ll mn = dp(at, k);
    iter(it,adj[at]) {
        if (mn == it->second + dp(it->first, k-1)) {
            bt(it->first, k-1);
        }
    }
}

int main() {
    memset(mem,-1,sizeof(mem));
    memset(vis,0,sizeof(vis));

    int m;
    cin >> n >> m;
    rep(i,0,n) safe[i] = true;

    rep(i,0,m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        adj[a].push_back(ii(b,c));
        adj[b].push_back(ii(a,c));
    }

    vector<pair<int,ll> > lines;
    rep(k,0,n) {
        ll mn = dp(0, k);
        if (mn == DINF) continue;
        lines.push_back(make_pair(k, mn));
    }

    stack<ii> S;
    rep(i,0,lines.size()) {
        rat lo(0,1), hi(0,1);
        bool inf = true;

        rep(j,0,lines.size()) {
            if (i == j) continue;
            ll a = lines[i].first - lines[j].first,
               b = lines[j].second - lines[i].second;

            if (a > 0) {
                // c <= b / a
                if (inf) hi = rat(b,a);
                else hi = min(hi, rat(b,a));
                inf = false;
            } else if (a < 0) {
                // c >= b / a
                lo = max(lo, rat(b,a));
            }
        }

        if (!(!inf && hi < lo)) {
            assert(lo >= 0);
            S.push(ii(0, lines[i].first));
        }
    }

    while (!S.empty()) {
        int at = S.top().first,
            k = S.top().second;
        S.pop();

        safe[at] = false;
        if (k == 0) {
            assert(at == n-1);
            continue;
        }

        ll mn = dp(at, k);
        iter(it,adj[at]) {
            if (!vis[it->first][k-1] && mn == it->second + dp(it->first, k-1)) {
                S.push(ii(it->first, k-1));
                vis[it->first][k-1] = true;
            }
        }
    }

    int cnt = 0;
    rep(i,0,n) if (safe[i]) cnt++;
    cout << cnt << endl;
    bool first = true;
    rep(i,0,n) {
        if (safe[i]) {
            if (!first) cout << " ";
            first = false;
            cout << i+1;
        }
    }
    cout << endl;

    return 0;
}

