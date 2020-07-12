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
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> prefMax(n);
        vector<int> suffMax(n);
        int ret = 0;
        prefMax[0] = height[0];
        for (size_t i = 1; i < n; i++)
            prefMax[i] = max(prefMax[i - 1], height[i]);
        suffMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffMax[i] = max(suffMax[i + 1], height[i]);
        for (int i = 1; i < n - 1; i++)
            if (prefMax[i - 1] >= height[i] && height[i] <= suffMax[i + 1])
                ret += min(prefMax[i - 1], suffMax[i + 1]) - height[i];
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