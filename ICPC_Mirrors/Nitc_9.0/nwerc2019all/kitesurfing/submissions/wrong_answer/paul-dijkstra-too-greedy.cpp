#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	int S, D, T, N;
	cin >> S >> D >> T >> N;
	
	vector<int> L(N+1), R(N+1);
	for (int i = 0; i < N; i++) {
		cin >> R[i] >> L[i+1];
	}
	R[N] = S;
	
	auto find_interval = [&](int x) {
		int i = lower_bound(begin(R),end(R),x) - begin(R);
		return (i <= N && L[i] <= x) ? i : -1;
	};
	
	map<int,i64> distance;
	set<int> PQ;

	distance[L[0]] = 0;
	PQ.insert(0);

	auto improve = [&](int x, i64 new_dist) {
		if (!distance.count(x)) distance[x] = LLONG_MAX;
		if (new_dist >= distance[x]) return;
		distance[x] = new_dist;
		PQ.insert(x);
	};

	while (!PQ.empty()) {
		int x = *begin(PQ);
		PQ.erase(begin(PQ));
		
		int i = find_interval(x);
		assert(i != -1);
		
		// From each point, try the following options:
		// 1a) Make jumps until we are within distance D of the end of this interval.
		// 1b) If we are within distance D of the end, make a jump of maximal length.
		// 2a) For each interval to the right, surf until we can jump to that interval.
		// 2b) If we are in the final interval, try surfing to the finish line.
		
		// 1a) is incorrect, because it may be better not to do the last jump.

		if (x+D < R[i]) {
			i64 k = (R[i]-1-x)/D;
			improve(x + k*D, distance[x] + k*T);
		} else {
			int j = i;
			while (j+1 <= N && L[j+1] <= x+D) j++;
			improve(min(x+D,R[j]), distance[x] + T);
		}
		
		if (i < N) {
			for (int j = i+1; j <= N; j++) {
				int y = L[j]-D;
				if (y >= x && y <= R[i]) {
					improve(y, distance[x] + y-x);
				}
			}
		} else {
			improve(S, distance[x] + S-x);
		}
	}
	cout << distance[S] << endl;
}
