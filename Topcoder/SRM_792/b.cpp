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

class IncreasingJumpsDiv1
{
public:
    vector<int> jump(vector<int> frogs)
    {
        int n = frogs.size();
        int jumpIdx = 1;
        vector<pair<int, int>> pp;
        for (int i = 0; i < n; i++)
            pp.pb({frogs[i], i + 1});
        sort(all(pp));
        vector<int> ret;
        for (size_t i = 0; i < n; i++)
        {
            int now = pp[i].f;
            ll idx = pp[i].s;
            while (now != 0)
            {
                db(idx, now, jumpIdx);
                if (now < 0)
                {
                    now += jumpIdx;
                    ret.pb(idx);
                    jumpIdx++;
                }
                else if (now >= jumpIdx)
                {
                    now -= jumpIdx;
                    ret.pb(-idx);
                    jumpIdx++;
                    assert(jumpIdx <= 2500);
                }
                else
                {
                    now += jumpIdx;
                    ret.pb(idx);
                    jumpIdx++;
                    assert(jumpIdx <= 2500);
                    now -= jumpIdx;
                    ret.pb(-idx);
                    jumpIdx++;
                    assert(jumpIdx <= 2500);
                }
            }
        }
        for (size_t i = 0; i < n; i++)
        {
            ret.pb(pp[i].s);
            jumpIdx++;
            assert(jumpIdx <= 2500);
        }
        return ret;
    }
};

#ifndef LOCAL
//<%:testing-code%>
#endif
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!