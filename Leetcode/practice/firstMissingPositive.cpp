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

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        int fptr = 0, rptr = n;
        int xorSum = 0;
        for (int i = 0; i <= rptr; i++)
            xorSum ^= i;
        for (auto &x : nums)
            if (x < 0 || x > rptr)
            {
                xorSum ^= rptr;
                --rptr;
            }
            else
            {
                xorSum ^= x;
            }

        return xorSum;
    }
};

#ifdef LOCAL
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    Solution S;
    for (int i = 1; i <= t; ++i)
    {
        ;
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif