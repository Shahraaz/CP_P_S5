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

int main() {
    int n, k;
    cin >> n >> k;

    vector<double> p(n), q(n);
    rep(i,0,n) cin >> p[i];

    vector<int> perm(n);
    rep(i,0,n) {
        perm[i] = i;
    }

    vector<bool> picked(n);

    int its = 20000000/n;
    rep(it,0,its) {
        random_shuffle(perm.begin(), perm.end());

        rep(i,0,n) picked[i] = false;
        rep(i,0,k) {
            picked[perm[i]] = true;
        }

        rep(i,0,n) {
            int at = i;
            while (!picked[at]) {
                at = (at+1)%n;
            }
            q[at] += p[i];
        }
    }

    rep(i,0,n) {
        cout << setprecision(12) << q[i]/its << endl;
    }

    return 0;
}

