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

const int nax = 2e5 + 10;

vector<ll> find_fact(ll n)
{
	vector<ll> ret;
	for (ll i = 1; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			if (n == i * i)
			{
				ret.pb(i);
			}
			else
			{
				ret.pb(i);
				ret.pb(n / i);
			}
		}
	}
	sort(ret.begin(), ret.end());
	return ret;
}

bool is_prime(ll n)
{
	if (n <= 3)
		return true;
	if (n % 2 == 0)
		return false;
	for (ll i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;
	return true;
}

void solve()
{
	ll a, b;
	cin >> a >> b;
	a = __gcd(a, b);
	auto fact = find_fact(a);
	pc(fact);
	int n = fact.size(), res = 0;
	// for (int i = 0; i < (1 << n); ++i)
	// {
	// 	vector<ll> nums;
	// 	for (int j = 0; j < 30; ++j)
	// 		if (i & (1 << j));
	// }
	// db(n);
	for (int i = 0; i < n; ++i)
	{
		if (is_prime(fact[i]))
			res++;
	}
	std::cout << res << '\n';
}

int main()
{
#ifndef WIN32
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#endif
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
	while (t--)
		solve();
#ifdef WIN32
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
	flush(cout);
#endif
	return 0;
}