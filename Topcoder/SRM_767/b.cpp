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

class ArpaKonkoori
{
private:
	vector<ll> factors(ll n)
	{
		vector<ll> ret;
		ret.pb(1);
		ret.pb(n);
		for (ll i = 2; i * i <= n; ++i)
		{
			if (n % i == 0)
			{
				ret.pb(i);
				ret.pb(n / i);
			}
		}
		sort(ret.begin(), ret.end());
		ret.erase(unique(ret.begin(), ret.end()), ret.end());
		return ret;
	}
	ll gcd(ll a, ll b)
	{
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

public:
	long long getA(long long d, long long s)
	{
		if (d > sqrt(LLONG_MAX))
			return -1;
		ll td = d;
		d *= d;

		if (s % d != 0 || s < d)
			return -1;
		s /= d;
		auto ret = factors(s);
		ll k1;
		k1 = -1;
		for (auto div : ret)
		{
			ll tempk1 = div + s / div;
			if (tempk1 % 2 == 0)
			{
				tempk1 /= 2;
				ll tempk2 = s / div - div;
				db(tempk1, tempk2);
				if (tempk2 >= 0)
					if (tempk2 % 2 == 0 && gcd(tempk1, tempk2 / 2) <= 1)
					{
						ll temp = tempk1;
						k1 = max(k1, temp * td);
					}
			}
		}
		return k1;
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
	Solver S;
	while (t--)
		S.Solve();
#ifdef WIN32
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}
#endif