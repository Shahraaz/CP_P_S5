#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;
const ll DINF = 1000000000000000000;

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

struct state {
    bool vis;
    ll dist;
    int cnt;

    bool operator <(const state &other) const {
        if (dist != other.dist) return dist < other.dist;
        if (cnt != other.cnt) return cnt < other.cnt;
        return false;
    }
} dist1[2010],
  dist2[2010];

int n;
void dijkstra(int start, state dist[]) {
    rep(i,0,n) {
        dist[i].vis = false;
    }

    priority_queue<pair<state, int>, vector<pair<state, int> >, greater<pair<state, int> > > pq;
    dist[start].vis = true;
    dist[start].dist = 0;
    dist[start].cnt = 0;
    pq.push(make_pair(dist[start], start));

    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();

        iter(it,adj[cur]) {
            state ndist;
            ndist.vis = true;
            ndist.dist = dist[cur].dist + it->second;
            ndist.cnt = dist[cur].cnt + 1;
            if (!dist[it->first].vis || ndist < dist[it->first]) {
                dist[it->first] = ndist;
                pq.push(make_pair(ndist, it->first));
            }
        }
    }
}

int main() {
    int m;
    cin >> n >> m;

    rep(i,0,m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        adj[a].push_back(ii(b,c));
        adj[b].push_back(ii(a,c));
    }

    dijkstra(0, dist1);
    dijkstra(n-1, dist2);

    vector<pair<ll,ll> > lines;
    rep(i,0,n) {

        ll dist = dist1[i].dist + dist2[i].dist,
           cnt = dist1[i].cnt + dist2[i].cnt;

        lines.push_back(make_pair(dist, cnt));
    }

    vi res;
    rep(i,0,n) {

        rat mn(-DINF),
            mx(DINF);
        bool ok = true;

        rep(j,0,n) {
            if (i == j) continue;

            ll d1 = lines[i].first,
               c1 = lines[i].second;

            ll d2 = lines[j].first,
               c2 = lines[j].second;

            if (c1 - c2 == 0) {
                ok = ok && d2 - d1 >= 0;
            }
            if (c1 - c2 > 0) {
                mx = min(mx, rat(d2 - d1, c1 - c2));
            }
            if (c1 - c2 < 0) {
                mn = max(mn, rat(d2 - d1, c1 - c2));
            }

        }

        if (!(ok && mn <= mx)) {
            res.push_back(i);
        }
    }

    cout << res.size() << endl;
    rep(i,0,res.size()) {
        if (i != 0) cout << " ";
        cout << res[i]+1;
    }
    cout << endl;

    return 0;
}

