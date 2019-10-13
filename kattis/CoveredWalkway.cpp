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
	while (*name == ',' || *name == ' ')
		name++;
	std::cerr << name << " { ";
	for (const auto &v : arg)
		cerr << v << ' ';
	cerr << " }\n";
}
template <typename Arg1, typename... Args>
void PC(const char *names, Arg1 &&arg1, Args &&... args)
{
	while (*names == ',' || *names == ' ')
		names++;
	const char *comma = strchr(names, ',');
	std::cerr.write(names, comma - names) << " { ";
	for (const auto &v : arg1)
		cerr << v << ' ';
	cerr << " }\n";
	PC(comma, args...);
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

using ld = double;

struct Bag
{
	int x;
	ll prevCost;
	Bag(int xx, ll pp) : x(xx), prevCost(pp) {}
	ll getCost(ll y)
	{
		return (x - y) * (x - y) + prevCost;
	}
	ld getCostutil(ld y)
	{
		return (x - y) * (x - y) + prevCost;
	}
	ld to(Bag rhs)
	{
		ld low = rhs.x, high = rhs.x;
		while (getCost(high) < rhs.getCost(high))
		{
			/* code */
			low = high + 1;
			high *= 2;
		}
		int itr = 100;
		while (low < high && --itr)
		{
			auto mid = (low + high) / 2;
			if (getCostutil(mid) >= rhs.getCostutil(mid))
				high = mid;
			else
				low = mid;
		}
		return high;
	}
};

void solve()
{
	int n, c, x;
	cin >> n >> c;
	ll bestprev = 0;
	vector<Bag> BigBag(n, Bag(0, 0));
	int fptr, bptr;
	fptr = bptr = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		Bag b(x, bestprev + c);
		while (bptr - fptr >= 2 && BigBag[bptr - 2].to(BigBag[bptr - 1]) >= BigBag[bptr - 2].to(b))
			--bptr;
		BigBag[bptr++] = b;
		while (fptr + 1 < bptr && BigBag[fptr].getCost(x) >= BigBag[fptr + 1].getCost(x))
			++fptr;
		bestprev = BigBag[fptr].getCost(x);
	}
	std::cout << bestprev << '\n';
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
#endif
	return 0;
}