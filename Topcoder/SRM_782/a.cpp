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

double calcEven[1 << 13];
vector<vector<vector<int>>> ways(14);
class EmptyTheBox
{
	int d;
	double solve(int mask)
	{
		if (mask == 0)
			return 0;
		double &ret = calcEven[mask];
		if (ret >= 0)
			return ret;
		set<int> avail;
		int sum = 0;
		for (size_t i = 0; i < 13; i++)
			if (mask & (1 << i))
			{
				avail.insert(i + 1);
				sum += i + 1;
			}
		vector<bool> explored(2 * d + 1);
		vector<double> result(2 * d + 1);
		ret = 0;
		for (int i = 1; i <= d; i++)
		{
			for (int j = 1; j <= d; j++)
			{
				if (explored[i + j])
				{
					ret += result[i + j];
					continue;
				}
				explored[i + j] = true;
				double tempBest = sum;
				for (auto &e : ways[i + j])
				{
					bool ok = true;
					int nMask = mask;
					for (auto &x : e)
					{
						if (avail.count(x) == 0)
						{
							ok = false;
							break;
						}
						nMask ^= (1 << (x - 1));
					}
					if (ok)
						tempBest = min(tempBest, solve(nMask));
				}
				result[i + j] = tempBest;
				// db(i + j, mask, tempBest);
				// pc(avail);
				ret += tempBest;
			}
		}
		ret /= d;
		ret /= d;
#ifdef LOCAL
		db(ret);
		pc(avail);
#else

#endif
		return ret;
	}
	void init()
	{
		ways[0].pb({});
		for (int val = 1; val <= 13; val++)
		{
			for (int x = 1; x <= 13; x++)
			{
				if (val - x >= 0)
				{
					for (auto w : ways[val - x])
					{
						if (count(w.begin(), w.end(), x) == 0)
						{
							if (w.size() && w.back() > x)
								continue;
							w.pb(x);
							ways[val].pb(w);
						}
					}
					// db(ways[val].size());
				}
			}
#ifdef LOCAL
			db(val);
			for (auto &w : ways[val])
			{
				pc(w);
			}
#else

#endif
		}
	}

public:
	double minExpectedPenalty(int D, int T)
	{
		d = D;
		init();
		int extra = T - 13;
		extra = max(extra, 0);
		T = min(T, 13);
		memset(calcEven, -1, sizeof calcEven);
		return extra + solve((1 << (T)) - 1);
	}
};

#ifndef LOCAL
//
#endif

#ifdef LOCAL
int main()
{
	EmptyTheBox E;
	cout << E.minExpectedPenalty(2, 3) << '\n';
	return 0;
}
#endif
// <%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!