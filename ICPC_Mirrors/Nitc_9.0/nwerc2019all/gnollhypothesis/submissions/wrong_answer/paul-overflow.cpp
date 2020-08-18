#include <bits/stdc++.h>
using namespace std;

const int N = 555;
double fac[N];

double binom(int n, int k) {
	if (k > n) return 0;
	return fac[n] / fac[k] / fac[n-k];
}

int main() {
	fac[0] = 1;
	for (int n = 1; n < N; n++) {
		fac[n] = fac[n-1] * n;
	}

	int n, k;
	cin >> n >> k;

	vector<double> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < n; j++) {
			b[(i+j)%n] += a[i] * binom(n-1-j, k-1) / binom(n, k);
		}
	}

	cout << fixed << setprecision(7);
	for (int i = 0; i < n; i++) {
		cout << b[i] << " \n"[i+1==n];
	}
}
