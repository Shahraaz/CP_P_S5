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
    int n;
    cin >> n;

    vii arr(n);
    rep(i,0,n) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    vi seq(n);
    rep(i,0,n) seq[arr[i].second] = i;

    int l = 0, r = n-1;
    while (l <= r && seq[l] == l) l++;
    while (l <= r && seq[r] == r) r--;

    if (l > r) {
        cout << 1 << " " << 1 << endl;
    } else {
        bool desc = true;
        for (int i = l; i < r; i++) {
            desc = desc && seq[i] > seq[i+1];
        }

        if (desc) {
            cout << l+1 << " " << r+1 << endl;
        } else {
            cout << "impossible" << endl;
        }
    }

    return 0;
}

