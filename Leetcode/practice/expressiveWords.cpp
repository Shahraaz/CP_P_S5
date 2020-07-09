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
    vector<pair<char, int>> convert(string S)
    {
        vector<pair<char, int>> ret;
        for (auto &x : S)
        {
            if (ret.size() == 0 || ret.back().f != x)
                ret.push_back({x, 1});
            else
                ret.back().s++;
        }
        return ret;
    }

public:
    int expressiveWords(string S, vector<string> words)
    {
        int ret = 0;
        auto base = convert(S);
        db(base);
        for (auto &x : words)
        {
            auto curr = convert(x);
            db(curr);
            if (curr.size() == base.size())
            {
                bool ok = true;
                for (size_t i = 0; i < curr.size(); i++)
                {
                    ok = ok && curr[i].f == base[i].f;
                    if (curr[i].s == base[i].s)
                        continue;
                    else
                        ok = ok && curr[i].s <= base[i].s && base[i].s >= 3;
                }
                db(ok);
                ret += ok;
            }
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
        db(S.expressiveWords("dddiiiinnssssssoooo", {"dinnssoo", "ddiinso", "dinsoo", "dinssoo", "dinso"}));
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif