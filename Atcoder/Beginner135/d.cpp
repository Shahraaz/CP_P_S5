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

const int nax = 2e5 + 10;
string s;
long long dp[nax][20], n;

long long solve(int index, int prevRem)
{
	if (index == n)
		return prevRem == 5;
	db(index, prevRem);
	auto &ret = dp[index][prevRem];
	if (ret >= 0)
		return ret;
	ret = 0;
	if (s[index] == '?')
	{
		for (int i = 0; i < 10; ++i)
			ret = (ret + solve(index + 1, (prevRem * 10 + i) % 13)) % mod;
	}
	else
		ret = solve(index + 1, (prevRem * 10 + s[index] - '0') % 13);
	db(index, prevRem, ret);
	return ret;
}

void solve()
{
	cin >> s;
	n = s.length();
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';
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
#ifdef TIME
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}