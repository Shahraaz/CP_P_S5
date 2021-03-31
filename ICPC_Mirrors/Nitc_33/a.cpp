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
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    db(n, m1, m2);
    // vector<vector<int>> adj(n + 1);
    vector<vector<int>> type1(m1), type2(m2);
    for (size_t i = 0; i < m1; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        type1[i] = {x, y, z};
    }
    for (size_t i = 0; i < m2; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        type2[i] = {x, y, z};
    }
    int l, r, ans;
    l = 0, r = n, ans = n;
    auto check = [&](int total) -> bool {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (size_t i = 1; i <= n; i++)
            adj[i].pb({i - 1, 0});
        for (size_t i = 1; i <= n; i++)
            adj[i - 1].pb({i, 1});

        for (size_t i = 0; i < m1; i++)
            adj[type1[i][1]].pb({type1[i][0] - 1, -type1[i][2]});
        for (size_t i = 0; i < m2; i++)
            adj[type2[i][0] - 1].pb({type2[i][1], -type2[i][2] + total});

        adj[0].pb({n, total});
        adj[n].pb({0, -total});
        db(total);
        for (size_t i = 0; i <= n; i++)
        {
            db(i, adj[i]);
        }
        auto find_neg = [&]() -> bool {
            vector<int> inQ(n + 1);
            vector<int> dist(n + 1, MOD);
            queue<int> Q;
            Q.push(n);
            dist[n] = 0;
            inQ[n] = 1;
            while (Q.size())
            {
                auto top = Q.front();
                Q.pop();
                db(top, dist[top]);
                inQ[top] = 0;
                for (auto &x : adj[top])
                {
                    if (dist[x.first] > dist[top] + x.second)
                    {
                        dist[x.first] = dist[top] + x.second;
                        if (!inQ[x.first])
                        {
                            inQ[x.first] = 1;
                            Q.push(x.first);
                        }
                    }
                    if (dist[n] < 0)
                        return true;
                }
            }
            return false;
        };
        return !find_neg();
    };
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    cout << ans << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}