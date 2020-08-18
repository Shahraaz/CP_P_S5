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

int combine(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return a+b;
}

struct node {
  int l, r;
  int nn, np, pn, pp;
  node() {}
  node(int _l, int _r) : l(_l), r(_r), nn(0), np(0), pn(0), pp(0) { }
  node(int _l, int _r, int x) : node(_l,_r) {
      if (x > 0) pp = 1;
      if (x < 0) nn = 1;
  }
  node(node a, node b) : node(a.l,b.r) {
      nn = max(max(a.nn,b.nn), max(combine(a.np, b.nn), combine(a.nn, b.pn)));
      np = max(max(a.np,b.np), max(combine(a.np, b.np), combine(a.nn, b.pp)));
      pp = max(max(a.pp,b.pp), max(combine(a.pp, b.np), combine(a.pn, b.pp)));
      pn = max(max(a.pn,b.pn), max(combine(a.pp, b.nn), combine(a.pn, b.pn)));
  }
  void update() {
      pp = 1;
      nn = 1;
  }
};

struct segment_tree {
  int n;
  vector<node> arr;
  segment_tree() { }
  segment_tree(const vector<int> &a) : n(a.size()), arr(4*n) {
    mk(a,0,0,n-1); }
  node mk(const vector<int> &a, int i, int l, int r) {
    int m = (l+r)/2;
    return arr[i] = l > r ? node(l,r) :
      l == r ? node(l,r,a[l]) :
      node(mk(a,2*i+1,l,m),mk(a,2*i+2,m+1,r)); }
  node update(int at, int i=0) {
    int hl = arr[i].l, hr = arr[i].r;
    if (at < hl || hr < at) return arr[i];
    if (hl == at && at == hr) {
      arr[i].update(); return arr[i]; }
    return arr[i] =
      node(update(at,2*i+1),update(at,2*i+2)); }
  node query(int l, int r, int i=0) {
    int hl = arr[i].l, hr = arr[i].r;
    if (r < hl || hr < l) return node(hl,hr);
    if (l <= hl && hr <= r) return arr[i];
    return node(query(l,r,2*i+1),query(l,r,2*i+2)); }
};

int longest(const node &x) {
    return max(x.pp, max(x.pn, max(x.np, x.nn)));
}

int main() {
    int n;
    ll x, y;
    cin >> n >> x >> y;

    vi arr(n);
    vii changes;
    rep(i,0,n) {
        cin >> arr[i];
        if (arr[i] >= 0) changes.push_back(ii(arr[i]+1, i));
        else changes.push_back(ii(-arr[i]+1, i));
    }

    segment_tree st(arr);

    ll res = (n - longest(st.query(0,n-1))) * y;
    sort(changes.begin(), changes.end());

    iter(it,changes) {
        st.update(it->second);
        res = min(res, (n - longest(st.query(0,n-1))) * y + it->first * x);
    }

    cout << res << endl;

    return 0;
}

