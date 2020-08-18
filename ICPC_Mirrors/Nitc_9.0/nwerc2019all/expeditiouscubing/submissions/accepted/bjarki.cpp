// This solution uses plain old doubles and no epsilons when doing comparisons.

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
    vector<double> arr(4);
    rep(i,0,4) cin >> arr[i];
    sort(arr.begin(), arr.end());

    double win;
    cin >> win;

    if ((arr[1]+arr[2]+arr[3])/3.0-1e-9 <= win) {
        cout << "infinite" << endl;
        return 0;
    }

    double t = 3*win - arr[1] - arr[2];
    if (t+1e-9 >= arr[0] && t-1e9 <= arr[3]) {
        cout << fixed << setprecision(2) << t << endl;
    } else {
        cout << "impossible" << endl;
        return 0;
    }

    return 0;
}

