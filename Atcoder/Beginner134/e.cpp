//Optimise
#include <bits/stdc++.h>
using namespace std;

// #define multitest 1
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
auto TimeStart = chrono::steady_clock::now();

const int nax = 5e3 + 10;
pair<int, pair<int, int>> Edges[nax];
int n, m, p, u, v, w;

void solve()
{
	cin >> n >> m >> p;
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v >> w;
		Edges[i] = {v, {u, w - p}};
	}
	vector<vector<ll>> dp(2, vector<ll>(n + 1, -1e18));
	bool curr, prev;
	prev = true;
	curr = false;
	dp[prev][1] = 0;
	for (int step = 1; step < 5 * n; ++step)
	{
		for (int i = 0; i < m; ++i)
		{
			int parent = Edges[i].s.f;
			int cost = Edges[i].s.s;
			int child = Edges[i].f;
			dp[curr][child] = max(dp[curr][child], cost + dp[prev][parent]);
		}
		prev = !prev;
		curr = !curr;
	}
	ll here = max(dp[curr][n], dp[prev][n]);
	for (int step = 1; step < 5 * n; ++step)
	{
		for (int i = 0; i < m; ++i)
		{
			int parent = Edges[i].s.f;
			int cost = Edges[i].s.s;
			int child = Edges[i].f;
			dp[curr][child] = max(dp[curr][child], cost + dp[prev][parent]);
		}
		prev = !prev;
		curr = !curr;
	}
	ll here2 = max(dp[curr][n], dp[prev][n]);
	db(here, here2);
	if (here2 > here)
		cout << -1 << '\n';
	else
		cout << max(here, 0LL) << '\n';
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