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

const int nax = 1e5 + 10;

vector<int> Adj[nax];

int _n = 1e5 + 10;
vector<int> Fact(_n), Inv(_n);
const int kmod = 1000000007;

int mul(int a, int b, int mod = kmod)
{
	return (long long)a * b % mod;
}

int power(int base, int index, int mod = kmod)
{
	if (index == 0)
		return 1;
	int temp = power(base, index / 2, mod);
	temp = mul(temp, temp, mod);
	if (index & 1)
		temp = mul(temp, base, mod);
	return temp;
}

void pre()
{
	Fact[0] = 1;
	for (int i = 1; i < _n; ++i)
		Fact[i] = mul(Fact[i - 1], i);
	Inv[_n - 1] = power(Fact[_n - 1], kmod - 2);
	for (int i = _n - 2; i >= 0; --i)
		Inv[i] = mul(Inv[i + 1], (1 + i));
}

int ncr(int n, int r)
{
	if (n < 0 || r < 0 || n - r < 0)
		return 0;
	return mul(Fact[n], mul(Inv[r], Inv[n - r]));
}

vector<bool> Vis(nax);
vector<int> subTreeSize(nax);

void computeSubtree(int root)
{
	Vis[root] = true;
	for (auto it : Adj[root])
		if (!Vis[it])
		{
			computeSubtree(it);
			subTreeSize[root] += subTreeSize[it];
		}
	subTreeSize[root]++;
	Vis[root] = false;
}

int answer = 0;
void add_self(int &a, int b)
{
	a += b;
	if (a >= mod)
		a -= mod;
}

int n, u, v;
void Solve(int node, int sum)
{
	add_self(answer, sum);
	Vis[node] = true;
	for (auto it : Adj[node])
		if (!Vis[it])
			Solve(it,mul(mul(sum,subTreeSize[it]),Inv[n-subTreeSize[it]]));
	Vis[node] = false;
}

void solve()
{
	pre();
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		cin >> u >> v;
		--u;
		--v;
		Adj[u].pb(v);
		Adj[v].pb(u);
	}
	const int root = 0;
	computeSubtree(root);
	int rootAnswer = Fact[n];
	for (int i = 0; i < n; ++i)
		rootAnswer = mul(rootAnswer, Inv[subTreeSize[i]]);
	Solve(root, rootAnswer);
	cout << answer << '\n';
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