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

class MahdiJumping
{
private:
	/* data */
public:
	long long minDis(int n, ll A, ll B, int a, int b)
	{
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
		Q.push({0, 0});
		vector<bool> vis(n);
		vector<ll> Dist(n, 1e16);
		Dist[0] = 0;
		while (!Q.empty())
		{
			auto top = Q.top();
			Q.pop();
			if (vis[top.s])
				continue;
			vis[top.s] = true;
			if (top.s == n - 1)
				break;
			int next = top.s + 1;
			if (Dist[next] > Dist[top.s] + a)
			{
				Dist[next] = Dist[top.s] + a;
				Q.push({Dist[next], next});
			}
			next = (A * top.s + B) % n;
			if (Dist[next] > Dist[top.s] + b)
			{
				Dist[next] = Dist[top.s] + b;
				Q.push({Dist[next], next});
			}
		}
		return Dist[n - 1];
	}
};

#ifdef WIN32
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	auto TimeStart = chrono::steady_clock::now();
#ifdef multitest
	cin >> t;
#endif
	Solver S;
	while (t--)
		S.Solve();
#ifdef WIN32
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}
#endif