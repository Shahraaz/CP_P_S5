/* Always do the jump of maximal possible distance.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	int s, d, t, n;
	cin >> s >> d >> t >> n;
	vector<int> a(n+1), b(n+1);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	a[n] = s, b[n] = INT_MAX;
	
	int x = 0, i = 0, cost = 0;
	while (x < s) {
		int y = x+d;
		while (b[i] <= y) i++;
		y = min(y,a[i]);
		cost += t, x = y;
	}
	cout << cost << endl;
}
