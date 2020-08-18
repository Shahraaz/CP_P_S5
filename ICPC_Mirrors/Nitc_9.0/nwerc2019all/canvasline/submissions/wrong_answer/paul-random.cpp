#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int a[N], b[N];
vector<int> pegs;

bool have_peg(int x) {
	return find(begin(pegs), end(pegs), x) != end(pegs);
}

int count_pegs(int i) {
	return count_if(begin(pegs), end(pegs), [&](int x) { return a[i] <= x && x <= b[i]; });
}

int main() {
	srand(111222333);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	int p; cin >> p;
	pegs.resize(p);
	for (int &x: pegs) cin >> x;

	for (int i = 0; i < n; i++) {
		if (count_pegs(i) > 2) {
			cout << "impossible" << endl;
			return 0;
		}
	}

	for (int i = 1; i < n; i++) {
		if (b[i-1] < a[i] || have_peg(a[i])) continue;
		if (max(count_pegs(i-1), count_pegs(i)) < 2) pegs.push_back(a[i]);
	}
	
	for (int i = 0; i < n; i++) {
		int need = 2 - count_pegs(i);
		while (need--) {
			int x = a[i] + 1 + rand() % (b[i]-a[i]-1);
			pegs.push_back(x);
		}
	}

	pegs.erase(begin(pegs), begin(pegs)+p);
	cout << pegs.size() << endl;
	for (int x: pegs) cout << x << " ";
	cout << endl;
}
