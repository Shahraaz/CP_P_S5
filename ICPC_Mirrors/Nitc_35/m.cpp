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
const int NAX = 1e5 + 5, MOD = 1000000007;

void solveCase()
{
    int n;
    cin >> n;
    vector<int> res(n);
    vector<vector<int>> adj(NAX);
    vector<deque<int>> adj2(NAX);
    for (size_t i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (size_t j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            adj[i].pb(x);
            adj2[x].pb(i);
        }
    }
    vector<int> vis(n);
    for (size_t i = 0; i < n; i++)
    {
        int now = res[i];
        for (auto &x : adj[i])
        {
            adj2[x].pop_front();
            if (adj2[x].size())
                res[adj2[x].front()] = max(res[adj2[x].front()], now + 1);
        }
    }
    cout << res.back() + 1 << '\n';
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