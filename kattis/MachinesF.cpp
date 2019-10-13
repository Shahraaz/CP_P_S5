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
	int day, price, resale, moneyPerDay;
	Machine()
	{
		cin >> day >> price >> resale >> moneyPerDay;
	}
	bool operator<(const Machine &rhs) const
	{
		return moneyPerDay < rhs.moneyPerDay;
	}
};

bool comp(const Machine &lhs, const Machine &rhs)
{
	return lhs.day < rhs.day;
}

ostream &operator<<(ostream &out, Machine &m)
{
	out << m.day << ' ' << m.price << ' ' << m.resale << ' ' << m.moneyPerDay << ' ';
	return out;
}

struct Sol
{
	int start, moneyPerDay;
	ll prevMoney;
	Sol(int s, int m, ll p) : start(s), moneyPerDay(m), prevMoney(p) {}
	ll moneyEarned(ll day) const
	{
		ll delta = day - start;
		return delta * moneyPerDay + prevMoney;
	}
	bool operator<(const Sol &rhs) const
	{
		return moneyPerDay < rhs.moneyPerDay;
	}
	ll to(Sol rhs) const // slope of this is
	{
		db("Bin Start Phase A");
		ll lo = max(start, rhs.start);
		if(start == rhs.start && moneyPerDay == rhs.moneyPerDay)
			return lo;
		ll high = 0;
		high = lo;
		int itr = 300;
		while (moneyEarned(high) >= rhs.moneyEarned(high) && --itr)
		{
			db(high, moneyEarned(high), rhs.moneyEarned(high));
			lo = high;
			high = 2 * high + 1;
		}
		db("Bin Start Phase B");
		while (lo < high)
		{
			ll mid = (lo + high) / 2;
			if (moneyEarned(mid) >= rhs.moneyEarned(mid))
				lo = mid + 1;
			else
				high = mid;
		}
		db("Bin End");
		return high;
	}
};

int tc = 0;
bool solve()
{
	int n, c, f;
	cin >> n;
	if (n == 0)
		return false;
	cin >> c >> f;
	vector<Machine> machines(n);
	sort(machines.begin(), machines.end(), comp);
	ll maxMoney = c;
	multiset<Sol> hull;
	db("Before Loop over Machines");
	for (auto m : machines)
	{
		db("Before Loop A");
		while (hull.size() >= 2)
		{
			auto fst = hull.begin();
			auto snd = (++hull.begin());
			// fst->moneyEarned
			if (fst->moneyEarned(m.day - 1) > snd->moneyEarned(m.day - 1))
				break;
			hull.erase(hull.begin());
		}
		db("After Loop A");
		if (hull.size() > 0)
			maxMoney = max(maxMoney, hull.begin()->moneyEarned(m.day - 1));
		if (m.price > maxMoney)
			continue;
		ll prevMoney = maxMoney - m.price + m.resale;
		Sol part(m.day, m.moneyPerDay, prevMoney);
		auto same = hull.lower_bound(part);
		if (same != hull.end() && same->moneyPerDay == part.moneyPerDay)
		{
			if (same->moneyEarned(m.day) >= part.moneyEarned(m.day))
				continue;
			hull.erase(same);
		}
		auto above = hull.lower_bound(part);
		if (above != hull.end())
			if (above != hull.begin())
			{
				auto below = --above;
				if (below->to(part) >= below->to(*above))
					continue;
			}
		db("Before Loop B");
		while (true)
		{
			auto up1 = hull.upper_bound(part);
			if (up1 == hull.end())
				break;
			auto up2 = ++up1;
			if (up2 == hull.end())
				break;
			// Check invarient
			ll t1 = part.to(*up1);
			ll t2 = up1->to(*up2);
			if (t1 < t2)
				break;
			hull.erase(up1);
		}
		db("After Loop B");
		db("Before Loop C");
		while (true)
		{
			auto low1 = hull.lower_bound(part);
			if (low1 == hull.begin())
				break;
			low1--;
			if (low1 == hull.begin())
				break;
			auto low2 = --low1;
			ll t1 = low2->to(*low1);
			ll t2 = low1->to(part);
			if (t1 < t2)
				break;
			hull.erase(low1);
		}
		db("After Loop C");
		hull.insert(part);
	}
	db("After Loop over Machines");
	for (auto s : hull)
		maxMoney = max(maxMoney, s.moneyEarned(f));
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