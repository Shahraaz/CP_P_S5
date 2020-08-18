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

struct Solution
{
    Solution() {}
    void solveCase();
};

int n, k;
vector<ll> adj[NAX];
vector<ll> cycle[NAX], cycle_cost[NAX];
ll cost[NAX], cycle_sum[NAX];

void Solution::solveCase()
{
    cin >> n >> k;
    for (size_t i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        adj[i].pb(p);
    }
    for (size_t i = 1; i <= n; i++)
        cin >> cost[i];
    vector<int> vis(n + 1, 0);
    ll res = LLONG_MIN;
    for (size_t i = 1; i <= n; i++)
    {
        db(i);
        if (vis[i])
            continue;
        queue<int> Q;
        Q.push(i);
        while (Q.size())
        {
            auto top = Q.front();
            Q.pop();
            vis[top] = 1;
            cycle[i].pb(top);
            top = adj[top][0];
            if (!vis[top])
                Q.push(top);
        }
        db(i, cycle[i]);
        for (auto &x : cycle[i])
        {
            cycle_sum[i] += cost[x];
            cycle_cost[i].pb(cost[x]);
        }
        for (auto &x : cycle[i])
            cycle_cost[i].pb(cost[x]);
        for (auto &x : cycle[i])
            cycle_cost[i].pb(cost[x]);
        for (auto &x : cycle[i])
            cycle_cost[i].pb(cost[x]);
        for (auto &x : cycle[i])
            cycle_cost[i].pb(cost[x]);
        for (auto &x : cycle[i])
            cycle_cost[i].pb(cost[x]);
        for (size_t j = 0; j < cycle_cost[i].size(); j++)
            if (j > 0)
                cycle_cost[i][j] += cycle_cost[i][j - 1];
        ll fixed = 0;
        ll k2 = k;
        if (cycle_sum[i] > 0)
        {
            db(k, cycle[i].size());
            if (k > cycle[i].size())
            {
                ll k1 = (k - cycle[i].size()) / cycle[i].size();
                db(k1);
                fixed = k1 * cycle_sum[i];
                k2 = (k - cycle[i].size()) % cycle[i].size() + cycle[i].size();
                db(k2);
            }
            else
            {
                k2 = min(k, (int)cycle[i].size());
            }
        }
        else
        {
            k2 = min(k, (int)cycle[i].size());
        }
        multiset<ll> ms;
        db(k2, fixed, cycle_cost[i].size());
        for (size_t j = 0; j < k2; j++)
            ms.insert(cycle_cost[i][j]);
        for (size_t j = 0; j < cycle[i].size(); j++)
        {
            ll prev = 0;
            if (j > 0)
                prev = cycle_cost[i][j - 1];
            auto it = *ms.rbegin();
            res = max(res, fixed + it - prev);
            ms.erase(ms.find(cycle_cost[i][j]));
            ms.insert(cycle_cost[i][j + k2]);
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
