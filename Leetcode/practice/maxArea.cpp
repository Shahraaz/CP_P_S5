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
    int maxArea(vector<int> height)
    {
        set<int> ss;
        int n = height.size();
        vector<int> v(n);
        for (size_t i = 0; i < n; i++)
        {
            v[i] = i;
            ss.insert(i);
        }
        int ret = 0;
        sort(all(v), [&](int a, int b) { return height[a] < height[b]; });
        db(v, height);
        for (size_t i = 0; (i + 1) < n; i++)
        {
            ss.erase(v[i]);
            int temp = *ss.begin();
            db(i, height[v[i]], v[i], temp);
            ret = max(ret, height[v[i]] * abs(temp - v[i]));
            temp = *ss.rbegin();
            db(i, height[v[i]], v[i], temp);
            ret = max(ret, height[v[i]] * abs(temp - v[i]));
            // cout << "-------------------\n";
            db("--------------")
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
        db(S.maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}));
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif