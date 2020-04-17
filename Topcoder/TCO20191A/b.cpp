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

class EllysCodeConstants
{
public:
	string getLiteral(string candidate)
	{
		if (candidate.size() == 0)
			return "";
		map<char, char> mp;
		set<string> suff = {"L", "LL", "U", "UL", "ULL", "LU", "LLU"};
		mp['O'] = '0';
		mp['I'] = '1';
		mp['Z'] = '2';
		mp['S'] = '5';
		mp['T'] = '7';
		mp['A'] = 'A';
		mp['B'] = 'B';
		mp['C'] = 'C';
		mp['D'] = 'D';
		mp['E'] = 'E';
		mp['F'] = 'F';
		string str;
		str = "0x";
		int prefLen = 0;
		for (size_t i = 0; i < candidate.size(); i++)
		{
			if ('0' <= candidate[i] && candidate[i] <= '9')
			{
				prefLen++;
				str += candidate[i];
			}
			else if (mp.find(candidate[i]) == mp.end())
			{
				if (suff.count(candidate.substr(i)))
				{
					if (prefLen)
						return str + candidate.substr(i);
				}
				return "";
			}
			else
			{
				str += mp[candidate[i]];
				prefLen++;
			}
		}
		if (prefLen)
			return str;
		return "";
	}
};

#ifndef LOCAL
//<%:testing-code%>
#endif

#ifdef LOCAL
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1)
{
	cout << "Test " << testNum << ": ["
		 << "\"" << p0 << "\"";
	cout << "]" << endl;
	EllysCodeConstants *obj;
	string answer;
	obj = new EllysCodeConstants();
	clock_t startTime = clock();
	answer = obj->getLiteral(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer)
	{
		cout << "Desired answer:" << endl;
		cout << "\t"
			 << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t"
		 << "\"" << answer << "\"" << endl;
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

	string p0;
	string p1;

	{
		// ----- test 0 -----
		p0 = "DEADBEEF";
		p1 = "0xDEADBEEF";
		all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		p0 = "BABACECA";
		p1 = "0xBABACECA";
		all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		p0 = "TOPCODER";
		p1 = "";
		all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		p0 = "FLU";
		p1 = "0xFLU";
		all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		p0 = "FULL";
		p1 = "0xFULL";
		all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 5 -----
		p0 = "FALL";
		p1 = "0xFALL";
		all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 6 -----
		p0 = "TASTEFUL";
		p1 = "0x7A57EFUL";
		all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 7 -----
		p0 = "OFFICIAL";
		p1 = "0x0FF1C1AL";
		all_right = KawigiEdit_RunTest(7, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 8 -----
		p0 = "OOZE";
		p1 = "0x002E";
		all_right = KawigiEdit_RunTest(8, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 9 -----
		p0 = "ESPRIT";
		p1 = "";
		all_right = KawigiEdit_RunTest(9, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 10 -----
		p0 = "COOL";
		p1 = "0xC00L";
		all_right = KawigiEdit_RunTest(10, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 11 -----
		p0 = "DISEASE";
		p1 = "0xD15EA5E";
		all_right = KawigiEdit_RunTest(11, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 12 -----
		p0 = "SOLVED";
		p1 = "";
		all_right = KawigiEdit_RunTest(12, p0, true, p1) && all_right;
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