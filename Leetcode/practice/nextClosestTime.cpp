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
    string nextClosestTime(string time)
    {
        vector<char> digs;
        pair<int, int> curr;
        curr.f = (time[0] - '0') * 10 + time[1] - '0';
        curr.s = (time[3] - '0') * 10 + time[4] - '0';
        for (auto &x : time)
        {
            if ('0' <= x && x <= '9')
                digs.pb(x);
        }
        int n = digs.size();
        vector<pair<int, int>> vec;
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < n; j++)
                for (size_t k = 0; k < n; k++)
                    for (size_t l = 0; l < n; l++)
                    {
                        if (digs[i] <= '1' || (digs[i] == '2' && digs[j] <= '4'))
                            if (digs[k] <= '5')
                                vec.pb({(digs[i] - '0') * 10 + digs[j] - '0',
                                        (digs[k] - '0') * 10 + digs[l] - '0'});
                    }
        sort(all(vec), [&](pair<int, int> a, pair<int, int> b) {
            if (a <= curr)
                a.f += 24;
            if (b <= curr)
                b.f += 24;
            return a.f * 60 + a.s < b.f * 60 + b.s;
        });
        db("----");
        db(curr);
        db(vec);
        // ;        for (auto &x : vec)
        //         {
        //             cout << x.f << ' ' << x.s << '\n';
        //         }
        string ret;
        ret += string(2 - to_string(vec[0].f).length(), '0') + to_string(vec[0].f);
        ret += ":";
        ret += string(2 - to_string(vec[0].s).length(), '0') + to_string(vec[0].s);
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
        cout << S.nextClosestTime("01:32") << '\n';
        ;
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif