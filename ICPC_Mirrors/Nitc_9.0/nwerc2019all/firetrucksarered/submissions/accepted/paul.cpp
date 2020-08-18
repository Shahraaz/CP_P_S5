#include <bits/stdc++.h>
using namespace std;

struct union_find {
	vector<int> parent, size;

	union_find(int n): parent(n), size(n,1) {
		iota(begin(parent), end(parent), 0);
	}


	int find(int a) {
		if (a == parent[a]) return a;
		return parent[a] = find(parent[a]);
	}

	bool unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (size[a] > size[b]) swap(a,b);
		parent[a] = b;
		size[b] += size[a];
		return true;
	}
};

int main() {
	int n; cin >> n;
	
	map<int,vector<int>> occurrences;
	union_find uf(n+1);
	vector<tuple<int,int,int>> result;

	for (int a = 1; a <= n; a++) {
		int m; cin >> m;
		for (int j = 0; j < m; j++) {
			int x; cin >> x;
			occurrences[x].push_back(a);
		}
	}
	
	for (auto [x,as]: occurrences) {
		int a = as[0];
		for (int b: as) if (uf.unite(a,b)) {
			result.emplace_back(a,b,x);
		}
	}

	if (uf.size[uf.find(1)] < n) {
		cout << "impossible" << endl;
	} else {
		for (auto [a,b,x]: result) {
			cout << a << " " << b << " " << x << endl;
		}
	}
}
