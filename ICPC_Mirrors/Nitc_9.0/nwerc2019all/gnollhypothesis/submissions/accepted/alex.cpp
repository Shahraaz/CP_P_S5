#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vld = vector<ld>;
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

ld choose(ll n, ll k) {
  ld res = 1.0, divide = 1;
  ll bigger_k = max(k, n - k);
  while(n > bigger_k) {
    res = (res * n) / divide;
    n--;
    divide++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout << setprecision(8) << fixed;
  ll n,k;
  cin >> n >> k;
  vld spawn_chance(n);
  FOR(i,0,n) cin >> spawn_chance[i];
  // corner case k = 1 since that breaks the latter algorithm
  if(k == 1) {
    FOR(i,0,n) cout << 100.0/n << " ";
    cout << endl;
    return 0;
  }
  vld eff_chance(n, 0);
  ld all_poss = choose(n, k);

  FOR(i,0, n-k+1) {
    // calculate probability that there is a gap of size i behind chosen monster
    ld prob = choose(n - i - 2, k - 2) / all_poss;
    // set first chosen monster to index i
    ld cur_spawn_chance = 0;
    FOR(j,0,i) cur_spawn_chance += spawn_chance[j];
    // cycle through all indices
    FOR(j,i,n + i) {
      cur_spawn_chance += spawn_chance[j % n];
      eff_chance[j % n] += cur_spawn_chance * prob;
      cur_spawn_chance -= spawn_chance[j-i];
    }
  }
  FOR(i,0,n) cout << eff_chance[i] << " ";
  cout << endl;
  return 0;
}
