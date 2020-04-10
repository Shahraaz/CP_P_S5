//Optimise
#include <bits/stdc++.h>
using namespace std;

#define Debug
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

using ld = long double;

ld dp[101][101 * 101 / 2];
int vis[101][101 * 101 / 2];

class BeatTheStar
{
	int N, G;
	ld res = 0;
	bool b;
	ld simulation(int idx, int myScore)
	{
		if (idx == N + 1)
		{
			int hisScotr = N * (N + 1) / 2 - myScore;
			if (myScore > hisScotr)
				return 1;
			else
				return 0;
		}
		if (vis[idx][myScore])
			return dp[idx][myScore];
		ld &ret = dp[idx][myScore];
		vis[idx][myScore] = true;
		if (idx == G)
			ret = simulation(idx + 1, b * idx + myScore);
		else
		{
			ret = simulation(idx + 1, myScore) + simulation(idx + 1, myScore + idx);
			ret /= 2;
		}
		return ret;
	}

public:
	double doesItMatter(int N, int G)
	{
		this->N = N;
		this->G = G;
		b = false;
		memset(vis, 0, sizeof vis);
		ld a = simulation(0, 0);
		this->G = G;
		memset(vis, 0, sizeof vis);
		b = true;
		ld b = simulation(0, 0);
		db(a, b);
		db(b - a);
		// cout << res << '\n';
		return abs(b-a);
	}
};

#ifndef LOCAL
//<%:testing-code%>
#endif

#ifdef LOCAL
int main()
{
	for (size_t i = 0; i < 5; i++)
	{
		int n, g;
		cin >> n >> g;
		BeatTheStar b;
		b.doesItMatter(n, g);
	}
	return 0;
}
#endif
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!