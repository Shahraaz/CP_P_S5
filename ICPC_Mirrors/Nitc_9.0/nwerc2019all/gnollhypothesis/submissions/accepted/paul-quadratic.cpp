#include <bits/stdc++.h>
using namespace std;

const int N = 555;
double binom[N][N];

int main() {
	for (int n = 0; n < N; n++) {
		binom[n][0] = binom[n][n] = 1;
		for (int k = 1; k < n; k++) {
			binom[n][k] = binom[n-1][k-1] + binom[n-1][k];
		}
	}

	int n, k;
	cin >> n >> k;

	vector<double> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < n; j++) {
			b[(i+j)%n] += a[i] * binom[n-1-j][k-1] / binom[n][k];
		}
	}

	cout << fixed << setprecision(7);
	for (int i = 0; i < n; i++) {
		cout << b[i] << " \n"[i+1==n];
	}
}
