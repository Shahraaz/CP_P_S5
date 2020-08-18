#include <bits/stdc++.h>
using namespace std;
typedef double Real;

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<Real> f(n), bp(n), g(n);
    for (auto &x: f) cin >> x;
    
    Real nCk = 1.0, binom = 1.0;
    for (int i = 0; i < k && i < n-k; ++i)
        nCk = nCk * (n-i) / (i+1);
    for (int j = n-k; j >= 0; --j) {
        // bp[j] = {n-j-1 choose k-1} / {n choose k}
        bp[j] = binom / nCk;
        binom = binom*(n-j)/(n-j-k+1);
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= n-k; ++j)
            g[(i+j)%n] += f[i] * bp[j];

    cout.precision(12);
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << g[i];
    }
    cout << endl;
}
