#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	
	vector<int> h(n+1);
	for (int i = 0; i <= n; i++) cin >> h[i];
	
	while (q--) {
		double tt; cin >> tt;
		int t = round(tt*10);

		auto f = [&](int i) { return h[i]-t*i; };

		vector<int> is(n+1);
		iota(begin(is), end(is), 0);
		stable_sort(begin(is), end(is), [&](int i, int j) { return f(i) < f(j); });
		
		double res = -1;

		int l = n;
		for (int r: is) {
			if (l < r) {
				double extra = -1e10;
				if (l > 0) extra = max(extra, double(f(r)-f(l)) / abs(f(l)-f(l-1)));
				if (r < n) extra = max(extra, double(f(r)-f(l)) / abs(f(r+1)-f(r)));
				res = max(res, r-l + clamp(extra,0.0,1.0));
			}
			l = min(l,r);
		}
		
		if (res < 0) cout << "impossible" << endl;
		else cout << fixed << setprecision(20) << res << endl;
	}
}
