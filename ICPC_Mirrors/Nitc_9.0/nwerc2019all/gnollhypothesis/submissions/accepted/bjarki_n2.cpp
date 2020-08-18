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

long double bin(int n, int k) {
    if (k > n) return 0;

    long double res = 1.0;
    rep(i,1,k+1) {
        res = res * (n - (k - i)) / i;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<double> p(n);
    rep(i,0,n) cin >> p[i];

    rep(i,0,n) {
        long double s = p[i] * bin(n-1,k-1);
        rep(j,1,n) {
            s += p[(i+n-j)%n] * bin(n-1-j,k-1);
        }
        cout << setprecision(12) << s / bin(n,k) << endl;
    }

    return 0;
}

