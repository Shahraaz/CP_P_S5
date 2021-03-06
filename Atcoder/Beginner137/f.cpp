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
long long mod = 1000000007;
auto TimeStart = chrono::steady_clock::now();

const int nax = 2e5 + 10;

ll pow(ll base, int index)
{
	if (index == 0)
		return 1;
	ll temp = pow(base, index / 2);
	temp = (temp * temp) % mod;
	if (index & 1)
		temp = (temp * base) % mod;
	return temp;
}

ll mul(ll a, ll b)
{
	return a * b % mod;
}

void gauss(vector<vector<ll>> a, vector<ll> &ans)
{
	int n = a.size();
	int row, col;
	row = col = 0;
	vector<int> where(n, -1);
	for (; col < n; ++col, ++row)
	{
		int sel = row;
		for (int i = row + 1; i < n; ++i)
			if (a[i][col] > a[sel][col])
				sel = i;
		for (int i = col; i <= n; ++i)
			swap(a[sel][i], a[row][i]);
		where[col] = row;
		for (int i = 0; i < n; ++i)
			if (i != row)
			{
				ll c = mul(a[i][col], pow(a[row][col], mod - 2));
				for (int j = col; j <= n; ++j)
					a[i][j] = (a[i][j] - a[row][j] * c % mod + mod) % mod;
			}
	}
	for (int i = 0; i < n; ++i)
		ans[i] = mul(a[where[i]][n], pow(a[where[i]][i], mod - 2));
}

void solve()
{
	int p;
	cin >> p;
	mod = p;
	vector<vector<ll>> a(p, vector<ll>(p + 1));
	for (int i = 0; i < p; ++i)
	{
		ll temp = 1;
		for (int j = 0; j < p; ++j)
		{
			a[i][j] = temp;
			temp = mul(temp, i);
		}
		cin >> a[i][p];
	}
	vector<ll> ans(p);
	gauss(a, ans);
	for (auto x : ans)
		cout << x << ' ';
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