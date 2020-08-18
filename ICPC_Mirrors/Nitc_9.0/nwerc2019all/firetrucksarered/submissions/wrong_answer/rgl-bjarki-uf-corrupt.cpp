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

struct union_find {
  vi p; union_find(int n) : p(n, -1) { }
  int find(int x) { return p[x] < 0 ? x : find(p[x]); }
  int compress(int x) { return p[x] < 0 ? x : p[x]=find(p[x]); }
  bool unite(int x, int y) {
    int xp = find(x), yp = find(y);
    if (xp == yp) return false;
    if (p[xp] > p[yp]) swap(x,y), swap(xp,yp);
    p[xp] += p[yp], p[p[y] < 0 ? y : p[y]] = xp;
    compress(y);
    return true; }
  int size(int x) { return -p[find(x)]; } };

int main() {
    int n;
    cin >> n;

    map<int, vi> rel;
    rep(i,0,n) {
        int c;
        cin >> c;
        rep(j,0,c) {
            int x;
            cin >> x;
            rel[x].push_back(i);
        }
    }

    union_find uf(n);
    vector<tuple<int,int,int> > es;
    iter(it,rel) {
        int last = -1;
        iter(jt,it->second) {
            if (last != -1 && uf.unite(*jt, last)) {
                es.push_back({ *jt, last, it->first });
            }
            last = *jt;
        }
    }

    if (uf.size(0) != n) {
        cout << "impossible" << endl;
        return 0;
    }

    for (auto [a,b,c] : es) {
        cout << a+1 << " " << b+1 << " " << c << endl;
    }

    return 0;
}

