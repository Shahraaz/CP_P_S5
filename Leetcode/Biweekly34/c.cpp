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
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int n = arr.size();
        vector<bool> isSortedPref(n);
        vector<bool> isSortedSuff(n);
        for (size_t i = 0; i < n; i++)
        {
            if (i == 0)
                isSortedPref[i] = 1;
            else if (arr[i - 1] <= arr[i])
                isSortedPref[i] = isSortedPref[i - 1];
            else
                isSortedPref[i] = 0;
        }
        reverse(all(arr));
        for (size_t i = 0; i < n; i++)
        {
            if (i == 0)
                isSortedSuff[i] = 1;
            else if (arr[i - 1] >= arr[i])
                isSortedSuff[i] = isSortedSuff[i - 1];
            else
                isSortedSuff[i] = 0;
        }
        reverse(all(isSortedSuff));
        reverse(all(arr));
        isSortedSuff.pb(1);
        arr.pb(MOD);
        int rptr = n;
        int ans = n;
        for (int i = n - 1; i >= 0; i--)
        {
            if (isSortedPref[i])
            {
                ans = min(ans, n - i - 1);
                while (rptr < n && arr[i] > arr[rptr])
                    ++rptr;
                while (rptr != i && isSortedSuff[rptr] && arr[i] <= arr[rptr])
                    --rptr;
                ans = min(ans, rptr - i);
            }
            if (isSortedSuff[i])
            {
                ans = min(ans, i);
            }
        }
        return ans;
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