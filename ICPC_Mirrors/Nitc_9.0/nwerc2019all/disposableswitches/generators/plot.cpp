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

int main() {
    memset(mem,-1,sizeof(mem));

    int m;
    cin >> n >> m;

    vector<pair<ii,int> > es;
    rep(i,0,m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        adj[a].push_back(ii(b,c));
        adj[b].push_back(ii(a,c));
        es.push_back(make_pair(ii(a,b),c));
    }

    vector<pair<int,ll> > lines;
    rep(k,0,n) {
        ll mn = dp(0, k);
        if (mn == DINF) continue;
        lines.push_back(make_pair(k, mn));
    }

    set<rat> check;
    check.insert(0LL);

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
            check.insert(lo);
            // Unnecessary: if (!inf) check.insert(hi);
            // Unnecessary: if (!inf) check.insert((lo+hi) * rat(1,2));
        }
    }

    vector<bool> safe(n, true),
                 safeedge(m, true);
    iter(it,check) {
        priority_queue<pair<rat,int>, vector<pair<rat,int> >, greater<pair<rat,int> > > pq;
        vector<rat> dist(n);
        vector<bool> reached(n);
        pq.push(make_pair(rat(0,1), 0));
        reached[0] = true;
        dist[0] = rat(0,1);

        while (!pq.empty()) {
            pair<rat,int> cur = pq.top();
            pq.pop();
            if (dist[cur.second] != cur.first) {
                continue;
            }

            iter(jt,adj[cur.second]) {
                rat ndist = cur.first + jt->second + *it;
                if (!reached[jt->first] || ndist < dist[jt->first]) {
                    reached[jt->first] = true;
                    dist[jt->first] = ndist;
                    pq.push(make_pair(ndist, jt->first));
                }
            }
        }

        vector<rat> distrev(n);
        vector<bool> reachedrev(n);
        pq.push(make_pair(rat(0,1), n-1));
        reachedrev[n-1] = true;
        distrev[n-1] = rat(0,1);

        while (!pq.empty()) {
            pair<rat,int> cur = pq.top();
            pq.pop();
            if (distrev[cur.second] != cur.first) {
                continue;
            }

            iter(jt,adj[cur.second]) {
                rat ndistrev = cur.first + jt->second + *it;
                if (!reachedrev[jt->first] || ndistrev < distrev[jt->first]) {
                    reachedrev[jt->first] = true;
                    distrev[jt->first] = ndistrev;
                    pq.push(make_pair(ndistrev, jt->first));
                }
            }
        }

        rep(i,0,n) {
            assert(reached[i] && reachedrev[i]);
            if (dist[i] + distrev[i] == dist[n-1]) {
                safe[i] = false;
            }
        }
        rep(i,0,m) {
            int a = es[i].first.first,
                b = es[i].first.second,
                c = es[i].second;
            rat mn = min(dist[a] + c + distrev[b] + *it,
                        dist[b] + c + distrev[a] + *it);
            if (mn == dist[n-1]) {
                safeedge[i] = false;
            }
        }
    }

    cout << "graph {" << endl;
    cout << "graph  [overlap=false];" << endl;
    rep(i,0,n) {
        cout << i+1 << "[";
        if (i == 0) {
            cout << "color=green";
        } else if (i == n-1) {
            cout << "color=red";
        } else if (safe[i]) {
            cout << "style=dashed";
        } else {

        }
        cout << "];" << endl;
    }
    rep(i,0,m) {
        int a = es[i].first.first,
            b = es[i].first.second,
            c = es[i].second;
        cout << a+1 << " -- " << b+1 << " [";

        bool first = true;

        if (m < 100) {
            if (!first) cout << ",";
            first = false;
            cout << "label=" << c;
        }
        if (safeedge[i]) {
            if (!first) cout << ",";
            first = false;
            cout << "style=dashed";
        }
        cout << "];" << endl;
    }
    cout << "}" << endl;

    return 0;
}

