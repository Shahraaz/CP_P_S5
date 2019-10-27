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
auto TimeStart = chrono::steady_clock::now();

const int nax = 2e5 + 10, mod = 1000000007;

struct Line
{
	mutable long long k, m;
	mutable function<const Line *()> succ;
	bool operator<(const Line &o) const
	{
		return k > o.k;
	}
	bool operator<(const long long &_p) const
	{
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

struct lineContainer : multiset<Line, less<>>
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
			// pc(*this);
			return;
		}
		while (next(y) != end() && bad(next(y)))
			erase(next(y));
		while (y != begin() && bad(prev(y)))
			erase(prev(y));
		// pc(*this);
	}
	long long query(long long x)
	{
		auto l = lower_bound(x);
		// db(x, *l, l->k * x + l->m);
		return l->k * x + l->m;
	}
};

struct flight
{
	ll src, dest, start, end, idx;
	bool type;
	bool operator<(const flight &rhs) const
	{
		int a, b;
		if (type)
			a = end;
		else
			a = start;
		if (rhs.type)
			b = rhs.end;
		else
			b = rhs.start;
		return a < b;
	}
};

ostream &operator<<(ostream &out, const flight &p)
{
	out << "src " << p.src << " dest " << p.dest << ' ';
	out << "start " << p.start << " end " << p.end << ' ';
	out << "type " << p.type << ' ';
	return out;
}

void solve(int caseNo)
{
	int n, m, src, dest, start, end;
	cin >> n >> m;
	vector<flight> f(2 * m);
	for (int i = 0; i < m; ++i)
	{
		cin >> src >> dest >> start >> end;
		f[i].src = src;
		f[i].dest = dest;
		f[i].start = start;
		f[i].end = end;
		f[i].type = false;
		f[i + m].src = src;
		f[i + m].dest = dest;
		f[i + m].start = start;
		f[i + m].end = end;
		f[i + m].type = true;
		f[i].idx = i;
		f[i + m].idx = i;
	}
	sort(f.begin(), f.end());
	vector<ll> dp(n + 1, LLONG_MAX);
	vector<lineContainer> LL(n + 1);
	vector<bool> take(m);
	vector<ll> takedp(m + 1, LLONG_MAX);
	LL[1].add(-0, -0);
	for (auto F : f)
	{
		db(F);
		if (F.type) // Landing
		{
			if (take[F.idx])
			{
				LL[F.dest].add(2 * F.end, -takedp[F.idx] - F.end * F.end);
			}
		}
		else //takeoff
		{
			if (LL[F.src].size()) //Anyway waiting
			{
				auto best = LL[F.src].query(F.start);
				take[F.idx] = 1;
				takedp[F.idx] = -best + F.start * F.start;
				db(takedp[F.idx], F.idx);
				dp[F.dest] = min(dp[F.dest], takedp[F.idx]);
			}
		}
	}
	std::cout << dp[n] << '\n';
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
	for (int i = 0; i < t; ++i)
		solve(i);
#ifdef WIN32
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}