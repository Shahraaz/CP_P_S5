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
	std::cout << name << " { ";
	for (const auto &v : arg)
		cout << v << ' ';
	cout << " }\n";
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

class ForwardMancala
{
	vector<int> a, start;
	int n;
	void ok(int idx)
	{
		a.push_back(idx);
		int hand = start[idx];
		int a, b;
		a = hand / n, b = hand % n;
		start[idx] = 0;
		idx++;
		if (idx == n)
			idx = 0;
		int cnt = 0;
		while (cnt < n)
		{
			++cnt;
			start[idx] += a + (b > 0);
			idx++;
			if (idx == n)
				idx = 0;
			b = b == 0 ? 0 : b - 1;
		}
		db(idx);
		pc(start);
	}

public:
	vector<int> findMoves(vector<int> Start)
	{
		a.clear();
		start = Start;
		n = start.size();
		while (true)
		{
			int idx = -1, mini = INT_MAX;
			//pc(start);
			int cnt = 0;
			for (int i = 0; i < n; ++i)
			{
				cnt += start[i] > 0;
				if (start[i] > 0 && start[i] < mini)
				{
					mini = start[i];
					idx = i;
				}
			}
			if (cnt <= 1)
				break;
			ok(idx);
		}
		pc(start);
		return a;
	}
};

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!