#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> L(n), R(n), count(n);
	for (int i = 0; i < n; i++) {
		cin >> L[i] >> R[i];
	}

	int p; cin >> p;
  set<int> px;
	while (p--) {
		int x; cin >> x; px.insert(x);
		for (int i = 0; i < n; i++) {
			count[i] += L[i] <= x && R[i] >= x;
		}
	}

	vector<int> res;
	for (int i = 0; i < n; i++) {
		if (i+1 < n && R[i] == L[i+1]) {
			if (!px.count(R[i]) && max(count[i],count[i+1]) < 2) {
				count[i]++, count[i+1]++;
				res.push_back(R[i]);
        px.insert(res.back());
			}
		}
    for (int j = L[i]; j <= R[i] && count[i] < 2; j++) {
      if (!px.count(j) && (j > L[i] || i == 0 || L[i] > R[i-1])) {
        count[i]++;
        res.push_back(j);
        px.insert(res.back());
      }
		}
	}

	int min_count = *min_element(begin(count), end(count));
	int max_count = *max_element(begin(count), end(count));
	if (min_count < 2 || max_count > 2) {
		cout << "impossible" << endl;
		return 0;
	}

	cout << res.size() << endl;
	for (int x: res) cout << x << " ";
	cout << endl;

}
