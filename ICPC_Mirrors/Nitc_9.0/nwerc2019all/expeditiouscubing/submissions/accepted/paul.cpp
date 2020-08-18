#include <bits/stdc++.h>
using namespace std;

int read() {
	double x; cin >> x;
	return int(round(x*100));
}

int main() {
	vector<int> times(4);
	for (int i = 0; i < 4; i++) {
		times[i] = read();
	}
	int target = read();
	
	sort(begin(times),end(times));
	int need = 3*target - times[1] - times[2];

	if (need < times[0]) {
		cout << "impossible" << endl;
	} else if (need >= times[3]) {
		cout << "infinite" << endl;
	} else {
		cout << fixed << setprecision(2) << need/100.0 << endl;
	}
}

