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
    vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime)
    {
        set<string> ss;
        vector<string> ret;
        map<string, vector<int>> mp;
        for (size_t i = 0; i < keyName.size(); i++)
        {
            int time = keyTime[i][0] - '0';
            time = time * 10 + keyTime[i][1] - '0';
            time = time * 60 + keyTime[i][3] - '0';
            time = time + keyTime[i][4] - '0';
            mp[keyName[i]].pb(time);
        }
        for (auto &x : mp)
        {
            sort(x.s.begin(), x.s.end());
            for (size_t i = 0; i + 2 < x.s.size(); i++)
                if (x.s[i + 1] - x.s[i] >= 0 && x.s[i + 1] - x.s[i] <= 60)
                    if (x.s[i + 2] - x.s[i] >= 0 && x.s[i + 2] - x.s[i] <= 60)
                    {
                        ss.insert(x.first);
                        break;
                    }
        }

        for (auto &x : ss)
        {
            ret.pb(x);
        }
        return ret;
    }
};