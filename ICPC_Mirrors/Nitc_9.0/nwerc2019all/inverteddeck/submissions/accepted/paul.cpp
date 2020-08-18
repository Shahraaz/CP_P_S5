#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	int i = 0;
	while (i+1 < n && a[i+1] >= a[i]) i++;
	while (i > 0 && a[i-1] == a[i]) i--;

	int j = i;
	while (j+1 < n && a[j+1] <= a[j]) j++;
	j++;

	reverse(begin(a)+i, begin(a)+j);
	
	if (is_sorted(begin(a), end(a))) {
		cout << i+1 << " " << j << endl;
	} else {
		cout << "impossible" << endl;
	}
}
