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

const int nax = 2e5 + 10, m = 17;
vector<pair<int, int>> Adj[nax];
ll d[nax], dp[1 << m];

void dfs(int node, int par)
{
	for (auto child : Adj[node])
		if (child.f != par)
		{
			d[child.f] = d[node] ^ child.s;
			dfs(child.f, node);
		}
}

const int kmod = 1000000007;

ll mul(ll a, ll b, int mod = kmod)
{
	return a * b % mod;
}

ll power(int base, int index, int mod = kmod)
{
	if (index == 0)
		return 1;
	ll temp = power(base, index / 2, mod);
	temp = mul(temp, temp, mod);
	if (index & 1)
		temp = mul(temp, base, mod);
	return temp;
}

void Transform(ll *x, int n, bool invert)
{
	for (int len = 1; 2 * len <= n; len <<= 1)
	{
		for (int i = 0; i < n; i += 2 * len)
		{
			for (int j = 0; j < len; j++)
			{
				int u = x[i + j], v = x[i + len + j];
				x[i + j] = u + v;
				if (x[i + j] >= mod)
				{
					x[i + j] -= mod;
				}
				x[i + len + j] = u - v;
				if (x[i + len + j] < 0)
				{
					x[i + len + j] += mod;
				}
				if (x[i + len + j] >= mod)
				{
					x[i + len + j] -= mod;
				}
			}
		}
	}
	if (invert)
	{
		int rev_n = power(n, mod - 2);
		for (int i = 0; i < n; i++)
			x[i] = 1LL * x[i] * rev_n % mod;
	}
}

void add_self(ll &a, ll b)
{
	a += b;
	if (a >= mod)
		a -= mod;
}

void solve()
{
	int n, u, v, w;
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		cin >> u >> v >> w;
		Adj[u].pb({v, w});
		Adj[v].pb({u, w});
	}
	dfs(1, -1);
	for (int i = 1; i <= n; ++i)
		dp[d[i]]++;
	Transform(dp, 1 << m, false);
	for (int i = 0; i < (1 << m); ++i)
		dp[i] = (dp[i] * dp[i]) % mod;
	Transform(dp, 1 << m, true);
	ll ans = 0;
	for (int i = 0; i < (1 << m); ++i)
	{
		add_self(ans, mul(dp[i], dp[i]));
		for (int j = 0; j < m; ++j)
			add_self(ans, mul(dp[i], dp[i ^ (1 << j)]));
	}
	cout << ans;
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