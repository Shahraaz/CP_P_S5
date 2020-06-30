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
    int check(vector<int> temp, int x)
    {
        if (temp.size() > 2)
        {
            int cnt = 0;
            for (int i = temp.size() - 1; i >= 0; i--)
            {
                if(temp[i] == x)
                    cnt++;
                else break;
                if(cnt > 2)
                    return false;
            }
            return true;
        }
        return false;
    }

public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ret;
        sort(all(nums));
        int n = nums.size();
        vector<int> temp;
        for (auto &x : nums)
        {
            if (check(temp, x))
                continue;
            temp.pb(x);
        }
        nums = temp;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i + 1; j < n; j++)
            {
                int curr = -nums[i] - nums[j];
                auto it = lower_bound(nums.begin() + j + 1, nums.end(), curr);
                if (it != nums.end() && *it == curr)
                    ret.pb({nums[i], nums[j], curr});
            }
        }
        sort(all(ret));
        ret.resize(unique(all(ret)) - ret.begin());
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