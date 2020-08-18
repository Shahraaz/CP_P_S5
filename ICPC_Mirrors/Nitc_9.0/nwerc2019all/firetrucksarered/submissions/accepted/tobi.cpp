#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n, m, x;
vector<pair<int,int>> nexts[2*100001];
bool vis[2*100001];
unordered_map<int, int> nums;
vector<tuple<int,int,int>> result;

void dfs(int cur) {
	for (auto it = nexts[cur].begin(); it != nexts[cur].end(); it++) {
		if (!vis[it->first]) {
			result.push_back(make_tuple(cur, it->first, it->second));
			vis[it->first] = true;
			dfs(it->first);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> x;
			auto range = nums.equal_range(x);
			for (auto it = range.first; it != range.second; ++it) {
				nexts[it->second].push_back(make_pair(i, x));
				nexts[i].push_back(make_pair(it->second, x));
			}
			nums.insert(make_pair(x,i));
		}
	}
	
	vis[0] = true;
	dfs(0);
	if (result.size() < n-1) cout << "impossible" << endl;
	else for (auto t : result) {
		cout << get<0>(t)+1 << " " << get<1>(t)+1 << " " << get<2>(t) << endl;
	}
}
