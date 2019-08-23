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

class Tunnel
{
private:
	/* data */
public:
	int minKeystrokes(vector<string> level, int rate)
	{
		int n = level.size(), m = level[0].size(), intmax = mod / 100;
		vector<vector<int>> Dist(n, vector<int>(m, mod));
		vector<vector<int>> Cnt(n, vector<int>(m, mod));
		for (int i = 0; i < m; ++i)
			if (level[0][i] == 'v')
				Dist[0][i] = 0;
		//bool turn = true;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (Dist[i][j] < intmax)
				{
					Cnt[i][j] = min(Cnt[i][j], Dist[i][j]);
					int j1 = j, cc = 0;
					while (cc <= rate && j1)
					{
						if (level[i][j1] == '#')
							break;
						Cnt[i][j1] = min(Cnt[i][j1], cc + Dist[i][j]);
						j1--;
						cc++;
					}
					j1 = j;
					cc = 0;
					while (cc <= rate && j1 < m)
					{
						if (level[i][j1] == '#')
							break;
						Cnt[i][j1] = min(Cnt[i][j1], cc + Dist[i][j]);
						j1++;
						cc++;
					}
				}
			}
			if (i + 1 < n)
				for (int j = 0; j < m; ++j)
				{
					if (level[i + 1][j] != '#')
						Dist[i + 1][j] = min(Dist[i + 1][j], Cnt[i][j]);
				}
		}
		int min = *min_element(Dist[n - 1].begin(), Dist[n - 1].end());
		return min < intmax ? min : -1;
	}
};

#ifdef Offline
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	auto TimeStart = chrono::steady_clock::now();
#ifdef multitest
	cin >> t;
#endif
	// Solver S;
	// while (t--)
	// 	S.Solve();
#ifdef WIN32
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}
#endif