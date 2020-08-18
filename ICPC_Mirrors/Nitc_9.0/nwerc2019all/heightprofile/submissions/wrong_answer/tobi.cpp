#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define FOR(i,a,b) for (auto i=(a); i<(b); ++i)
using namespace std;

long long n, k, heights[100005];
double g, diffs[100005];
vector<pair<int, double>> candidates;

int main() {
	cin >> n >> k;
	n++;
	FOR(i, 0, n) cin >> heights[i];
	FOR(i, 0, k) {
		double best = 0;
		cin >> g;
		long long wanted = g*10;
		FOR(j, 0, n) diffs[j] = heights[j] - wanted * j;
		candidates.clear();
		candidates.push_back(make_pair(0, diffs[0]));
		FOR(j, 1, n) {
			int a = 0, o = candidates.size();
			while (a < o) {
				int m = (a + o) / 2;
				if (candidates[m].second <= diffs[j]) o = m;
				else a = m + 1;
			}
			if (a < candidates.size()) {
				int idx = candidates[a].first;
				while (idx > 0 && diffs[idx-1] <= diffs[j]) idx--;
				double streak = j - idx;
				best = max(best, streak);
				if (idx > 0) best = max(best, streak + 1 - (diffs[j] - diffs[idx-1]) / (diffs[idx] - diffs[idx-1]));
				if (j < n - 1) best = max(best, streak + (diffs[j] - diffs[idx]) / (diffs[j] - diffs[j+1]));
			}
			if (diffs[j] < candidates.back().second) candidates.push_back(make_pair(j, diffs[j]));
		}
		if (best == 0) cout << "impossible" << endl;
		else cout << fixed << setprecision(20) << best << endl;
	}
}
