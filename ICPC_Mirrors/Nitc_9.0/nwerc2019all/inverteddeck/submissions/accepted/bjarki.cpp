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

    vi inp(n), arr(n);
    rep(i,0,n) {
        cin >> inp[i];
        arr[i] = inp[i];
    }

    sort(arr.begin(), arr.end());

    int start = 0;
    while (start < n && arr[start] == inp[start]) start++;

    int end = n-1;
    while (end >= 0 && arr[end] == inp[end]) end--;

    if (start > end) {
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    reverse(inp.begin() + start, inp.begin() + end + 1);

    rep(i,1,n) {
        if (!(inp[i-1] <= inp[i])) {
            cout << "impossible" << endl;
            return 0;
        }
    }

    cout << start+1 << " " << end+1 << endl;

    return 0;
}

