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

const int nax = 1e2 + 10, mod = 1000000007;
int dp[nax][nax][nax][nax];
int ver[nax][nax], hor[nax][nax];

void maxSelf(int &a, int b)
{
	a = max(a, b);
}

void solve(int caseNo)
{
	int n, m, X, Y;
	cin >> n >> m;
	vector<string> s(n);
	db("Start");
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
		for (int j = 0; j < m; ++j)
			if (s[i][j] == 'E')
				X = i, Y = j, s[i][j] = '.';
	}
	db("Start 2");
	for (int i = 0; i < n; ++i)
	{
		hor[i][0] = 0;
		for (int j = 0; j < m; ++j)
			hor[i][j + 1] = hor[i][j] + s[i][j] == 'o';
	}
	db("Start 3");
	for (int i = 0; i < m; ++i)
	{
		ver[0][i] = 0;
		for (int j = 0; j < n; ++j)
			ver[j + 1][i] = ver[j][i] + s[j][i] == 'o';
	}
	db("Start 4");
	int res = 0;
	for (int len1 = 0; len1 < n; len1++)
		for (int len2 = 0; len2 < m; ++len2)
			for (int x1 = 0; x1 + len1 < n; ++x1)
				for (int y1 = 0; y1 + len2 < m; ++y1)
				{
					int x2 = x1 + len1;
					int y2 = y1 + len2;
					db(x1, x2, y1, y2, dp[x1][x2][y1][y2]);
					maxSelf(res, dp[x1][x2][y1][y2]);
					int yL = max(0, y2 - Y);
					int yR = min(m, m + y1 - Y);
					int xL = max(0, x2 - X);
					int xR = min(n, n + x1 - X);
					if (x1 > xL)
						maxSelf(dp[x1 - 1][x2][y1][y2], dp[x1][x2][y1][y2] +
															hor[x1 - 1][min(yR, y2 + 1)] - hor[x1 - 1][max(yL, y1)]);
					if (x2 < xR - 1)
						maxSelf(dp[x1][x2 + 1][y1][y2], dp[x1][x2][y1][y2] +
															hor[x2 + 1][min(yR, y2 + 1)] - hor[x2 + 1][max(yL, y1)]);
					if (y1 > yL)
						maxSelf(dp[x1][x2][y1 - 1][y2], dp[x1][x2][y1][y2] +
															ver[min(xR, x2 + 1)][y1 - 1] - ver[max(xL, x1)][y1 - 1]);
					if (y2 < yR - 1)
						maxSelf(dp[x1][x2][y1][y2 + 1], dp[x1][x2][y1][y2] +
															ver[min(xR, x2 + 1)][y2 + 1] - ver[max(xL, x1)][y2 + 1]);
				}
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
	for (int i = 0; i < t; ++i)
		solve(i);
#ifdef TIME
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}