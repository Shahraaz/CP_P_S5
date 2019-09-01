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
auto TimeStart = chrono::steady_clock::now();

const int nax = 2e5 + 10;

void solve()
{
	int n;
	cin >> n;
	vector<queue<int>> Q(n + 1);
	int x;
	set<int> Exist;
	for (int i = 1; i <= n; ++i)
	{
		Exist.insert(i);
		for (int j = 1; j < n; ++j)
		{
			cin >> x;
			Q[i].push(x);
		}
	}
	set<pair<int, int>> Matches;
	for (int i = 1; i <= n; ++i)
	{
		int wish = Q[i].front();
		if (Q[wish].front() == i)
			Matches.insert({i, wish});
	}
	int cnt = 0, over = 0;
	for (int i = 0;; ++i)
	{
		for (auto match : Matches)
		{
			Q[match.f].pop();
			if (Q[match.first].size() == 0)
				over++;
		}
		set<pair<int, int>> MatchesNew;
		for (auto match : Matches)
		{
			if (Q[match.first].size())
			{
				int wish = Q[match.first].front();
				if (Q[wish].size())
				{
					if (Q[wish].front() == match.f)
					{
						MatchesNew.insert({match.f, wish});
						MatchesNew.insert({wish, match.f});
					}
				}
				else
				{
					cout << -1;
					return;
				}
			}
		}
		pc(Matches);
		cnt++;
		if (MatchesNew.size() == 0)
			break;
		// pc(MatchesNew);
		Matches = MatchesNew;
	}
	if (over == n)
		std::cout << cnt;
	else
		cout << -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
	while (t--)
		solve();
#ifdef WIN32
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}