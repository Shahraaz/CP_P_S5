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
    int n, q;
    cin >> n >> q;
    vector<string> vecc(n);
    vector<vector<pair<int, int>>> adj(n + 26);
    vector<vector<int>> helper(n, vector<int>(26));
    vector<vector<int>> dist(26);
    for (size_t i = 0; i < n; i++)
    {
        cin >> vecc[i];
        for (auto &c : vecc[i])
        {
            helper[i][c - 'A'] = 1;
            int cidx = c - 'A' + n;
            if (adj[i].empty() || adj[i].back().first != cidx)
                adj[i].pb({cidx, 0});
            if (adj[cidx].empty() || adj[cidx].back().first != i)
                adj[cidx].pb({i, 1});
        }
    }
    for (size_t i = 0; i < 26; i++)
    {
        int cidx = n + i;
        dist[i].resize(n + 26, MOD);
        dist[i][cidx] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        vector<int> vis(n + 26);
        Q.push({0, cidx});
        // vis[cidx] = 1;
        while (Q.size())
        {
            auto top = Q.top();
            Q.pop();
            if (vis[top.second])
                continue;
            db(i, top);
            vis[top.second] = 1;
            for (auto &child : adj[top.second])
                if (!vis[child.first] && dist[i][child.first] > (top.first + child.second))
                {
                    dist[i][child.first] = top.first + child.second;
                    Q.push({dist[i][child.first], child.first});
                }
        }
#ifdef LOCAL
        db(i);
        for (size_t j = 0; j < n + 26; j++)
        {
            if (dist[i][j] < 100)
                cout << "(" << j << ' ' << dist[i][j] << "),";
        }
        cout << '\n';
#endif
    }
    for (size_t i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        int ret = MOD;
        for (size_t j = 0; j < 26; j++)
            for (size_t z = 0; z < 26; z++)
                if (helper[x][j] && helper[y][z])
                {
                    ret = min(ret, 2 + dist[j][z + n]);
                }
        if (ret >= 100)
            ret = -1;
        cout << ret << ' ';
    }
    cout << '\n';
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
    {
        cout << "Case #" << i << ": ";
        solveCase();
#ifdef TIMER
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}