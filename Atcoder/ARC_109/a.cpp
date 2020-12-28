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

#define ina(i) (2 * (i))
#define inb(i) (2 * (i) + 1)

void solveCase()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    vector<pair<int, int>> adj[201];
    for (size_t i = 1; i <= 99; i++)
    {
        adj[ina(i + 1)].pb({inb(i), x});
        adj[inb(i)].pb({ina(i + 1), x});

        adj[ina(i + 1)].pb({ina(i), y});
        adj[ina(i)].pb({ina(i + 1), y});

        adj[inb(i + 1)].pb({inb(i), y});
        adj[inb(i)].pb({inb(i + 1), y});
    }

    Q.push({0, a * 2});
    vector<int> dist(2 * 100 + 2, MOD);
    vector<int> vis(2 * 100 + 2, 0);
    dist[2 * a] = 0;
    while (Q.size())
    {
        auto top = Q.top();
        db(top);
        Q.pop();
        if (top.second == (2 * b + 1))
            break;
        if (vis[top.second] || top.first != dist[top.second])
            continue;
        vis[top.second] = 1;
        int idx = top.second / 2;
        int bit = top.second & 1;
        vector<pair<int, pair<int, int>>> dxx;
        dxx.push_back({bit, {1, y}});
        dxx.push_back({bit, {-1, y}});
        dxx.push_back({1 - bit, {bit ? 1 : -1, x}});
        for (auto dx : dxx)
        {
            int next = dx.first + 2 * (idx + dx.second.first);
            int cont = top.first + dx.second.second;
            db(top, next, cont, dx);
            if (1 <= next && next <= 200)
                if (!vis[next] && dist[next] > cont)
                {
                    dist[next] = cont;
                    Q.push({cont, next});
                }
        }
    }
    cout << dist[b * 2 + 1] << '\n';
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