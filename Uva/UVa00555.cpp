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

int getRank(char c)
{
	switch (c)
	{
	case '2':
		return 0;
	case '3':
		return 1;
	case '4':
		return 2;
	case '5':
		return 3;
	case '6':
		return 4;
	case '7':
		return 5;
	case '8':
		return 6;
	case '9':
		return 7;
	case 'T':
		return 8;
	case 'J':
		return 9;
	case 'Q':
		return 10;
	case 'K':
		return 11;
	case 'A':
		return 12;
	default:
		break;
	}
	return mod;
}

int getSuit(char c)
{
	switch (c)
	{
	case 'C':
		return 0;
	case 'D':
		return 1;
	case 'S':
		return 2;
	case 'H':
		return 3;
	default:
		break;
	}
	return mod;
}

bool cmp(string a, string b)
{
	if (a[0] == b[0])
		return getRank(a[1]) < getRank(b[1]);
	return getSuit(a[0]) < getSuit(b[0]);
}

void solve(char c)
{
	string s1, s2;
	cin.ignore();
	getline(cin, s1);
	getline(cin, s2);
	db(c, s1, s2);
	map<char, int> M;
	vector<string> V[4];
	M['S'] = 0;
	M['W'] = 1;
	M['N'] = 2;
	M['E'] = 3;
	char rev[4];
	rev[0] = 'S';
	rev[1] = 'W';
	rev[2] = 'N';
	rev[3] = 'E';
	int cur = (M[c] + 1) % 4;
	for (int i = 0; i < s1.length(); i += 2)
	{
		string temp = "";
		temp = s1[i];
		temp.pb(s1[i + 1]);
		// db(temp, s1[i], s1[i + 1]);
		V[cur].pb(temp);
		cur = (cur + 1) % 4;
	}
	for (int i = 0; i < s2.length(); i += 2)
	{
		string temp = "";
		temp = s2[i];
		temp.pb(s2[i + 1]);
		V[cur].pb(temp);
		cur = (cur + 1) % 4;
	}
	sort(V[0].begin(), V[0].end(),cmp);
	sort(V[1].begin(), V[1].end(),cmp);
	sort(V[2].begin(), V[2].end(),cmp);
	sort(V[3].begin(), V[3].end(),cmp);
	for (int i = 0; i < 4; ++i)
	{
		cout << rev[i] << ":";
		for (auto s : V[i])
			cout << ' ' << s ;
		cout << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
	char c;
	while (cin >> c)
	{
		if (c == '#')
			break;
		solve(c);
	}
#ifdef WIN32
	cerr
		<< "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}