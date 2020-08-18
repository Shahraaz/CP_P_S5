/* We first transform the problem by switching land and water, so that we now
 * jump from island to island or walk on them. Now consider any solution:
 *
 * - If at any point we walk, followed by a jump, and the jump does not
 *   land at the left end of an island, then it is not worse to make the
 *   jump earlier instead.
 * - So WLOG we can assume that each walk either ends at a point L[i]-D, or
 *   at the finish line. (1)
 * - Also, whenever we make a jump, it is optimal to jump to the furthest
 *   possible land point. (2)
 * 
 * So we set up the following DP:
 * 
 *   dp[i] = minimal time needed to finish when starting at L[i]
 *
 * To compute dp[i], we iterate over j: the next island where we allow
 * ourselves to walk:
 * 
 * - Using (2), we can find the first point on the island we touch.
 * - Using (1), we can also iterate over the last point we touch.
 *
 * For the fastest way between two points on the same island, there are
 * three options: a) walk, b) only use jumps, c) jump until the distance is
 * less than D and walk the rest.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	int S, D, C, N;
	cin >> S >> D >> C >> N;
	
	vector<int> L(N+1), R(N+1);
	for (int i = 0; i < N; i++) {
		cin >> R[i] >> L[i+1];
	}
	R[N] = S;
	
	/* If we start jumping at L[i] until we reach island j,
	 * where do we first land and how many jumps do we need?
	 */
	auto jump = [&](int i, int j) {
		int pos = L[i], cnt = 0, k = i;
		while (k < j) {
			if (pos+D <= R[k]) {
				int t = (R[k]-pos)/D;
				pos += t*D, cnt += t;
			} else if (pos+D < L[k+1]) {
				pos = R[k], cnt++;
			} else {
				while (k < j && L[k+1] <= pos+D) k++;
				pos = min(pos+D,R[k]), cnt++;
			}
		}
		return make_pair(pos,cnt);
	};
	
	/* What is the fastest way to cover a certain distance
	 * when only moving over land?
	 */
	auto dry_distance = [&](int from, int to) {
		if (from > to) return 0LL;
		long long dist = to-from, k = dist/D;
		return min(dist, min((k+1)*C, k*C + dist%D));
	};

	vector<long long> dp(N+1,LLONG_MAX/2);
	
	for (int i = N; i >= 0; i--) {
		for (int j = i; j <= N; j++) {
			auto [first_pos, jump_count] = jump(i,j);
			long long jump_cost = jump_count * 1LL * C;
			
			if (j == N) {
				dp[i] = min(dp[i], jump_cost + dry_distance(first_pos,R[N]));
			} else {
				for (int k = j+1; k <= N; k++) {
					int last_pos = L[k]-D;
					if (last_pos > R[j]) break;
					dp[i] = min(dp[i], jump_cost + dry_distance(first_pos, last_pos) + C + dp[k]);
				}
			}
		}
	}
	cout << dp[0] << endl;
}
