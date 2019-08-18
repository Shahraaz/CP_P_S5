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

const int nax = 1e4 + 10;
map<ll, int> Dp;
vector<int> Cumm(nax);

void solve(int i, int j)
{
	int start = i, end = j;
	if (i > j)
	{
		start = j;
		end = i;
	}
	int maxElem = 0;
	while (start <= end)
	{
		maxElem = max(maxElem, Cumm[start]);
		++start;
	}
	cout << i << ' ' << j << ' ' << maxElem << '\n';
}

int solve(ll i)
{
	auto it = Dp.find(i);
	if (it != Dp.end())
		return it->s;
	auto temp = 0;
	// db(i);
	if (i % 2)
		temp = 1 + solve(i * 3 + 1);
	else
		temp = 1 + solve(i / 2);
	return Dp[i] = temp;
}

void pre()
{
	// db("Start");
	Dp[1] = 1;
	Dp[0] = 0;
	// db("Start");
	for (int i = 0; i < nax; ++i)
		Cumm[i] = solve(i);
	// Cumm[0] = Dp[0];
	// for (int i = 1; i < nax; ++i)
	// Cumm[i] = Dp[i];
	// db("End");
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	pre();
#ifdef multitest
	cin >> t;
#endif
	int i, j;
	while (cin >> i >> j)
		solve(i, j);
#ifdef WIN32
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}