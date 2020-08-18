#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> values[N], occurrences[N];
vector<tuple<int,int,int>> result;

bool mark[N];
void dfs(int a) {
	for (int x: values[a]) {
		for (int b: occurrences[x]) {
			if (mark[b]) continue;
			mark[b] = true;
			result.emplace_back(a,b,x);
			dfs(b);
		}
	}
}

int main() {
	int n; cin >> n;
	
	vector<int> numbers;
	map<int,int> id;
	for (int a = 1; a <= n; a++) {
		int m; cin >> m;
		while (m--) {
			int x; cin >> x;
			if (!id.count(x)) {
				id[x] = numbers.size();
				numbers.push_back(x);
			}
			x = id[x];
			values[a].push_back(x);
			occurrences[x].push_back(a);
		}
	}
	
	mark[1] = true;
	dfs(1);

	if (int(result.size()) != n-1) {
		cout << "impossible" << endl;
	} else {
		for (auto [a,b,x]: result) {
			cout << a << " " << b << " " << numbers[x] << endl;
		}
	}
}
