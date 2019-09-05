//Optimise
#include <bits/stdc++.h>
using namespace std;

// #define multitest 1
#ifdef WIN32
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
const long long mod = 30011;
auto TimeStart = chrono::steady_clock::now();

const int nax = 2e5 + 10, lim = 65536;
int Data[lim + 11];

void fwht(int *data, int dim)
{
	for (int len = 1; 2 * len <= dim; len *= 2)
		for (int i = 0; i < dim; i += 2 * len)
			for (int j = 0; j < len; ++j)
			{
				int a = data[i + j];
				int b = data[i + j + len];
				data[i + j] = (a + b) % mod;
				data[i + j + len] = (a - b + mod) % mod;
			}
}

ll poww(int base, int index)
{
	if (index == 0)
		return 1;
	ll temp = poww(base, index / 2);
	temp = (temp * temp) % mod;
	if (index & 1)
		return (temp * base) % mod;
	return temp;
}

void solve()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= k; ++i)
		Data[i] = 1;
	fwht(Data, lim);
	for (int i = 0; i < lim; ++i)
		Data[i] = poww(Data[i], n);
	fwht(Data, lim);
	ll inv = poww(lim, mod - 2), ans = 0;
	for (int i = 1; i < lim; ++i)
	{
		ans += ((ll)Data[i] * inv) % mod;
		ans %= mod;
	}
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
	while (t--)
		solve();
#ifdef WIN32
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}