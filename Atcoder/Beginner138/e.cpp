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

void solve()
{
	string s, t;
	cin >> s >> t;
	vector<bool> h(26), h1(26);
	for (auto c : s)
		h[c - 'a'] = true;
	for (auto c : t)
		h1[c - 'a'] = true;
	for (int i = 0; i < 26; ++i)
		if (h1[i])
			if (!h[i])
			{
				cout << -1;
				return;
			}
	ll len = 0;
	vector<vector<int>> NextOcc(s.size() + 1, vector<int>(26, mod));
	for (int i = s.size() - 1; i >= 0; --i)
	{
		for (int j = 0; j < 26; ++j)
			NextOcc[i][j] = NextOcc[i + 1][j];
		NextOcc[i][s[i] - 'a'] = i;
	}
	int curr = 0;
	for (int i = 0; i < t.size(); ++i)
	{
		int next = NextOcc[curr][t[i] - 'a'];
		db(t[i], len);
		db(curr, i, NextOcc[curr][t[i] - 'a']);
		if (next == mod)
		{
			--i;
			curr = 0;
			len += s.size();
		}
		else
		{
			curr = next + 1;
			if (curr == s.size())
			{
				curr = 0;
				len += s.size();
			}
			// db(t[i], len);
			// db(curr, i, NextOcc[curr][t[i] - 'a']);
		}
	}
	len += curr;
	cout << len;
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