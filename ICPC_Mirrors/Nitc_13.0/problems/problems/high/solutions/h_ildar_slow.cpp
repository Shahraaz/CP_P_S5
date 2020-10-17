#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector <int> pref(n);
  for (int i = 0; i < n; i++) {
    pref[i] = a[i];
    if (i) pref[i] += pref[i - 1];
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, a[i]);
  }
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t < mx) {
      cout << "Impossible\n";
      continue;
    }
    auto f = [&] (int l, int r) {
      return pref[r] - (l ? pref[l - 1] : 0);
    };
    int i = 0;
    int years = 0;
    while (i < n) {
      int l = i, r = n;
      while (l < r - 1) {
        int m = (l + r) / 2;
        if (f(i, m) <= t) {
          l = m;
        } else {
          r = m;
        }
      }
      i = r;
      years++;
    }
    cout << years << '\n';
  }
}
