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

class MilkConsumption
{
private:
	/* data */
public:
	vector<int> findMaxRegion(vector<int> population, vector<int> totalConsumption)
	{
		vector<pair<int, int>> V;
		ll num = 0, dem = 1,idx = -1;
		for (int i = 0; i < population.size(); ++i)
		{
			if (num * population[i] < dem * totalConsumption[i])
			{
				num = dem = population[i];
				num = totalConsumption[i];
				idx = i;
			}
		}
		return vector<int>(1,idx);
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