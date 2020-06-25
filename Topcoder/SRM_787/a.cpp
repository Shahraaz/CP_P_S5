// Optimise
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()

const int NAX = 2e5 + 5, MOD = 1000000007;

class AqaAsadiMinimizes
{
public:
	double getMin(vector<int> P, int B0, int X, int Y, int N)
	{
		vector<ll> A(N);
		for (size_t i = 0; i < N; i++)
		{
			if (i < P.size())
				A[i] = P[i];
			else if (i == P.size())
				A[i] = B0;
			else
				A[i] = (A[i - 1] * X + Y) % 1000000007;
		}
		// for (int i = 0; i < N; i++)
		// {
		// 	for (int j = 0; j < N; j++)
		// 	{
		// 		if (i == j)
		// 			continue;
		// 		cout << abs(A[i] - A[j]) * 1.0 / abs(i - j) << ' ';
		// 	}
		// 	cout << '\n';
		// }
		map<int, int> ss;
		for (size_t i = 0; i < N; i++)
		{
			if (ss.count(A[i]))
				return 0;
			ss[A[i]] = (i);
		}
		long double ret = LDBL_MAX;
		for (int i = 0; i < N; i++)
		{
			set<int> temp;
			temp.insert(A[i]);
			auto it = ss.lower_bound((A[i]));
			if (it != ss.end())
			{
				auto it2 = it;
				it2++;
				if (it2 != ss.end())
				{
					int idx = it2->s;
					ret = min(ret, abs(A[i] - A[idx]) * 1.0l / abs(i - idx));
				}
			}
			if (it != ss.begin())
			{
				auto it2 = it;
				it2--;
				{
					int idx = it2->s;
					ret = min(ret, abs(A[i] - A[idx]) * 1.0l / abs(i - idx));
				}
			}
			// double idx1 = *(it->s).begin();
		}
		return 0;
	}
};

#ifndef LOCAL
//<%:testing-code%>
#endif

#ifdef LOCAL
int32_t main()
{
#ifndef LOCAL
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#endif
	int t = 1;
	// cin >> t;
	// Solution mySolver;
	for (int i = 1; i <= t; ++i)
	{
		// mySolver.solveCase();
#ifdef LOCAL
		cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
		TimeStart = chrono::steady_clock::now();
#endif
	}
	return 0;
}
#endif

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!