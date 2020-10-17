#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn(i, n)
            cin >> a[i];
        int ans = 0;
        map<int,int> cnts;
        for (int j = n - 1; j >= 0; j--) {
            forn(i, j) {
                int ak = a[j] - a[i] + a[j];
                if (cnts.count(ak))
                    ans += cnts[ak];
            }                    
            cnts[a[j]]++;
        }
        cout << ans << endl;
    }
}
