#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main(){
	int n, k;
   	cin >> n >> k;
	++n;
	vector<int> h(n);
	for(auto& x : h) cin >> x;

	while(k--){
		float x;
		cin >> x;
		int y = round(10*x);

		// Create a new 'hill' h2 where we subtract the target inclination.
		vector<int> h2 = h;
		for(int i = 0; i < n; ++i)
			h2[i] -= i * y;

		// Positions of increasing heights:
		vector<int> perm(n);
		iota(begin(perm), end(perm), 0);
		// Make sure that for equal points, the left one comes first.
		stable_sort(begin(perm), end(perm), [&](int i, int j){ return h2[i] < h2[j]; });

		// Go through the points on h2 from low to high, keeping track of the
		// leftmost point we've seen. The longest interval starts at this
		// leftmost point.
		int min = 1e9;
		double ans = 0;
		for(auto i : perm){
			if(i < min){
				min = i;
			} else {
				ans = max(ans, double(i - min));
				// Try to extend the interval to the left or right.
				// WA: should be min > 0
				if(min > 1 and h2[min-1] > h2[i]){
					// extend left at height h2[i]
					//
					// a
					//  \
					//   h
					//    \
					//     b
					// x ? y
					// sa + (1-s)b = h
					// s(a-b) = h-b
					// s = (h-b)/(a-b)
					ans = max(ans, i - min + double(h2[i]-h2[min])/(h2[min-1]-h2[min]));
				}
				if(i+1 < n and h2[i+1] < h2[min]){
					// extend right at height h2[min]
					//
					// a
					//  \
					//   h
					//    \
					//     b
					// x ? y
					// (1-s)a + sb = h
					// s = (a-h)/(a-b)
					ans = max(ans, i - min + double(h2[i]-h2[min])/(h2[i]-h2[i+1]));
				}
			}
		}

		cout.precision(10);
		if(ans > 0)
			cout << ans << endl;
		else
			cout << "impossible" << endl;
	}
}
