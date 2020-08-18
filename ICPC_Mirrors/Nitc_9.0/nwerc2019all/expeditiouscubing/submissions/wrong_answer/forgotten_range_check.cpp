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

    if ((arr[1]+arr[2]+arr[3])/3.0 <= win) {
        cout << "infinite" << endl;
        return 0;
    }

    if ((arr[0]+arr[1]+arr[2])/3.0 > win) {
        cout << "impossible" << endl;
        return 0;
    }

    double t = 3*win - arr[1] - arr[2];
    cout << fixed << setprecision(2) << t << endl;

    return 0;
}

