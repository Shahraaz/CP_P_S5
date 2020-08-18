#include<bits/stdc++.h>
using namespace std;

using C = complex<double>;

vector<C> fft(vector<C> a, int sign) {
	int n = a.size();
	if (n == 1) return a;
	vector<C> b, c;
	for (C x: a) b.push_back(x), swap(b,c);
	b = fft(b,sign), c = fft(c,sign);
	for (int i = 0; i < n/2; i++) {
		C r = polar(1.0, 2*i*sign*M_PI/n);
		a[i]     = b[i] + r * c[i];
		a[n/2+i] = b[i] - r * c[i];
	}
	return a;
}

vector<C> operator*(vector<C> a, vector<C> b) {
	int m = a.size(), n = b.size(), N = 1;
	while (N < m+n) N *= 2;
	
	a.resize(N), b.resize(N);
	a = fft(a,1), b = fft(b,1);

	vector<C> c(N);
	for (int i = 0; i < N; i++) {
		c[i] = a[i] * b[i];
	}
	c = fft(c,-1);
	for (C &x: c) x /= N;
	return c;
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<C> a(n);
	for (int i = 0; i < n; i++) {
		double x; cin >> x;
		a[i] = x;
	}
	
	vector<double> logfact(n+1);
	for (int i = 1; i <= n; i++) logfact[i] = log(i) + logfact[i-1];
	
	auto logbinom = [&](int n, int k) {
		if (k < 0 || k > n) return -1/0.;
		return logfact[n] - logfact[k] - logfact[n-k];
	};

	vector<C> b(n);
	for (int i = 0; i < n; i++) {
		b[i] = exp(logbinom(n-1-i,k-1) - logbinom(n,k));
	}
	
	vector<C> c = a*b;
	for (int i = n; i < int(c.size()); i++) c[i%n] += c[i];
	
	cout << fixed << setprecision(7);
	for (int i = 0; i < n; i++) cout << real(c[i]) << " ";
	cout << endl;
}
