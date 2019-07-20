//Optimise
#include <bits/stdc++.h>
using namespace std;

#define multitest 1
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
auto TimeStart = chrono::steady_clock::now();

const int nax = 2e5 + 10;
string s;

void solve(int t)
{
	cin >> s;
	int n = s.length();
	if (s == "1" || s == "4" || s == "78")
		cout << "+";
	else if (n >= 2 && s[n - 1] == '5' && s[n - 2] == '3')
		cout << "-";
	else if (n >= 2 && s[0] == '9' && s[n - 1] == '4')
		cout << "*";
	else if (n >= 3 && s[0] == '1' && s[1] == '9' && s[2] == '0')
		cout << "?";
	else
		cout << "+";
	// if (t)
	cout << '\n';
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
		solve(t);
#ifdef TIME
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}