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
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        auto get = [](char c) -> int {
            if (c == 'R')
                return 0;
            if (c == 'G')
                return 1;
            // if(c == 'B')
            return 2;
        };
        vector<vector<int>> poses(3);
        for (size_t i = 0; i < n; i++)
            poses[get(str[i])].pb(i);
        ll res = 0;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i + 1; j < n; j++)
            {
                if (get(str[i]) != get(str[j]))
                {
                    int nextClr = 3 - get(str[i]) - get(str[j]);
                    int cnt = upper_bound(all(poses[nextClr]), j) - poses[nextClr].begin();
                    int scare = j + (j - i);
                    auto it = lower_bound(all(poses[nextClr]), scare);
                    bool ss = false;
                    if (it != poses[nextClr].end())
                        if (*it == scare)
                            ss = true;
                    res += poses[nextClr].size() - cnt - ss;
                }
            }
        }

        cout << res << '\n';
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
