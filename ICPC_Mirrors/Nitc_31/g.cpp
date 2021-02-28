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
const int NAX = 500 + 5, MOD = 1000000007;

int n, m;
int adj[NAX][NAX];
int adj2[NAX][NAX], degree[NAX];

bool check(int k)
{
    memcpy(adj2, adj, sizeof adj2);
    set<pair<int, int>> nodes;
    for (size_t i = 0; i < n; i++)
    {
        degree[i] = count(adj2[i], adj2[i] + n, 1);
        nodes.insert({degree[i], i});
    }
    db(k);
    while (true)
    {
        bool ok = false;
        for (int node = 0; node < n; node++)
            for (size_t i = 0; i < n; i++)
            {
                if (i != node)
                    if (!adj2[node][i] && (degree[node] + degree[i]) >= k)
                    {
                        ok = 1;
                        adj2[node][i] = 1;
                        adj2[i][node] = 1;
                        // nodes.erase({degree[i], i});
                        // nodes.erase({degree[node], node});
                        degree[i]++;
                        degree[node]++;
                        // nodes.insert({degree[i], i});
                        // nodes.insert({degree[node], node});
                    }
            }
        if (!ok)
            break;
        // return false;
    }
    return count(degree, degree + n, n - 1) == n;
}

void solveCase()
{
    cin >> n >> m;
    for (size_t i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    int low = 0, high = 2 * n + 1, ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(mid))
        {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
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
    // cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}