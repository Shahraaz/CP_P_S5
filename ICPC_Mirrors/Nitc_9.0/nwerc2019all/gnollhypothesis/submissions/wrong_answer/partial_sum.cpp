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
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<double> p(n);
    rep(i,0,n) cin >> p[i];

    rep(i,0,n) {
        long double s = 0.0;
        long double q = k;
        rep(j,0,min(n-1, 1000)) {
            q /= n-j;
            s += p[(i+n-j)%n] * q;
            q *= n-k-j;
        }
        cout << setprecision(12) << s << endl;
    }

    return 0;
}

