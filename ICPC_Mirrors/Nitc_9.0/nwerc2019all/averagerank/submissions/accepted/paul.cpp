#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
long long res[N];
vector<int> points[N];            // i -> list of times where person i scores a point
vector<pair<int,int>> events[N];  // j -> list of events "person i enters/leaves bucket j at time k"

int main() {
	int n, m;
	cin >> n >> m;

	for (int k = 0; k < m; k++) {
		int len; cin >> len;
		while (len--) {
			int i; cin >> i;
			points[i].push_back(k);
		}
	}

	for (int i = 1; i <= n; i++) {
		int s = points[i].size();
		for (int j = 0; j < s; j++) {
			int k = points[i][j];
			events[j].emplace_back(k,~i);
			events[j+1].emplace_back(k,i);
		}
		events[s].emplace_back(m,~i);
	}

	for (int j = 0; j <= m; j++) {
		sort(begin(events[j]), end(events[j]));
		int above = 0, pk = -1;
		long long sum = 0;
		for (auto [k,i]: events[j]) {
			sum += (k-pk) * 1LL * above;
			pk = k;
			if (i < 0) {
				res[~i] += sum;
				above++;
			} else {
				res[i] -= sum;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << fixed << setprecision(10) << double(m+res[i])/m << endl;
	}
}
