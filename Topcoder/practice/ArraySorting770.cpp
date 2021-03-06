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

const int nax = 2e3 + 10, WINDOW = 2000 + 10;

int dp[nax][nax];
int dp2[nax][nax];

class ArraySorting
{
public:
	vector<int> arraySort(vector<int> A)
	{
		int n = A.size();
		int MAXVAL = *max_element(A.begin(), A.end());
		for (int i = n - 1; i >= 0; i--)
			for (int currentVal = MAXVAL; currentVal >= 0; --currentVal)
			{
				int this_edit = A[i] != currentVal;
				if (i == n - 1)
				{
					dp[i][currentVal] = dp2[i][currentVal] = this_edit;
					if (currentVal < MAXVAL)
						dp2[i][currentVal] = min(dp2[i][currentVal], dp2[i][currentVal + 1]);
				}
				else
				{
					dp[i][currentVal] = dp2[i][currentVal] = this_edit + dp2[i + 1][currentVal];
					if (currentVal < MAXVAL)
						dp2[i][currentVal] = min(dp2[i][currentVal], dp2[i][currentVal + 1]);
				}
			}
		vector<int> B;
		int prevVal = 1;
		for (size_t i = 0; i < n; i++)
		{
			int best_edits = 3000, bestVal = -1;
			for (size_t currentValue = prevVal; currentValue <= MAXVAL; currentValue++)
			{
				int current_edits = dp[i][currentValue];
				if (current_edits < best_edits)
				{
					best_edits = current_edits;
					bestVal = currentValue;
				}
			}
			B.pb(bestVal);
			prevVal = bestVal;
		}
		return B;
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
bool KawigiEdit_RunTest(int testNum, vector<int> p0, bool hasAnswer, vector<int> p1)
{
	cout << "Test " << testNum << ": ["
		 << "{";
	for (int i = 0; int(p0.size()) > i; ++i)
	{
		if (i > 0)
		{
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	ArraySorting *obj;
	vector<int> answer;
	obj = new ArraySorting();
	clock_t startTime = clock();
	answer = obj->arraySort(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer)
	{
		cout << "Desired answer:" << endl;
		cout << "\t"
			 << "{";
		for (int i = 0; int(p1.size()) > i; ++i)
		{
			if (i > 0)
			{
				cout << ",";
			}
			cout << p1[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t"
		 << "{";
	for (int i = 0; int(answer.size()) > i; ++i)
	{
		if (i > 0)
		{
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer)
	{
		if (answer.size() != p1.size())
		{
			res = false;
		}
		else
		{
			for (int i = 0; int(answer.size()) > i; ++i)
			{
				if (answer[i] != p1[i])
				{
					res = false;
				}
			}
		}
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

	vector<int> p0;
	vector<int> p1;

	{
		// ----- test 0 -----
		int t0[] = {10, 8};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = {1, 8};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		int t0[] = {6, 9};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = {6, 9};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		int t0[] = {9, 8, 10, 4};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = {1, 8, 10, 10};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		int t0[] = {3, 7, 7, 7, 6};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = {3, 7, 7, 7, 7};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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