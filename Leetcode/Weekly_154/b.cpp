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
	string reverseParentheses(string s)
	{
		int n = s.length();
		// string s;
		// int start = 0, end = n - 1;
		int cnt = 0;
		stack<int> S;
		queue<int> q;
		string res = s;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == '(')
				S.push(i);
			if (s[i] == ')')
				q.push(i);
			if (q.size())
			{
				while (!q.empty())
				{
					auto top = S.top();
					S.pop();
					auto end = q.front();
					db(top, end);
					q.pop();
					reverse(res.begin() + top, res.begin() + end);
				}
			}
			// cnt += s[i] == '(';
		}
		// pc(S);
		// pc(Q);
		s = res;
		while (!S.empty())
		{
			auto top = S.top();
			S.pop();
			auto end = q.front();
			db(top, end);
			q.pop();
			reverse(s.begin() + top, s.begin() + end);
		}
		string ret;
		for (auto c : s)
			if (c != '(' && c != ')')
				ret += c;
		return ret;
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
	cout << S.reverseParentheses("(abcd)") << '\n';
	cout << S.reverseParentheses("(u(love)i)") << '\n';
	cout << S.reverseParentheses("(ed(et(oc))el)") << '\n';
	cout << S.reverseParentheses("a(bcdefghijkl(mno)p)q") << '\n';
	cout << S.reverseParentheses("ta()usw((((a))))") << '\n';
	cout << S.reverseParentheses("n(ev(t)((()lfevf))yd)cb()") << '\n';
#ifdef WIN32
	// cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}
#endif