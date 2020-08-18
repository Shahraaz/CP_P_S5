// This submission uses up time and memory proportional to the maximum possible distance.
// May be either TLE or RTE, depending on the environment.
#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX/2;

int main() {
	int S, D, C, N;
	cin >> S >> D >> C >> N;
	
	vector<int> L(N), R(N);
	for (int i = 0; i < N; i++) {
		cin >> L[i] >> R[i];
	}
	
	// dp[x] = minimal time needed to reach x; dp[x] = INF if x is on land.
	vector<long long> dp(S+1, INF);
	dp[0] = 0;

	int y = 0;
	for (int i = 0; i <= N; i++) {
		int xmin = i > 0 ? R[i-1] : 0;
		int xmax = i < N ? L[i] : S;
		for (int x = xmin; x <= xmax; x++) {
			// Either we surf here...
			if (x > xmin) dp[x] = min(dp[x], dp[x-1] + 1);

			// ... or we jump here from the furthest possible point.
			while (y < x-D || dp[y] == INF) y++;
			if (y < x) dp[x] = min(dp[x], dp[y] + C);
		}
	}
	cout << dp[S] << endl;
}
