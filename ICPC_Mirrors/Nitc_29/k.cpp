#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

#define all(v) v.begin(), v.end()
#define pb push_back
using ll = long long;
const int NAX = 2e5 + 5, MOD = 1000000007;

void solveCase()
{
    string str;
    cin >> str;
    vector<vector<int>> poses(26);
    int n = str.size();
    for (size_t i = 0; i < n; i++)
        poses[str[i] - 'a'].pb(i);
    ll res = 0;
    for (size_t i = 0; i < n; i++)
    {
        auto curr = str[i] - 'a';
        auto nextIdxit = upper_bound(all(poses[curr]), i);
        int nextIdx = 0;
        if (nextIdxit == poses[curr].end())
            nextIdx = n;
        else
            nextIdx = *nextIdxit;
        db(i, curr, nextIdx);
        for (size_t j = 0; j < 26; j++)
        {
            if (j == curr)
                continue;
            auto nextIdxitj = upper_bound(all(poses[j]), i);
            int nextIdxj = 0;
            if (nextIdxitj != poses[j].end())
            {
                nextIdxj = *nextIdxitj;
                if (nextIdx > nextIdxj)
                    res += 1;
            }
        }
    }
    cout << res << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}