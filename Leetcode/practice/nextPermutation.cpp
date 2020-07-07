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
    void nextPermutation(vector<int> &nums)
    {
        if (is_sorted(nums.rbegin(), nums.rend()))
        {
            reverse(all(nums));
        }
        else
        {
            int pos_till_sorred = nums.size() - 1;
            pos_till_sorred--;
            while (nums[pos_till_sorred] > nums[pos_till_sorred + 1])
                pos_till_sorred--;
            int idx = -1;
            for (size_t i = pos_till_sorred; i < nums.size(); i++)
                if(idx == -1 || nums[idx] > nums[i])
                    idx = i;
            swap(nums[idx], nums[pos_till_sorred]);
            sort(nums.begin() + pos_till_sorred + 1, nums.end());
        }
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