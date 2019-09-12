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

void solve()
{
	int n, u, v;
	cin >> n;
	map<pair<int, int>, bool> isEdge;
	vector<vector<int>> Tree(n + 1);
	vector<int> Depth(n + 1, -1), white, black;
	for (int i = 1; i < n; ++i)
	{
		cin >> u >> v;
		Tree[u].pb(v);
		Tree[v].pb(u);
		isEdge[{u, v}] = true;
		isEdge[{v, u}] = true;
	}
	queue<int> Q;
	Q.push(1);
	Depth[1] = 0;
	while (!Q.empty())
	{
		auto top = Q.front();
		Q.pop();
		db(top, Depth[top], Depth[top] % 2);
		if (Depth[top] % 2)
			black.pb(top);
		else
			white.pb(top);
		for (auto child : Tree[top])
			if (Depth[child] < 0)
			{
				Depth[child] = 1 + Depth[top];
				Q.push(child);
			}
	}
	bool found = false;
	pc(white);
	pc(black);
	for (auto &w : white)
	{
		for (auto &b : black)
			if (!isEdge[{w, b}])
			{
				found = true;
				swap(white.back(), w);
				swap(black.front(), b);
				break;
			}
		if (found)
			break;
	}
	if (found)
	{
		for (auto w : white)
			cout << w << ' ';
		for (auto b : black)
			cout << b << ' ';
		cout << '\n';
	}
	else
		cout << -1 << '\n';
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