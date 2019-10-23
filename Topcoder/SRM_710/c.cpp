//Optimise
#include <bits/stdc++.h>
using namespace std;

// #define multitest 1
// #define Debug
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

const int nax = 2e5 + 10;
using pii = pair<pair<ll, int>, pair<int, int>>;

class MinMaxMax
{
	int n, m;

public:
	long long findMin(vector<int> a, vector<int> b, vector<int> w, vector<int> v)
	{
		n = v.size();
		m = w.size();
		ll res = 0;
		ll mn[n][n], dist[n][n];
		vector<pair<int, int>> V;
		for (int i = 0; i < n; ++i)
		{
			V.pb({v[i], i});
			for (int j = 0; j < n; ++j)
				mn[i][j] = 1LL << 40,
				dist[i][j] = 1LL << 60;
		}
		for (int i = 0; i < m; ++i)
		{
			mn[a[i]][b[i]] = w[i];
			mn[b[i]][a[i]] = w[i];
		}
		sort(V.begin(), V.end());
		for (int e = 0; e < n; ++e)
		{
			ll k = V[e].s;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
				{
					mn[i][j] = min(mn[i][j], max(mn[i][k], mn[k][j]));
					dist[i][j] = min(dist[i][j], mn[i][j] * max(v[k], max(v[i], v[j])));
				}
		}
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				res += dist[i][j];
		return res;
	}
};
//<% : testing - code %>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!