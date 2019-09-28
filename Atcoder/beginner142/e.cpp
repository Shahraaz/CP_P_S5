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
vector<int> Unlock[nax];
int cost[nax];
ll dp[1 << 12][1000 + 10];
int n, m, a, b, c;

ll solve(int mask, int index)
{
	if (index == m)
	{
		// mask = __builtinpopcount(mask);
		if (mask == ((1 << n) - 1))
			return 0;
		else
			return INT_MAX;
	}
	if (mask == ((1 << n) - 1))
		return 0;
	ll ret = dp[mask][index];
	if (ret >= 0)
		return ret;
	ret = 0;
	ret = solve(mask, index + 1);
	ll nmask = mask;
	for (auto u : Unlock[index])
		nmask |= (1 << u);
	ret = min(ret, cost[index] + solve(nmask, index + 1));
	dp[mask][index] = ret;
	return ret;
}

void solve()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		cost[i] = a;
		for (int j = 0; j < b; ++j)
		{
			cin >> c;
			Unlock[i].pb(c - 1);
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << (solve(0, 0) >= INT_MAX ? -1 : solve(0, 0)) << '\n';
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