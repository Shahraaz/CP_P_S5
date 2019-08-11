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
vector<pair<int, int>> a;
int n, m;

bool solvable(int toGain)
{
	set<int> S;
	for (int i = 1; i <= m; ++i)
		S.insert(i);
	for (int i = 0; i < n; ++i)
	{
		auto it = S.lower_bound(a[i].s);
		if (it != S.end())
		{
			S.erase(it);
			toGain -= a[i].f;
		}
		if (toGain <= 0)
			return true;
	}
	return toGain <= 0;
}

ll solver()
{
	int low = 0, high = mod, ans;
	ans = 0;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (solvable(mid))
		{
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	return ans;
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.f == b.f)
		return a.s < b.s;
	return a.f > b.f;
}

void solve()
{
	cin >> n >> m;
	a = vector<pair<int, int>>(n);
	for (int i = 0; i < n; ++i)
		cin >>
			a[i].s >> a[i].f;
	sort(a.begin(), a.end(), cmp);
	// cout << solve(0, 0) << '\n';
	cout << solver();
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