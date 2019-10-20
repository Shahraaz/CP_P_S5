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

void solve(int CaseNo)
{
	int n, h, x, y;
	cin >> n >> h;
	int mid = n / 2;
	ll res = 0;
	vector<ll> one(n), two(n);
	for (int i = 0; i < n; ++i)
		cin >> one[i];
	for (int i = 0; i < n; ++i)
		cin >> two[i];
	// vector<ll> sumOne(1 << n), sumTwo(1 << n);
	// sumOne[0] = sumTwo[0] = 0;
	// for (int mask = 1; mask < (1 << n); ++mask)
	// {
	// 	int i;
	// 	for (i = 0; i < n; ++i)
	// 		if (mask & (1 << i))
	// 			break;
	// 	sumOne[mask] = sumOne[mask ^ (1 << i)] + one[i];
	// 	sumTwo[mask] = sumTwo[mask ^ (1 << i)] + two[i];
	// 	// db(mask, sumOne[mask], sumTwo[mask]);
	// }
	// // ll res = 0;
	// for (int mask = 0; mask < (1 << n); ++mask)
	// {
	// 	int i;
	// 	int maskt = (1 << n) - 1;
	// 	db(mask, sumOne[mask], sumTwo[maskt ^ mask]);
	// 	ll cntOne = sumOne[mask];
	// 	if (cntOne < h)
	// 		continue;
	// 	int cntMask = 0;
	// 	for (i = 0; i < n; ++i)
	// 		if (mask & (1 << i))
	// 			cntMask++;
	// 	ll cntTwo = sumTwo[maskt ^ mask];
	// 	if (cntTwo < h)
	// 		continue;
	// 	res += 1 << cntMask;
	// }
	vector<pair<ll, ll>> Score;
	Score.pb({one[0], 0});
	Score.pb({0, two[0]});
	Score.pb({one[0], two[0]});
	for (int i = 1; i < n; ++i)
	{
		vector<pair<ll, ll>> temp;
		for (auto elem : Score)
		{
			temp.pb({one[i] + elem.f, elem.s});
			temp.pb({one[i] + elem.f, two[i] + elem.s});
			temp.pb({elem.f, two[i] + elem.s});
		}
		swap(temp, Score);
	}
	for (auto elem : Score)
		if (elem.f >= h && elem.s >= h)
			res++;
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