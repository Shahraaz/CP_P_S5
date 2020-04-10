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

template <typename inpType, int (*func)(int, int)>
struct sparseTree
{
	int n, logLim, def;
	vector<vector<int>> lookup;

	void buildSparseTable(inpType arr, int n, int def)
	{
		this->n = n;
		this->def = def;
		logLim = log2(n) + 1;
		lookup.resize(n, vector<int>(logLim, def));
		// pc(arr);
		for (int i = 0; i < n; i++)
		{
			lookup[i][0] = arr[i];
			// db(i, 0, lookup[i][0]);
		}
		for (int j = 1; (1 << j) <= n; j++)
			for (int i = 0; (i + (1 << j) - 1) < n; i++)
			{
				// db(lookup[i][j - 1], lookup[i + (1 << (j - 1))][j - 1]);
				lookup[i][j] = func(lookup[i][j - 1], lookup[i + (1 << (j - 1))][j - 1]);
				// db(i, j, lookup[i][j]);
			}
	}

	int query(int L, int R)
	{
		if (L < 0 || L > n - 1 || R < 0 || R > n - 1 || L > R)
			return def;
		int j = (int)log2(R - L + 1);
		return func(lookup[L][j], lookup[R - (1 << j) + 1][j]);
	}
};

int min(int a, int b)
{
	return std::min(a, b);
}
int max(int a, int b)
{
	return std::max(a, b);
}

class Prominence
{
	vector<int> getBigggerLeft(vector<ll> H)
	{
		stack<int> s;
		vector<int> ret(H.size());
		for (int i = 0; i < H.size(); i++)
		{
			while (s.size() && H[s.top()] <= H[i])
				s.pop();
			if (s.size())
				ret[i] = s.top();
			else
				ret[i] = -10;
			s.push(i);
		}
		return ret;
	}

	vector<int> getBigggerRight(vector<ll> H)
	{
		reverse(H.begin(), H.end());
		auto ret = getBigggerLeft(H);
		for (size_t i = 0; i < H.size(); ++i)
			ret[i] = H.size() - 1 - ret[i];
		reverse(ret.begin(), ret.end());
		return ret;
	}

public:
	long long sumOfProminences(int N, vector<int> coef, vector<int> idx, vector<int> val)
	{
		vector<ll> H(N);
		for (size_t i = 0; i < N; i++)
		{
			int parity = i % 2;
			int a = coef[3 * parity];
			int b = coef[3 * parity + 1];
			int c = coef[3 * parity + 2];
			H[i] = (((a * i + b) % 1000000007) * i + c) % 1000000007;
		}
		for (size_t j = 0; j < idx.size(); j++)
			H[idx[j]] = val[j];
		sparseTree<vector<ll>, min> smin;
		smin.buildSparseTable(H, N, 1e9 + 7);
		ll ret = 0;
		auto left = getBigggerLeft(H);
		auto right = getBigggerRight(H);
		pc(H);
		pc(left);
		pc(right);
		for (size_t i = 0; i < N; i++)
			if (i == 0 || H[i] > H[i - 1])
				if (i == N - 1 || H[i] > H[i + 1])
				{
					int bl = left[i];
					int br = right[i];
					db(i, bl, br);
					int bottom = 0;
					if (bl >= 0)
						bottom = max(bottom, smin.query(bl + 1, i - 1));
					if (br + 1 <= N)
						bottom = max(bottom, smin.query(i + 1, br - 1));
					if (bottom == 1000000007)
						bottom = 0;
					db(i, bottom);
					ret += H[i] - bottom;
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
bool KawigiEdit_RunTest(int testNum, int p0, vector<int> p1, vector<int> p2, vector<int> p3, bool hasAnswer, long long p4)
{
	cout << "Test " << testNum << ": [" << p0 << ","
		 << "{";
	for (int i = 0; int(p1.size()) > i; ++i)
	{
		if (i > 0)
		{
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}"
		 << ","
		 << "{";
	for (int i = 0; int(p2.size()) > i; ++i)
	{
		if (i > 0)
		{
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}"
		 << ","
		 << "{";
	for (int i = 0; int(p3.size()) > i; ++i)
	{
		if (i > 0)
		{
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}";
	cout << "]" << endl;
	Prominence *obj;
	long long answer;
	obj = new Prominence();
	clock_t startTime = clock();
	answer = obj->sumOfProminences(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer)
	{
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer)
	{
		res = answer == p4;
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
	vector<int> p1;
	vector<int> p2;
	vector<int> p3;
	long long p4;

	{
		// ----- test 0 -----
		p0 = 7;
		int t1[] = {0, 0, 47, 0, 0, 47};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2.clear() /*{}*/;
		p3.clear() /*{}*/;
		p4 = 0ll;
		all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		p0 = 8;
		int t1[] = {0, 0, 47, 0, 0, 42};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2.clear() /*{}*/;
		p3.clear() /*{}*/;
		p4 = 188ll;
		all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		p0 = 10;
		int t1[] = {0, 0, 0, 0, 0, 0};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		int t2[] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};
		p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
		int t3[] = {500, 300, 400, 200, 400, 700, 100, 300, 300, 100};
		p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
		p4 = 1500ll;
		all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		p0 = 16;
		int t1[] = {123456789, 234567890, 345678901, 456789012, 567890123, 678901234};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		int t2[] = {7};
		p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
		int t3[] = {890123456};
		p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
		p4 = 4543586810ll;
		all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
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