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

const int nax = 3e5 + 10, mod = 1000000007;
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
		if (size() == 0)
			return -(ll)1e15;
		auto l = lower_bound(x);
		db(x, *l, -(l->k * x + l->m));
		return -(l->k * x + l->m);
	}
};

vector<lineContainer> tree(4 * nax);

void update(int node, int start, int end, int pos, ll slope, ll constant)
{
	if (start <= pos && pos <= end)
		tree[node].add(slope, constant);
	if (start == end)
	{
		return;
	}
	int mid = (start + end) / 2;
	if (pos <= mid)
		update(2 * node, start, mid, pos, slope, constant);
	else
		update(2 * node + 1, mid + 1, end, pos, slope, constant);
}

ll query(int node, int start, int end, int qstart, int qend, ll pos)
{
	if (start > end || qend < start || end < qstart)
		return 1e15;
	if (start <= qstart && qend <= end)
		return tree[node].query(pos);
	int mid = (start + end) / 2;
	return min(query(2 * node, start, mid, qstart, qend, pos), query(2 * node + 1, mid + 1, end, qstart, qend, pos));
}

void solve(int caseNo)
{
	int n;
	cin >> n;
	vector<ll> p(n), h(n), a(n);
	vector<pair<int, int>> srt;
	int cnt = 0;
	for (auto &x : p)
	{
		cin >> x;
		--x;
		srt.pb({x, cnt++});
	}
	sort(srt.begin(), srt.end());
	for (auto &x : a)
		cin >> x;
	for (auto &x : h)
		cin >> x;
	update(1, 0, n - 1, p[0], 2 * h[0], -a[0] - h[0] * h[0]);
	ll prev = 0;
	for (int i = 1; i < n; ++i)
	{
		int idx = srt[i].s;
		int H = h[idx];
		int P = p[idx];
		prev = query(1, 0, n - 1, 0, idx - 1, H) + a[i] + h[idx] * h[idx];
		db(i, prev, P, H);
		update(1, 0, n - 1, idx, 2 * h[idx], -prev - h[idx] * h[idx]);
	}
	cout << prev << '\n';
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