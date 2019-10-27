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

vector<pair<int, int>> vec;
vector<ll> one(nax), two(nax);

void solve(int start, int end, ll a, ll b)
{
	if (start == end)
	{
		vec.emplace_back((int)min((ll)mod, a), (int)min((ll)mod, b));
		return;
	}
	solve(start + 1, end, a + one[start], b);
	solve(start + 1, end, a, b + two[start]);
	solve(start + 1, end, a + one[start], b + two[start]);
}

const bool Query = 0, Point = 1;

struct Event
{
	int x, y;
	bool type;
	bool operator<(const Event &rhs) const
	{
		return make_pair(x, make_pair(y, type)) > make_pair(rhs.x, make_pair(rhs.y, rhs.type));
	}
};

struct Node
{
	long long val;
	Node(int one = 0) : val(one) {}
	Node operator+(const Node &rhs)
	{
		Node a = *this;
		a.val = a.val + rhs.val;
		return a;
	}
};
ostream &operator<<(ostream &out, const Node &p)
{
	out << p.val;
	return out;
}
istream &operator>>(istream &in, Node &p)
{
	in >> p.val;
	return in;
}

struct Segtree
{
	vector<Node> Seg, Lazy;
	vector<Node> Base;
	vector<bool> isLazy;
	int n;
	Segtree(int n = 2e5)
	{
		this->n = n;
		Seg.resize(4 * n + 10);
		Lazy.resize(4 * n + 10);
		isLazy.resize(4 * n + 10);
	}
	void merge(Node &curr, Node &l, Node &r)
	{
		curr = l + r;
	}
	void propagate(int node, int L, int R)
	{
		if (isLazy[node])
		{
			isLazy[node] = false;
			Seg[node] = Seg[node] + Lazy[node];
			if (L != R)
			{
				Lazy[2 * node] = Lazy[2 * node] + Lazy[node];
				Lazy[2 * node + 1] = Lazy[2 * node + 1] + Lazy[node];
				isLazy[2 * node] = true;
				isLazy[2 * node + 1] = true;
			}
			Lazy[node] = Node();
		}
	}
	void build(int node, int start, int end)
	{
		if (start == end)
		{
			Seg[node] = Base[start];
			return;
		}
		int mid = (start + end) / 2;
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		merge(Seg[node], Seg[2 * node], Seg[2 * node + 1]);
	}
	void build(vector<Node> &Arr)
	{
		Base = Arr;
		n = Arr.size();
		Seg.resize(4 * n + 10);
		Lazy.resize(4 * n + 10);
		isLazy.resize(4 * n + 10);
		build(1, 0, n - 1);
	}
	Node Query(int node, int start, int end, int qstart, int qend)
	{
		propagate(node, start, end);
		if (qend < start || qstart > end || start > end)
			return Node();
		if (qstart <= start && end <= qend)
			return Seg[node];
		int mid = (start + end) / 2;
		Node l = Query(2 * node, start, mid, qstart, qend);
		Node r = Query(2 * node + 1, mid + 1, end, qstart, qend);
		Node ret;
		merge(ret, l, r);
		return ret;
	}
	Node qQuery(int node, int start, int end, int pos)
	{
		propagate(node, start, end);
		if (start == end)
			return Seg[node];
		int mid = (start + end) / 2;
		if (pos <= mid)
			return qQuery(2 * node, start, mid, pos);
		return qQuery(2 * node + 1, mid + 1, end, pos);
	}
	void Update(int node, int start, int end, int qstart, int qend, Node val)
	{
		propagate(node, start, end);
		if (qend < start || qstart > end || start > end)
			return;
		if (qstart <= start && end <= qend)
		{
			isLazy[node] = true;
			Lazy[node] = val;
			propagate(node, start, end);
			return;
		}
		int mid = (start + end) / 2;
		Update(2 * node, start, mid, qstart, qend, val);
		Update(2 * node + 1, mid + 1, end, qstart, qend, val);
		merge(Seg[node], Seg[2 * node], Seg[2 * node + 1]);
	}
	void pUpdate(int node, int start, int end, int pos, Node val)
	{
		propagate(node, start, end);
		if (start == end)
		{
			isLazy[node] = true;
			// Seg[node] = Node();
			Lazy[node] = val;
			propagate(node, start, end);
			return;
		}
		int mid = (start + end) / 2;
		if (pos <= mid)
			pUpdate(2 * node, start, mid, pos, val);
		else
			pUpdate(2 * node + 1, mid + 1, end, pos, val);
		merge(Seg[node], Seg[2 * node], Seg[2 * node + 1]);
	}
	Node query(int pos)
	{
		return qQuery(1, 0, n - 1, pos);
	}
	Node query(int left, int right)
	{
		return Query(1, 0, n - 1, left, right);
	}
	void update(int pos, Node val)
	{
		pUpdate(1, 0, n - 1, pos, val);
	}
	void update(int start, int end, Node val)
	{
		Update(1, 0, n - 1, start, end, val);
	}
};

void solve(int CaseNo)
{
	int n, h, x, y;
	cin >> n >> h;
	int mid = n / 2;
	ll res = 0;
	for (int i = 0; i < n; ++i)
		cin >> one[i];
	for (int i = 0; i < n; ++i)
		cin >> two[i];
	vec.clear();
	solve(0, mid, 0, 0);
	auto l = vec;
	vec.clear();
	solve(mid, n, 0, 0);
	auto r = vec;
	vector<Event> events;
	vector<int> values;
	for (auto p : l)
	{
		int x = max(0, h - p.f);
		int y = max(0, h - p.s);
		events.pb(Event{x, y, Query});
		values.pb(x);
		values.pb(y);
	}
	for (auto p : r)
	{
		events.pb(Event{p.f, p.s, Point});
		values.pb(p.f);
		values.pb(p.s);
	}
	sort(values.begin(), values.end());
	values.resize(unique(values.begin(), values.end()) - values.begin());
	int maxx = values.size() + 1;
	auto get = [&](int x) {
		return lower_bound(values.begin(), values.end(), x) - values.begin();
	};
	for (auto &e : events)
	{
		e.x = get(e.x);
		e.y = get(e.y);
	}
	sort(events.begin(), events.end());
	Segtree S(maxx);
	for (auto &e : events)
	{
		int y = e.y;
		if (e.type == Query)
			res += S.query(y, maxx).val;
		else
			S.update(y, 1);
	}
	cout << "Case #" << CaseNo << ": " << res << '\n';
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
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve(i + 1);
#ifdef WIN32
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}