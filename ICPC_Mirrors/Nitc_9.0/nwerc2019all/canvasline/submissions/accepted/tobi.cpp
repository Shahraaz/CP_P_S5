#include <iostream>
#include <set>
using namespace std;

int n, l[1005], r[1005], p, x, c[1005], candidate;
set<int> pegs;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
	cin >> p;
	for (int i = 0; i < p; i++) {
		cin >> x;
		pegs.insert(x);
		for (int i = 0; i < n; i++) if (l[i] <= x && x <= r[i]) c[i]++;
	}
	set<int> origPegs(pegs);
	for (int i = 0; i < n; i++) {
		switch (c[i]) {
		case 0:
			if (i + 1 < n && r[i] == l[i+1]) {
				if (c[i+1] <= 1) pegs.insert(r[i]), c[i+1]++;
				else pegs.insert(r[i]-3);
				pegs.insert(r[i]-1);
			} else pegs.insert(r[i]-4), pegs.insert(r[i]-1);
			break;
		case 1:
			candidate = r[i];
			if (i + 1 < n && r[i] == l[i+1] && c[i+1] >= 2) candidate = r[i] - 1;
			while (pegs.count(candidate)) candidate--;
			pegs.insert(candidate);
			if (i + 1 < n && r[i] == l[i+1] && candidate == r[i]) c[i+1]++;
			break;
		case 2: break;
		default:
			cout << "impossible" << endl;
			return 0;
		}
	}
	cout << pegs.size()-origPegs.size() << endl;
	for (int peg : pegs) if (!origPegs.count(peg)) cout << peg << " ";
	cout << endl;
}
