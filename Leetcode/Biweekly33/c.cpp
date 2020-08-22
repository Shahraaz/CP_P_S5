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
    int minOperations(vector<int> &nums)
    {
        int ret = 0;
        while (true)
        {
            vector<int> vec(2);
            int a = 0;
            for (size_t i = 0; i < nums.size(); i++)
            {
                vec[nums[i] & 1]++;
                a += nums[i] > 0;
            }
            if (a == 0)
                break;
            if (vec[1])
            {
                for (size_t i = 0; i < nums.size(); i++)
                    if (nums[i] & 1)
                    {
                        nums[i]--;
                        ret++;
                    }
            }
            else
            {
                for (size_t i = 0; i < nums.size(); i++)
                    nums[i] /= 2;
                ret++;
            }
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