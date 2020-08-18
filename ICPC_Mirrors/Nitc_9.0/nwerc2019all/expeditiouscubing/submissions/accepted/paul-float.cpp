#include <bits/stdc++.h>
using namespace std;

int main() {
	float a, b, c, d, t;
	cin >> a >> b >> c >> d >> t;
	
	if (a > b) swap(a,b);
	if (c > d) swap(c,d);
	if (a > c) swap(a,c);
	if (b > d) swap(b,d);
	
	if ((a+b+c)/3 > t+1e-3) {
		cout << "impossible" << endl;
	} else if ((b+c+d)/3 < t+1e-3) {
		cout << "infinite" << endl;
	} else {
		cout << fixed << setprecision(2) << (3*t-b-c) << endl;
	}
}
