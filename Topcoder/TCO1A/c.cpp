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

const int nax = 50 + 1;

double dp[nax][nax][nax];
bool vis[nax][nax][nax][nax];

// struct mpStr
// {
// 	vector<int> v;
// 	mpStr()
// 	{
// 		v.resize(4);
// 	}
// };

class BlindBoxSets
{
public:
	// bool check(mpStr s)
	// {
	// 	bool ok = vis[s.v[0]][s.v[1]][s.v[2]][s.v[3]];
	// 	return ok;
	// }
	double expectedPurchases(int numSets, int numItems)
	{
		dp[0][0][0] = 0;
		int n = numItems;
		vector<double> ret(5);
		for (int threeCnt = 0; threeCnt <= n; threeCnt++)
			for (int twoCnt = 0; twoCnt <= n; twoCnt++)
			{
				for (int OneCnt = 0; OneCnt <= n; OneCnt++)
				{
					for (int zeroCnt = 0; zeroCnt <= n; zeroCnt++)
					{
						db(zeroCnt, OneCnt, twoCnt, threeCnt, dp[threeCnt][twoCnt][OneCnt]);
						dp[threeCnt][twoCnt][OneCnt + 1] += zeroCnt * (1 + dp[threeCnt][twoCnt][OneCnt]) / numItems;
						dp[threeCnt][twoCnt + 1][OneCnt] += OneCnt * (1 + dp[threeCnt][twoCnt][OneCnt]) / numItems;
						dp[threeCnt + 1][twoCnt][OneCnt] += twoCnt * (1 + dp[threeCnt][twoCnt][OneCnt]) / numItems;
						ret[1] += zeroCnt * (1 + dp[threeCnt][twoCnt][OneCnt]) / numItems;
						if (numSets >= 2)
							ret[2] += OneCnt * (1 + dp[threeCnt][twoCnt][OneCnt]) / numItems;
						if (numSets >= 3)
							ret[3] += twoCnt * (1 + dp[threeCnt][twoCnt][OneCnt]) / numItems;
						if (numSets >= 4)
							ret[4] += threeCnt * (1 + dp[threeCnt][twoCnt][OneCnt]) / numItems;
					}
				}
			}
		return ret[numSets];
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
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, double p2)
{
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	BlindBoxSets *obj;
	double answer;
	obj = new BlindBoxSets();
	clock_t startTime = clock();
	answer = obj->expectedPurchases(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer)
	{
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer)
	{
		res = fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
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

	int p0;
	int p1;
	double p2;

	{
		// ----- test 0 -----
		p0 = 1;
		p1 = 1;
		p2 = 1.0;
		all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		p0 = 1;
		p1 = 2;
		p2 = 3.0;
		all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		p0 = 2;
		p1 = 1;
		p2 = 2.0;
		all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		p0 = 2;
		p1 = 2;
		p2 = 5.5;
		all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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