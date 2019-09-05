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
const long long mod = 1000000007;
auto TimeStart = chrono::steady_clock::now();

const int nax = 2e5 + 10, sz = 1 << 20;
ll n, i, x;
ll Data[sz + 11];

void to_transform(ll dim, ll *data)
{
	ll len, i, j, u, v;
	for (len = 1; 2 * len <= dim; len *= 2)
		for (i = 0; i < dim; i += 2 * len)
			for (j = 0; j < len; ++j)
			{
				u = data[i + j];
				v = data[i + j + len];
				data[i + j] = v;
				data[i + j + len] = (u + v) % mod;
			}
}

void inv_transform(ll dim, ll *data)
{
	ll len, i, j, u, v;
	for (len = 1; 2 * len <= dim; len *= 2)
		for (i = 0; i < dim; i += 2 * len)
			for (j = 0; j < len; ++j)
			{
				u = data[i + j];
				v = data[i + j + len];
				data[i + j] = (v - u + mod) % mod;
				data[i + j + len] = u;
			}
}

ll poww(ll base, ll index)
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
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		Data[x]++;
	}
	Data[0]++;
	to_transform(sz, Data);
	for (int i = 0; i < sz; ++i)
		Data[i] = poww(Data[i], n);
	inv_transform(sz, Data);
	int cnt = 0;
	for (int i = 0; i < sz; ++i)
		cnt += (Data[i] != 0);
	cout << cnt;
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