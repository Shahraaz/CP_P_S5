#include <bits/stdc++.h>
using namespace std;

int sign(int x) { return (x > 0) - (x < 0); }

int only_delete(vector<int> a) {
	auto nz_end = remove(begin(a), end(a), 0);
	auto uq_end = unique(begin(a), nz_end, [&](int x, int y) { return sign(x) == sign(y); });
	return end(a) - uq_end;
}

int main() {
	int n;
	long long X, Y;
	cin >> n >> X >> Y;

	vector<int> a(n);
	vector<pair<int,int>> pairs(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pairs[i] = {abs(a[i]),i};
	}
	sort(begin(pairs), end(pairs), greater<pair<int,int>>());

	long long res = only_delete(a)*Y;

	auto bad = [&](int i, int j) {
		if (i < 0 || j >= n) return false;
		return (j-i)%2 == (sign(a[i]) == sign(a[j]));
	};

	int bad_pairs = 0;
	set<int> indices = {-1,n};
	
	for (auto [x,j]: pairs) {
		int accounts = x+1;
		int deletions = bad_pairs;
		res = min(res, accounts*X + deletions*Y);

		if (x == 0) break;
		
		auto it = indices.lower_bound(j);
		int i = *prev(it), k = *it;
		indices.insert(j);
		
		bad_pairs += bad(i,j) + bad(j,k) - bad(i,k);
	}
	cout << res << endl;
}
