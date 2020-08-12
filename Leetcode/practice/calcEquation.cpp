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
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        map<string, int> literals;
        for (auto &x : equations)
            for (auto &y : x)
                if (literals[y] == 0)
                    literals[y] = literals.size();
        int n = literals.size();
        using ld = long double;
        vector<pair<int, ld>> adj[n];
        for (size_t i = 0; i < equations.size(); i++)
        {
            adj[literals[equations[i][0]] - 1].pb({literals[equations[i][1]] - 1, values[i]});
            adj[literals[equations[i][1]] - 1].pb({literals[equations[i][0]] - 1, 1 / values[i]});
        }
        vector<double> ret;
        for (auto &x : queries)
        {
            int a = literals[x[0]];
            int b = literals[x[1]];
            if (a == 0 || b == 0)
                ret.pb(-1);
            else
            {
                if (a == b)
                    ret.pb(1);
                else
                {
                    queue<pair<int, ld>> Q;
                    --a, --b;
                    Q.push({a, 1});
                    set<int> vis;
                    vis.insert(a);
                    bool found = false;
                    while (Q.size())
                    {
                        auto top = Q.front();
                        if (top.s == b)
                        {
                            found = true;
                            ret.pb(top.s);
                            break;
                        }
                        for (auto &x : adj[top.f])
                            if (vis.count(x.f) == 0)
                            {
                                vis.insert(x.f);
                                Q.push({x.f, top.s * x.s});
                            }
                    }
                    if (!found)
                        ret.pb(-1);
                }
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
        ;
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif