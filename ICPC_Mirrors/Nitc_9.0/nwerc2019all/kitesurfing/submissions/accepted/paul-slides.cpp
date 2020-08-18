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

	auto no_obstacle = [&](int len) {
		i64 k = len/D;
		return min(i64(len), k*T + min(len%D,T));
	};

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

		if (i == N) {
			improve(S, distance[x] + no_obstacle(S-x));
			continue;
		}

		for (int j = i+1; j <= N; j++) {
			int y = L[j]-D;
			if (find_interval(y) == i && x <= y) {
				improve(L[j], distance[x] + no_obstacle(y-x) + T);
			}
		}
		
		int j = i, k = (R[i]-x)/D;
		i64 cost = i64(k) * T;
		int y = x + k*D;
		
		while (j = find_interval(y), j == i || j == -1) {
			if (j == i) {
				y += D, cost += T;
			}
			if (j == -1) {
				y = R[upper_bound(begin(R),end(R),y) - begin(R) - 1];
			}
		}
		improve(y, distance[x] + cost);
	}
	cout << distance[S] << endl;
	cerr << distance.size() << endl;
}
