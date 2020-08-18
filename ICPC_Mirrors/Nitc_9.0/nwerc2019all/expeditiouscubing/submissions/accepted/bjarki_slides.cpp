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
    double mn = INFINITY,
           mx = -INFINITY,
           sm = 0.0;

    rep(i,0,4) {
        double y;
        cin >> y;
        mn = min(mn, y);
        mx = max(mx, y);
        sm += y;
    }

    double t;
    cin >> t;

    if ((sm - mn)/3.0 <= t + 1e-9) {
        cout << "infinite" << endl;
        return 0;
    }

    if ((sm - mx)/3.0 > t + 1e-9) {
        cout << "impossible" << endl;
        return 0;
    }

    cout << setprecision(2) << fixed << t*3.0 + mn + mx - sm << endl;

    return 0;
}

