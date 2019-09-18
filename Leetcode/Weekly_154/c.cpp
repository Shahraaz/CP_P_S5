#ifdef WIN32
#include <bits/stdc++.h>
using namespace std;
#endif
#define Debug
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

const int nax = 2e5 + 10;

class Solution
{
	int maxSubArraySum(vector<int> a)
	{
		int size = a.size();
		int max_so_far = INT_MIN, max_ending_here = 0;

		for (int i = 0; i < size; i++)
		{
			max_ending_here = max_ending_here + a[i];
			if (max_so_far < max_ending_here)
				max_so_far = max_ending_here;

			if (max_ending_here < 0)
				max_ending_here = 0;
		}
		return max_so_far;
	}

public:
	int kConcatenationMaxSum(vector<int> &arr, int k)
	{
		int sum = 0;
		for (auto i : arr)
			sum += i;
		int pref = 0, sum = 0;
		for (auto i : arr)
		{
			sum += i;
			pref = max(pref, sum);
		}
		int suff = 0;
		sum = 0;
		reverse(arr.begin(), arr.end());
		for (auto i : arr)
		{
			sum += i;
			suff = max(suff, sum);
		}
		int ret = maxSubArraySum(arr);
		if (sum >= 0)
		{
			if (k >= 2)
				ret = max(ret, sum * (k - 2) pref + suff);
		}
		else
		{
			if (k >= 2)
				ret = max(ret, pref + suff);
		}
	}
};
