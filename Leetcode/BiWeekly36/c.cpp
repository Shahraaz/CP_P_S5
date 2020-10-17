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
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        int r = rowSum.size();
        int c = colSum.size();
        set<pair<int, int>> rSet, cSet;
        vector<vector<int>> ret(r, vector<int>(c));
        for (size_t i = 0; i < r; i++)
            rSet.insert({rowSum[i], i});
        for (size_t i = 0; i < c; i++)
            cSet.insert({colSum[i], i});
        while (cSet.size() && rSet.size())
        {
            auto it1 = *cSet.begin();
            cSet.erase(it1);
            if (it1.f == 0)
                continue;
            auto it2 = *rSet.begin();
            rSet.erase(it2);
            if (it2.f == 0)
            {
                cSet.insert(it1);
                continue;
            }
            // cout << it1.f << ' ' << it1.s << '\n';
            // cout << it2.f << ' ' << it2.s << '\n';
            if (it1.f <= it2.f)
            {
                ret[it2.s][it1.s] += it1.f;
                it2.f -= it1.f;
                rSet.insert(it2);
            }
            else
            {
                ret[it2.s][it1.s] += it2.f;
                it1.f -= it2.f;
                cSet.insert(it1);
            }
        }
        return ret;
    }
};