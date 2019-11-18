//Optimise
#include <bits/stdc++.h>
using namespace std;

// #define multitest 1
#define Debug
#ifdef Debug
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
#define pc(...) PC(#__VA_ARGS__, __VA_ARGS__);
template <typename T, typename U>
ostream &operator<<(ostream &out, const pair<T, U> &p)
{
	out << '[' << p.first << ", " << p.second << ']';
	return out;
}
template <typename Arg>
void PC(const char *name, Arg &&arg)
{
	std::cerr << name << " { ";
	for (const auto &v : arg)
		cerr << v << ' ';
	cerr << " }\n";
}
template <typename Arg1>
void ZZ(const char *name, Arg1 &&arg1)
{
	std::cerr << name << " = " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void ZZ(const char *names, Arg1 &&arg1, Args &&... args)
{
	const char *comma = strchr(names + 1, ',');
	std::cerr.write(names, comma - names) << " = " << arg1;
	ZZ(comma, args...);
}
#else
#define db(...)
#define pc(...)
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;

const int nax = 2e5 + 10;

class DeleteArrays
{
private:
	vector<ll> A, B, C;

public:
	vector<long long> doDelete(int a, int b, int c, long long x, long long y, long long z)
	{
		A.resize(a);
		B.resize(b);
		C.resize(c);
		A[0] = 33;
		A[1] = 42;
		for (int i = 2; i < a; ++i)
			A[i] = (5 * A[i - 1] + 7 * A[i - 2]) % mod + 1;
		B[0] = 13;
		for (int i = 1; i < b; ++i)
			B[i] = (11 * B[i - 1]) % mod + 1;
		C[0] = 7;
		C[1] = 2;
		for (int i = 2; i < c; ++i)
			C[i] = (5 * C[i - 1] + 7 * C[i - 2]) % mod + 1;
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		sort(C.begin(), C.end());
		pc(A);
		pc(B);
		pc(C);
		return vector<ll>();
	}
};

#ifdef WIN32
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	auto TimeStart = chrono::steady_clock::now();
#ifdef multitest
	cin >> t;
#endif
	DeleteArrays D;
	D.doDelete(2, 2, 2, 2, 3, 4);
	// while (t--)
	// 	S.Solve();
#ifdef WIN32
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}
#endif