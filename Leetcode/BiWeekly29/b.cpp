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
    int longestSubarray(vector<int> nums)
    {
        int n = nums.size();
        vector<int>
            prefNum(nums.size());
        vector<int> suffNum(nums.size());
        for (size_t i = 0; i < n; i++)
        {
            if (nums[i] != 1)
                continue;
            if (i > 0)
                prefNum[i] = prefNum[i - 1];
            prefNum[i]++;
        }
        reverse(all(nums));
        for (size_t i = 0; i < n; i++)
        {
            if (nums[i] != 1)
                continue;
            if (i > 0)
                suffNum[i] = suffNum[i - 1];
            suffNum[i]++;
        }
        reverse(all(suffNum));
        int ret = 0;
        for (size_t i = 0; i < n; i++)
        {
            int curr = 0;
            if (i > 0)
                curr = prefNum[i - 1];
            if (i != n - 1)
                curr += suffNum[i + 1];
            ret = max(ret, curr);
        }
        return ret;
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
    cout << S.longestSubarray({1, 1, 0, 1}) << '\n';
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