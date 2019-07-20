//Optimise
#include <bits/stdc++.h>
using namespace std;

// #define multitest 1
#define Debug
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
const long long mod = 65536;

const int nax = 2e5 + 10;
vector<int> Tree(4 * mod);

class FloatingMedian
{
private:
	ll seed, add, mul;
	ll next()
	{
		ll temp = seed;
		seed *= mul;
		seed += add;
		seed %= mod;
		return temp;
	}
	void update(int node, int start, int end, int pos, int dx)
	{
		if (start == end)
		{
			Tree[node] += dx;
			return;
		}
		int mid = (start + end) / 2;
		if (pos <= mid)
			update(2 * node, start, mid, pos, dx);
		else
			update(2 * node + 1, mid + 1, end, pos, dx);
		Tree[node] = Tree[2 * node] + Tree[2 * node + 1];
	}
	int query(int node, int start, int end, int index)
	{
		db(Tree[node], start, end, index);
		if (start == end)
			return start;
		int mid = (start + end) / 2;
		int left = Tree[node * 2];
		if (left >= index)
			return query(2 * node, start, mid, index);
		return query(2 * node + 1, mid + 1, end, index - left);
	}

public:
	long long sumOfMedians(int seed, int mul, int add, int N, int K)
	{
		this->seed = seed;
		this->mul = mul;
		this->add = add;
		int tab[N];
		for (int i = 0; i < N; ++i)
			tab[i] = next();
		for (int i = 0; i < K; ++i)
			update(1, 0, mod, tab[i], 1);
		ll ans = 0;
		int index = (1 + K) / 2;
		ans = query(1, 0, mod, index);
		for (int i = K; i < N; ++i)
		{
			update(1, 0, mod, tab[i - K], -1);
			update(1, 0, mod, tab[i], 1);
			ll q = query(1, 0, mod, index);
			// db(q, tab[i]);
			ans += q;
		}
		return ans;
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
	Solver S;
	while (t--)
		S.Solve();
	return 0;
}
#endif