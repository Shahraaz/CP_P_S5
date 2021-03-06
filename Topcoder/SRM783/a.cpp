//Optimise
#include <bits/stdc++.h>
using namespace std;

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

class CardboardBoxes
{
public:
	long long count(long long S)
	{
		if (S & 1)
		{
			return 0;
		}
		S /= 2;
		vector<ll> factors;
		for (ll i = 1; i * i <= S; i++)
		{
			if (S % i == 0)
			{
				factors.pb(i);
				if (i * i != S)
					factors.pb(S / i);
			}
		}
		ll ret = 0;
		for (auto &x : factors)
		{
			ll lplusb = x;
			ll lplush = S / x;
			db(lplusb, lplush);
			if (lplusb > 1 && lplush > 1)
			{
				db(lplusb - 1, lplush - 1, lplusb / 2);
				ret += min({lplusb - 1, lplush - 1, lplusb / 2});
			}
		}
		return ret;
	}
};

#ifndef LOCAL
//<%:testing-code%>
#endif

#ifdef LOCAL
// int main()
// {
// 	return 0;
// }
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, long long p0, bool hasAnswer, long long p1)
{
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	CardboardBoxes *obj;
	long long answer;
	obj = new CardboardBoxes();
	clock_t startTime = clock();
	answer = obj->count(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer)
	{
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer)
	{
		res = answer == p1;
	}
	if (!res)
	{
		cout << "DOESN'T MATCH!!!!" << endl;
	}
	else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2)
	{
		cout << "FAIL the timeout" << endl;
		res = false;
	}
	else if (hasAnswer)
	{
		cout << "Match :-)" << endl;
	}
	else
	{
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main()
{
	bool all_right;
	all_right = true;

	long long p0;
	long long p1;

	{
		// ----- test 0 -----
		p0 = 47ll;
		p1 = 0ll;
		all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		p0 = 470ll;
		p1 = 6ll;
		all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		p0 = 4700ll;
		p1 = 106ll;
		all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
		// ------------------
	}

	if (all_right)
	{
		cout << "You're a stud (at least on the example cases)!" << endl;
	}
	else
	{
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
#endif

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!