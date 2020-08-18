#include <vector>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>
using namespace std;

// TCR CODE

using V = double;

constexpr V pi = 3.1415926535897932384626433; // or std::acos(-1)
struct Complex { using T = Complex; V u,v;
	template<typename U = V>
	Complex(U u=0, U v=0) : u(u), v(v) {}
	T operator+(T r) const { return {u+r.u, v+r.v}; }
	T operator-(T r) const { return {u-r.u, v-r.v}; }
	T operator*(T r) const { return {u*r.u - v*r.v, u*r.v + v*r.u}; }
	T operator/(T r) const {
		auto norm = r.u*r.u+r.v*r.v;
		return {(u*r.u + v*r.v)/norm, (v*r.u - u*r.v)/norm};
	}
	T operator*(V r) const { return T{u*r, v*r}; }
	T operator/(V r) const { return T{u/r, v/r}; }
	T inv() const { return T{1,0}/ *this; }
	T conj() const { return T{u, -v}; }
	static T root(long long k){ return {cos(2*pi/k), sin(2*pi/k)}; }
	bool zero() const { return max(abs(u), abs(v)) < 1e-6; }
};
void brinc(int &x, int k) {
	int i = k - 1, s = 1 << i;
	x ^= s;
	if ((x & s) != s) {
		--i; s >>= 1;
		while (i >= 0 && ((x & s) == s))
			x = x &~ s, --i, s >>= 1;
		if (i >= 0) x |= s;
	}
}
using T = Complex;
vector<T> roots;
/*
void root_cache(int N) {
	if (N == (int)roots.size()) return;
	roots.assign(N, T{0});
	for (int i = 0; i < N; ++i)
		roots[i] = ((i&-i) == i)
			? T{cos(2.0*pi*i/N), sin(2.0*pi*i/N)}
			: roots[i&-i] * roots[i-(i&-i)];
}*/
void fft(vector<T> &A, int p, bool inv = false) {
	int N = 1<<p;
	for(int i = 0, r = 0; i < N; ++i, brinc(r, p))
		if (i < r) swap(A[i], A[r]);
//	Uncomment to precompute roots (for T=Complex). Slower but more precise.
	//root_cache(N);
	for (int m = 2, sh=p-1; m <= N; m <<= 1, --sh) {
		T w, w_m = T::root(inv ? -m : m);
		for (int k = 0; k < N; k += m) {
			w = T{1};
			for (int j = 0; j < m/2; ++j) {
				//T w = (!inv ? roots[j<<sh] : roots[j<<sh].conj());
				T t = w * A[k + j + m/2];
				A[k + j + m/2] = A[k + j] - t;
				A[k + j] = A[k + j] + t;
				w = w * w_m;
			}
		}
	}
	if(inv){ T inverse = T(N).inv(); for(auto &x : A) x = x*inverse; }
}
// convolution leaves A and B in frequency domain state
// C may be equal to A or B for in-place convolution
void convolution(vector<T> &A, vector<T> &B, vector<T> &C){
	int s = A.size() + B.size() - 1;
	int q = 32 - __builtin_clz(s-1), N=1<<q;	// fails if s=1
	A.resize(N,{}); B.resize(N,{}); C.resize(N,{});
	fft(A, q, false); fft(B, q, false);
	for (int i = 0; i < N; ++i) C[i] = A[i] * B[i];
	fft(C, q, true); C.resize(s);
}

// Solution code

int main(){
	int n, k; cin >> n >> k;
	vector<T> v(n), streak(n-k+1, {1,0});
	for(auto&x : v) cin >> x.u;

	// p[i] = probability of adding v[n-i] to v[n]
	//      = i-1 non-chosen monsters and 1 chosen monster
	for(int i = n-k-1; i >= 0; --i) streak[i].u = streak[i+1].u * (n-i-1) / (n-i-k);
	
	// Hockey-stick lemma
	V nck = 0;
	for(auto& x : streak) nck += x.u;
	for(auto& x : streak) x.u /= nck;

	vector<T> ans;
	convolution(v, streak, ans);
	assert(ans.size() == n+(n-k+1)-1);
	for(int i = n; i < n+(n-k); ++i)
		ans[i%n].u += ans[i].u;

	ans.resize(n);
	bool f = true;
	cout.precision(13);
	for(auto x : ans){
		if(!f) cout << ' ';
		f = false;
	   	cout << x.u;
	}
	cout << endl;
}
