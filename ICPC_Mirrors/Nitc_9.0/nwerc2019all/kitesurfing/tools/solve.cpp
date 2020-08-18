#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int MAX_ACTIONS = 200;
const int MAX_FACTOR = 1000;

void refuse(string reason) {
	cerr << "Case not drawable: " << reason << endl;
	exit(1);
}

enum action { jump, surf };

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
	map<int,pair<int,action>> pred;
	set<int> PQ;

	distance[L[0]] = 0;
	PQ.insert(0);

	auto improve = [&](int x, int y, action act, i64 new_dist) {
		if (!distance.count(x)) distance[x] = LLONG_MAX;
		if (new_dist >= distance[x]) return;
		distance[x] = new_dist;
		pred[x] = {y,act};
		PQ.insert(x);
	};

	while (!PQ.empty()) {
		int x = *begin(PQ);
		PQ.erase(begin(PQ));
		
		int i = find_interval(x);
		assert(i != -1);
		
		// From each point, try the following options:
		// 1a) Make jumps until we are within distance 2*D of the end of this interval.
		// 1b) If we are within distance 2*D of the end, make a jump of maximal length.
		// 2a) For each interval to the right, surf until we can jump to that interval.
		// 2b) If we are in the final interval, try surfing to the finish line.
		
		if (x+2LL*D <= R[i]) {
			i64 k = max(0, (R[i]-x)/D - 1);
			improve(x + k*D, x, jump, distance[x] + k*T);
		} else {
			int j = i;
			while (j+1 <= N && L[j+1] <= x+D) j++;
			improve(min(x+D,R[j]), x, jump, distance[x] + T);
		}
		
		if (i < N) {
			for (int j = i+1; j <= N; j++) {
				int y = L[j]-D;
				if (y >= x && y <= R[i]) {
					improve(y, x, surf, distance[x] + y-x);
				}
			}
		} else {
			improve(S, x, surf, distance[x] + S-x);
		}
	}

	vector<pair<int,action>> path;
	for (int x = S; x > 0; ) {
		auto [y,act] = pred[x];
		int dist = x-y;
		if (act == surf) {
			path.emplace_back(dist, surf);
		} else {
			if (dist%D > 0) {
				path.emplace_back(dist%D, jump);
			}
			if (dist/D > MAX_ACTIONS) refuse("too many jumps");
			for (int i = 0; i < dist/D; i++) {
				path.emplace_back(D, jump);
			}
		}
		x = y;
	}
	if (int(path.size()) > MAX_ACTIONS) refuse("too many steps");
	reverse(begin(path), end(path));

	vector<int> lengths;
	for (int i = 0; i <= N; i++) {
		lengths.push_back(R[i]-L[i]);
		if (i > 0) lengths.push_back(L[i]-R[i-1]);
	}
	for (auto step: path) {
		lengths.push_back(step.first);
	}

	int min_length = *min_element(begin(lengths), end(lengths));
	int max_length = *max_element(begin(lengths), end(lengths));
	
	if (max_length / min_length > MAX_FACTOR) {
		refuse("range of interval lengths too large");
	}

	cout << path.size() << endl;
	for (auto [len,act]: path) {
		cout << (act == surf ? "surf" : "jump") << " " << len << endl;
	}
}
