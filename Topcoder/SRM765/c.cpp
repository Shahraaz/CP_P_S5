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

class FixedPointReversals
{
private:
	vector<int> Sort(vector<int> &a)
	{
		int n = a.size(), start = 0;
		vector<int> ret;
		if (n == 0)
			return ret;
		int idx = 0;
		while (n--)
		{
			auto it = min_element(a.begin() + start, a.end()) - a.begin();
			if (it != idx)
			{
				ret.pb(idx);
				ret.pb(it + 1);
				reverse(a.begin() + idx, a.begin() + it);
			}
			idx++;
		}
		return ret;
	}
	/* data */
public:
	vector<int> sort(vector<int> A, int fixed)
	{
		vector<int> left, right;
		for (int i = 0; i < fixed; ++i)
			left.pb(A[i]);
		for (int i = fixed + 1; i < A.size(); ++i)
			right.pb(A[i]);
		auto one = Sort(left);
		auto two = Sort(right);
		auto prev = A[fixed];
		sort(A.begin(), A.end());
		if (A[fixed] != prev)
			return vector<int>(1, -1);
		for (auto i : left)
			cerr << i << ' ';
		cerr << '\n';
		for (auto i : right)
			cerr << i << ' ';
		cerr << '\n';
		return vector<int>(1, -1);
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
	Solver S;
	while (t--)
		S.Solve();
#ifdef WIN32
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}
#endif