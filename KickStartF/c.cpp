//Optimise
#include <bits/stdc++.h>
using namespace std;

#define multitest 1
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

int Caso = 0;

int dp[nax][2][2];
class Solver
{
	int n;
	vector<vector<int>> Adj;
	vector<int> Beauty;

	int dfs(int node, int par, bool YouMustGlow, bool YouareCounted)
	{
		if (dp[node][YouMustGlow][YouareCounted] >= 0)
			return dp[node][YouMustGlow][YouareCounted];
		int ret = 0, cnt = 0;
		for (auto child : Adj[node])
			if (child != par)
			{
				cnt++;
				if (YouMustGlow) // Light Ur Self
				{
					ret += Beauty[child] + max(dfs(child, node, 0, 1), dfs(child, node, 1, 1));
				}
				else
				{
					if (YouareCounted)
					{
						ret += Beauty[child] + max(dfs(child, node, 1, 0), dfs(child, node, 0, 1));
					}
					else
					{
						ret += max(dfs(child, node, 0, 0), dfs(child, node, 0, 1));
					}
				}
			}
		return dp[node][YouMustGlow][YouareCounted] = ret;
	}

public:
	Solver()
	{
		cin >> n;
		int u, v;
		Adj = vector<vector<int>>(n + 1);
		Beauty.pb(0);
		for (int i = 0; i < n; ++i)
		{
			cin >> u;
			Beauty.pb(u);
		}
		for (int i = 1; i < n; ++i)
		{
			cin >> u >> v;
			Adj[u].pb(v);
			Adj[v].pb(u);
		}
		Adj[0].pb(1);
		Adj[1].pb(0);
		cout << "Case #" << Caso << ": ";
		memset(dp, -1, sizeof(dp));
		cout << max(dfs(0, -1, 0), Beauty[0] + dfs(0, -1, 1)) << '\n';
	}
};
void solve()
{
	Caso++;
	Solver S;
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