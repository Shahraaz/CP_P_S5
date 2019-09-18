#ifdef WIN32
#include <bits/stdc++.h>
using namespace std;
#endif
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

class Solution
{
public:
	int maxNumberOfBalloons(string text)
	{
		map<char, int> V;
		for (int i = 0; i < text.size(); ++i)
			V[text[i]]++;
		int ans = INT_MAX;
		pc(V);

		ans = min(ans, V['b']);
		ans = min(ans, V['a']);
		ans = min(ans, V['n']);
		ans = min(ans, V['l']/2);
		ans = min(ans, V['o']/2);
		// ans = min(ans, V[c] / 2);
		return ans;
	}
};

#ifdef WIN32
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
	Solution S;
	cout << S.maxNumberOfBalloons("nlaebolko") << '\n';
	cout << S.maxNumberOfBalloons("loonbalxballpoon") << '\n';
	cout << S.maxNumberOfBalloons("leetcode") << '\n';
#ifdef WIN32
	// cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}
#endif