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
int n, k, a[200], dp[101][101][1001];

int solve(int index, int disOrder, int prevHt)
{
	if (disOrder > k)
		return mod;
	if (index == n)
		return 0;
	int &ret = dp[index][disOrder][prevHt];
	if (ret >= 0)
		return ret;
	ret = INT_MAX;
	if (index == n - 1)
	{
		if (a[index] == prevHt)
			return ret = 0;
		else
			return ret = min(1 + solve(index + 1, disOrder, a[index]), solve(index + 1, disOrder + 1, a[index]));
	}
	int curr = a[index], next = a[index + 1];
	if (prevHt == curr)
	{
		if (next == curr)
		{
			ret = solve(index + 1, disOrder, curr);
		}
		else
		{
			ret = solve(index + 1, disOrder, curr);
		}
	}
	return ret;
}

void solve()
{
	++Caso;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	memset(dp, -1, sizeof(dp));
	int res = INT_MAX;
	for (int i = 1; i <= 1000; ++i)
	{
		if (i == a[0])
			res = min(res, solve(1, 0, a[0]));
		else
			res = min(res, 1 + solve(1, 0, i));
	}
	cout << "Case #" << Caso << ": ";
	cout << res << '\n';
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