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
const int NAX = 4e5 + 5, MOD = 1000000007;

vector<int> adj[NAX];
pair<int, int> edges[NAX];
int used[NAX];

void solveCase()
{
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[i] = {x, y};
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int res = 0;
    for (size_t i = 0; i < NAX; i++)
    {
        if (used[i] || adj[i].empty())
            continue;
        queue<int> Q;
        Q.push(i);
        used[i] = 1;
        int nodecnt = 0, edgecnt = 0;
        while (Q.size())
        {
            auto top = Q.front();
            nodecnt++;
            edgecnt += adj[top].size();
            Q.pop();
            for (auto &x : adj[top])
                if (!used[x])
                {
                    used[x] = 1;
                    Q.push(x);
                }
        }
        edgecnt /= 2;
        res += min(nodecnt, edgecnt);
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