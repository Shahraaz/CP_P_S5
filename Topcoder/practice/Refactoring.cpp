//Optimise
#include <bits/stdc++.h>
using namespace std;

// #define multitest 1
// #define Debug
#ifdef Debug
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
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
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;

const int nax = 2e5 + 10;

class Refactoring
{
private:
	map<pair<int, int>, int> Dp;
	int solve(int n, int last)
	{
		auto it = Dp.find({n, last});
		if (it != Dp.end())
			return it->s;
		int ret = 0;
		for (int i = last; i * i <= n; ++i)
			if (n % i == 0)
				ret += 1 + solve(n / i, i);
		Dp[{n, last}] = ret;
		return ret;
	}

public:
	int refactor(int n)
	{
		return solve(n, 2);
	}
};

#ifdef Offline
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
	Refactoring S;
	while (t--)
	{
		int n;
		cin >> n;
		cout << S.refactor(n) << '\n';
	}
	return 0;
}
#endif