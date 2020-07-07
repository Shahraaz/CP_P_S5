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
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper)
    {
        vector<pair<int, int>> temp;
        int prev = -1;
        for (auto &x : nums)
        {
            if (prev == -1)
            {
                if (lower == x)
                {
                }
                else
                    temp.pb({lower, x - 1});
            }
            else
            {
                if (prev + 1 == x)
                    ;
                else
                {
                    temp.pb({prev + 1, x - 1});
                }
            }
            prev = x;
        }
        if (nums.back() != upper)
            temp.pb({nums.back(), upper});
        vector<string> ret;
        for (auto &x : temp)
        {
            cout << x.f << ' ' << x.s << '\n';
            if(x.f == x.s)
                ret.pb(to_string(x.f));
            else 
                ret.pb(to_string(x.f) + "->" + to_string(x.s));
        }
        return ret;
    }
};

// int32_t main()
// {
// #ifndef LOCAL
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
// #endif
//     int t = 1;
//     // cin >> t;
//     Solution mySolver;
//     for (int i = 1; i <= t; ++i)
//     {
//         mySolver.solveCase();
// #ifdef LOCAL
//         cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
//         TimeStart = chrono::steady_clock::now();
// #endif
//     }
//     return 0;
// }
