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
int n, m;
vector<int> Adj[nax];
bool inPath[nax];
int notChoosable[nax];
stack<int> Q;

void solve(int i, int par = -1)
{
	// pc(notChoosable)
	int inp = 0;
	for (auto c : Adj[i])
	{
		// db(i, par, c, notChoosable[c]);
		if (notChoosable[c])
			return;
		inp += inPath[c];
	}
	for (auto c : Adj[i])
		if (inPath[c])
		{
			stack<int> SS;
			while (Q.top() != c)
			{
				db(Q.top());
				SS.push(Q.top());
				Q.pop();
			}
			SS.push(c);
			cout << SS.size() << '\n';
			while (!SS.empty())
			{
				cout << SS.top() + 1 << '\n';
				SS.pop();
			}
			exit(0);
		}
	// db(i, par, inp);
	if (inp >= 2)
		return;
	for (auto c : Adj[i])
			notChoosable[c]++;
	for (auto c : Adj[i])
		{
			notChoosable[c]--;
			// db(i, c, notChoosable[c]);
			if (notChoosable[c] == 0)
			{
				// db(i,c,par);
				inPath[c] = true;
				Q.push(c);
				solve(c, i);
				Q.pop();
				inPath[c] = false;
			}
			notChoosable[c]++;
		}
	for (auto c : Adj[i])
			notChoosable[c]--;
}

void solve()
{
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		--x;
		--y;
		Adj[x].pb(y);
	}
	for (int i = 0; i < n; ++i)
	{
		inPath[i] = true;
		Q.push(i);
		solve(i);
		Q.pop();
		inPath[i] = false;
	}
	cout << -1 << '\n';
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