#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, a[100000];

void solve() {
	cin >> n >> k;
	for(int i=0; i<n; ++i)
		cin >> a[i];

	int lb=1, rb=a[n-1]-a[0];
	while(lb<rb) {
		int mb=(lb+rb)/2;
		int k2=0;
		for(int i=1; i<n; ++i) {
			int d=a[i]-a[i-1];
			//ceil(d/(n+1))<=mb
			//d<=mb*(n+1)
			//d/mb-1<=n
			k2+=(d+mb-1)/mb-1;
		}
		if(k2<=k)
			rb=mb;
		else
			lb=mb+1;
	}
	cout << lb << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, i=1;
	cin >> t;
	while(t--) {
		cout << "Case #" << i << ": ";
		solve();
		++i;
	}
}