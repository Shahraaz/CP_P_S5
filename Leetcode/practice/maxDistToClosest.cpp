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
    int maxDistToClosest(vector<int> &seats)
    {
        int n = seats.size();
        set<int> indices;
        for (size_t i = 0; i < n; i++)
            if (seats[i])
                indices.insert(i);
        int ret = 0;
        for (size_t i = 0; i < n; i++)
            if (seats[i] == 0)
            {
                auto it = indices.lower_bound(i);
                int curr = INT_MAX;
                if (it != indices.end())
                    curr = *it - i;
                if (it != indices.begin())
                {
                    it--;
                    curr = i - *it;
                }
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