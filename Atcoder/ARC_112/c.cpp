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
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (size_t i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        adj[p - 1].pb(i);
    }
    function<pair<int, int>(int)> dfs = [&](int node) -> pair<int, int> {
        pair<int, int> ret{1, 1};
        vector<int> seq;
        int sum = 0;
        for (auto &x : adj[node])
        {
            auto x_res = dfs(x);
            ret.second += x_res.second;
            if (x_res.second % 2)
                seq.pb(-x_res.first);
            else if (x_res.first < 0)
                ret.first -= -x_res.first;
            else
                sum += -x_res.first;
        }
        sort(all(seq), greater<int>());
        seq.pb(sum);
        db(node, seq, sum);
        for (size_t i = 0; i < seq.size(); i++)
            if (i % 2 == 0)
                ret.first -= seq[i];
            else
                ret.first += seq[i];
        db(node, ret);
        return ret;
    };
    cout << (dfs(0).first + n) / 2 << '\n';
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