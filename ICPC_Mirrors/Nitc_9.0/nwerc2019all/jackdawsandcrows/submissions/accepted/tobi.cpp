#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define FOR(i,a,b) for (auto i=(a); i<(b); ++i)
#define MUCH 1000001

long long score, x, y, best, dp[20][5*100001][2][2], items[20], layer;
set<pair<long long, int>> votes;

void update(int curLayer, int idx) {
	FOR(j, 0, 2) FOR(k, 0, 2) dp[curLayer][idx][j][k] = MUCH;
	FOR(j, 0, 2) FOR(k, 0, 2) FOR(l, 0, 2)
		dp[curLayer][idx][j][k] = min(dp[curLayer][idx][j][k], dp[curLayer-1][idx*2][j][l] + dp[curLayer-1][idx*2+1][1-l][k]);
}

int main() {
	cin >> items[0] >> x >> y;
	best = y*items[0];
	FOR(i, 0, items[0]) {
		cin >> score;
		votes.insert(make_pair(1+abs(score), i));
		dp[0][i][0][0] = score < 0 ? 0 : MUCH;
		dp[0][i][1][1] = score > 0 ? 0 : MUCH;
		dp[0][i][0][1] = dp[0][i][1][0] = 1;
	}
	for (layer = 1; items[layer-1] > 1; layer++) {
		items[layer] = (items[layer-1]+1) / 2;
		FOR(i, 0, items[layer]) update(layer, i);
	}
	FOR(i, 0, 2) FOR(j, 0, 2) best = min(best, y*dp[layer-1][0][i][j]);
	for(auto vote : votes) {
		int idx = vote.second;
		FOR(j, 0, 2) dp[0][idx][j][j] = 0;
		FOR(j, 1, layer) {
			idx /= 2;
			update(j, idx);
		}
		FOR(j, 0, 2) FOR(k, 0, 2) best = min(best, y*dp[layer-1][0][j][k] + x*vote.first);
	}
	cout << best << endl;
}
