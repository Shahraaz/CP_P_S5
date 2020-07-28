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
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        int n = A.size();
        vector<int> f, s;
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < n; j++)
                f.pb(A[i] + B[j]);
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < n; j++)
                s.pb(C[i] + D[j]);
        sort(all(f));
        int ret = 0;
        for (auto &x : s)
        {
            auto lo = lower_bound(all(f), -x);
            auto up = upper_bound(all(f), -x);
            // cout << x << ' ' << (up - lo) << '\n';
            ret += up - lo;
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