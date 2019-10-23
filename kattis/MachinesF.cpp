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

struct Machine
{
	ll day, price, resale, moneyPerDay;
	Machine()
	{
		cin >> day >> price >> resale >> moneyPerDay;
	}
	bool operator<(const Machine &rhs) const
	{
		return day < rhs.day;
	}
};

bool Q;
ll _p;
struct Line
{
	mutable long long k, m;
	mutable function<const Line *()> succ;
	bool operator<(const Line &o) const
	{
		if (!Q)
			return k > o.k;
		const Line *s = succ();
		if (s == nullptr)
			return false;
		return (m + k * _p) < (s->m + s->k * _p);
	}
};

ostream &operator<<(ostream &out, const Line &p)
{
	out << "slope " << p.k << " constant " << p.m << ' ';
	return out;
}
//Max Query

struct lineContainer : multiset<Line>
{
	bool bad(iterator y)
	{
		auto z = next(y);
		if (y == begin())
		{
			if (z == end())
				return false;
			return y->k == z->k && y->m <= z->m;
		}
		auto x = prev(y);
		if (z == end())
			return y->k == x->k && y->m <= x->m;
		return 1.0L * (x->m - y->m) * (y->k - z->k) >= 1.0L * (y->k - x->k) * (z->m - y->m);
	}
	void add(long long k, long long m)
	{
		auto y = insert({k, m});
		y->succ = [=] { return next(y) == end() ? nullptr : &*(next(y)); };
		if (bad(y))
		{
			erase(y);
			pc(*this);
			return;
		}
		while (next(y) != end() && bad(next(y)))
			erase(next(y));
		while (y != begin() && bad(prev(y)))
			erase(prev(y));
		pc(*this);
	}
	long long query(long long x)
	{
		Q = true;
		_p = x;
		auto l = lower_bound(Line({0, 0}));
		Q = false;
		db(x, *l, l->k * x + l->m);
		return l->k * x + l->m;
	}
};

int tc = 0;
bool solve()
{
	int n, c, f;
	cin >> n;
	cin >> c >> f;
	if (n == 0)
		return false;
	vector<Machine> machines(n);
	sort(machines.begin(), machines.end());
	ll maxMoney = c;
	lineContainer l;
	l.add(0, 0);
	for (auto machine : machines)
	{
		maxMoney = max(maxMoney, l.query(machine.day));
		db(maxMoney);
		if (maxMoney < machine.price)
			continue;
		ll newRem = maxMoney - machine.price + machine.resale - machine.moneyPerDay * (machine.day + 1);
		l.add(machine.moneyPerDay, newRem);
	}
	maxMoney = max(maxMoney, l.query(f + 1));
	std::cout << "Case " << ++tc << ": " << maxMoney << '\n';
	return true;
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
	while (solve())
		;
#ifdef WIN32
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}