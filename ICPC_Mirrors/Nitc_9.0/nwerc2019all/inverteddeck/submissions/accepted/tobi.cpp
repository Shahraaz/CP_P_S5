#include <iostream>
using namespace std;

int nums[1000005], nums2[1000005], n, l, r;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> nums[i];
	for (int i = 0; i < n; i++) nums2[i] = nums[i];
	for (int i = 0; i < n - 1; i++) {
		if (nums[i] > nums[i + 1]) {
			l = i;
			r = i+1;
			break;
		}
	}
	while (l > 0 && nums[l-1] >= nums[l]) l--;
	while (r < n - 1 && nums[r] >= nums[r+1]) r++;
	for (int i = l; i <= r; i++) nums2[i] = nums[r-i+l];
	for (int i = 0; i < n - 1; i++) if (nums2[i] > nums2[i + 1]) {
		cout << "impossible" << endl;
		return 0;
	}
	cout << l+1 << " " << r+1 << endl;
}
