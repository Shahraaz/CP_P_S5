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

ll snoob(ll x) {
  ll y = x & -x, z = x + y;
  return z | ((x ^ z) >> 2) / y; }

int main() {
    int n, k;
    cin >> n >> k;

    vector<double> p(n), q(n);
    rep(i,0,n) {
        cin >> p[i];
    }

    ll cnt = 0;
    for (ll s = (1LL<<k)-1; s < (1LL<<n); s = snoob(s)) {
        cnt++;

        rep(i,0,n) {
            int at = i;
            while (~s&(1<<at)) {
                at = (at+1)%n;
            }
            q[at] += p[i];
        }
    }

    rep(i,0,n) {
        cout << setprecision(12) << q[i]/cnt << endl;
    }

    return 0;
}

