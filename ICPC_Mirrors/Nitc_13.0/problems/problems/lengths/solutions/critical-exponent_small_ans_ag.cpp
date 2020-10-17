#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

struct fraction {
    int64_t p, q;
    fraction(int64_t _p, int64_t _q) {
        int64_t g = gcd(_p, _q);
        p = _p / g;
        q = _q / g;
    }

    bool operator<(const fraction& f) const {
        return p * f.q < q * f.p;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string w;
    cin >> w;
    int n = int(w.size());
    
    fraction ans(1, 1);
    vector<int> pi(n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n && j < i + 150; j++) {
            int k = pi[j - i - 1];
            while (k > 0 && w[j] != w[k + i]) {
                k = pi[k - 1];
            }
            if (w[j] == w[k + i]) {
                k++;
            }
            pi[j - i] = k;
            ans = max(ans, fraction(j - i + 1, j - i + 1 - k));
        }
    }

    cout << ans.p << "/" << ans.q << "\n";

    return 0;
}