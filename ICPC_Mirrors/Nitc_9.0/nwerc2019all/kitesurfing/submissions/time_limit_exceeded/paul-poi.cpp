#include <bits/stdc++.h>
using namespace std;

int main() {
	int S, D, T, n;
	cin >> S >> D >> T >> n;

	auto no_obstacle = [&](long long len) {
		long long k = len/D;
		return min(len, min((k+1)*T, k*T + len%D));
	};

	vector<int> L(n+1), R(n+1,S);
	for (int i = 0; i < n; i++) {
		cin >> R[i] >> L[i+1];
	}

	auto mod_pos = [&](int x) { return ((x%D) + D) % D; };
	auto mod_neg = [&](int x) { return ((x%D) - D) % D; };
	
	vector<int> p;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			p.push_back(L[i] + mod_pos(L[j]-L[i]));
			p.push_back(L[i] + mod_pos(R[j]-L[i]));
			p.push_back(R[i] + mod_neg(L[j]-R[i]));
			p.push_back(R[i] + mod_neg(R[j]-R[i]));
		}
	}
	p.erase(remove_if(begin(p), end(p), [&](int y) {
		int i = lower_bound(begin(R), end(R), y) - begin(R);
		return i > n || L[i] > y;
	}), end(p));
	sort(begin(p), end(p));
	p.erase(unique(begin(p), end(p)), end(p));
	
	int m = p.size(), k = 0;

	vector<long long> dp(m, 1e16);
	dp[0] = 0;

	for (int i = 0; i < m; i++) {
		while (k <= n && R[k] < p[i]) k++;

		for (int j = i-1; j >= 0 && (p[i]-p[j] <= D || p[j] >= L[k]); j--) {
			if (p[i]-p[j] <= D) {
				dp[i] = min(dp[i], dp[j] + T);
			}
			if (p[j] >= L[k]) {
				dp[i] = min(dp[i], dp[j] + no_obstacle(p[i]-p[j]));
			}
		}
	}
	cout << dp.back() << endl;
}
