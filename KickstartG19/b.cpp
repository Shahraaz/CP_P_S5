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
	while (*name == ',' || *name == ' ')
		name++;
	std::cerr << name << " { ";
	for (const auto &v : arg)
		cerr << v << ' ';
	cerr << " }\n";
}
template <typename Arg1, typename... Args>
void PC(const char *names, Arg1 &&arg1, Args &&... args)
{
	while (*names == ',' || *names == ' ')
		names++;
	const char *comma = strchr(names, ',');
	std::cerr.write(names, comma - names) << " { ";
	for (const auto &v : arg1)
		cerr << v << ' ';
	cerr << " }\n";
	PC(comma, args...);
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
auto TimeStart = chrono::steady_clock::now();

const int nax = 2e5 + 10, mod = 1000000007;
ll bitCnt[65], MInfo[65];

void solve(int CaseNo)
{
	ll x, n, m;
	cin >> n >> m;
	memset(bitCnt, 0, sizeof(bitCnt));
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		for (int j = 0; j < 63; ++j)
			if (x & (1LL << j))
				bitCnt[j]++;
	}
	// for (int j = 0; j < 63; ++j)
	// 	if (m & (1LL << j))
	// 		MInfo[j]++;
	ll res = 0, sum = 0;
	// for (int j = 62; j >= 0; --j)
	const int lim = 20;
	vector<ll> ONE(lim), ZERO(lim);
	vector<bool> who(lim);
	for (int j = 0; j < lim; ++j)
	{
		ll temp = n - bitCnt[j];
		ll one = temp * (1LL << j);
		ll zero = bitCnt[j] * (1LL << j);
		ZERO[j] = zero;
		ONE[j] = one;
		db(j, bitCnt[j], zero, one);
		if (one <= zero)
		{
			who[j] = 1;
			sum += one;
		}
		else
		{
			who[j] = 0;
			sum += zero;
		}
	}
	pc(ONE, ZERO, who);
	if (sum > m)
	{
		cout << "Case #" << CaseNo << ": " << -1 << '\n';
		return;
	}
	for (int j = lim - 1; j >= 0; --j)
	{
		if (who[j] == 0)
		{
			ll newSum = sum - ZERO[j] + ONE[j];
			if (newSum <= m)
			{
				sum = newSum;
				res += 1LL << j;
			}
		}
		else
		{
			res += 1LL << j;
		}
	}
	cout << "Case #" << CaseNo << ": " << res << '\n';
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
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve(i + 1);
#ifdef WIN32
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}