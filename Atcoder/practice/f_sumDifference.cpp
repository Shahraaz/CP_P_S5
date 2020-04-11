#include <bits/stdc++.h>

using namespace std;
using ll = long long;
 
#define rep(i, n)      for (int i = 0; i < (n); i++)
#define repr(i, n)     for (int i = (n) - 1; i >= 0; i--)
#define repe(i, l, r)  for (int i = (l); i < (r); i++)
#define reper(i, l, r) for (int i = (r) - 1; i >= (l); i--)
#define repi(i, l, r)  for (int i = (l); i <= (r); i++)
#define repir(i, l, r) for (int i = (r); i >= (l); i--)
#define range(a) a.begin(), a.end()
void initio() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); }

ll count(vector<pair<ll, ll>> a) {
  const int n = a.size();
  vector<pair<ll, int>> events;
  rep(i, a.size()) {
    events.emplace_back(a[i].first, i);
    events.emplace_back(a[i].second, i + n);
  }
  sort(range(events));
  ll res = 0;
  int cnt = 0;
  ll prev = 0;
  for (auto kv : events) {
    if (kv.second < n) {
      if (cnt == 0) {
        prev = kv.first;
      }
      cnt++;
    } else {
      cnt--;
      if (cnt == 0) {
        res += kv.first - prev;
      }
    }
  }
  return res;
}

ll floordiv(ll n, ll d) {
  if (n >= 0) return n / d;
  return (n - d + 1) / d;
}

int main() { initio();
  ll N, X, D; cin >> N >> X >> D;
  map<ll, vector<pair<ll, ll>>> mp;
  if (D == 0) {
    if (X == 0) {
      cout << 1 << endl;
      return 0;
    }
    cout << N + 1 << endl;
    return 0;
  }
  if (D < 0) {
    X *= -1;
    D *= -1;
  }
  mp[0].emplace_back(0, 1);
  for (ll i = 1; i <= N; i++) {
    // 0 + 1 + 2 + ... (i-1)
    ll mn = i * X + i * (i - 1) / 2 * D;
    // (N-1-(i-1)) (N-1)
    ll mx = i * X + (N-1-(i-1) + (N-1)) * i / 2 * D;
    mp[((mn % D) + D) % D].emplace_back(floordiv(mn, D), floordiv(mx+D, D));
  }
  ll ans = 0;
  for (auto kv : mp) {
    ans += count(kv.second);
  }
  cout << ans << endl;
}
