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
using ld = long double;
const ld EPS_DIST = 1e-4 + 1e-8;
ld angle = acosl(1 - EPS_DIST * EPS_DIST / 2);
ld preCompx[1001], preCompy[1001];
vector<int> adj[1001];
ld x_res[1001], y_res[1001];

ld dfs(int node, int par)
{
    int ctr = 0;
    ld maxHt = y_res[node];
    for (auto &x : adj[node])
    {
        if (x != par)
        {
            if (ctr == 0)
            {
                x_res[x] = x_res[node] + 1;
                y_res[x] = y_res[node];
                maxHt = dfs(x, node);
            }
            else
            {
                y_res[x] = maxHt + preCompy[1];
                x_res[x] = x_res[node] + sqrtl(1 - (y_res[x] - y_res[node]) * (y_res[x] - y_res[node]));
                maxHt = dfs(x, node);
            }
            ctr++;
        }
    }
    return maxHt;
}

ld dist(int i, int j)
{
    return sqrtl((x_res[i] - x_res[j]) * (x_res[i] - x_res[j]) + (y_res[i] - y_res[j]) * (y_res[i] - y_res[j]));
}

void solveCase()
{
    db("incase");
    int n;
    cin >> n;
    for (size_t i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (size_t i = 0; i < 1001; i++)
    {
        preCompx[i] = cosl(i * angle);
        preCompy[i] = sinl(i * angle);
    }
    // cout << preCompx[100] << ' ' << preCompy[100] << '\n';
    // cout << preCompx[1000] << ' ' << preCompy[1000] << '\n';
    x_res[0] = 1500, y_res[0] = 1500;
    dfs(0, 0);
    for (size_t i = 0; i < n; i++)
        cout << fixed << setprecision(20) << x_res[i] << ' ' << y_res[i] << '\n';
    for (size_t i = 0; i < n; i++)
    {
        for (auto &x : adj[i])
        {
            // cout << i << ' ' << x << ' ' << dist(i, x) << '\n';
            if (abs(dist(i, x) - 1) < 1e-6)
                continue;
            // cout << i << ' ' << x << '\n';
            exit(1);
        }
        for (size_t j = i + 1; j < n; j++)
        {
            if (dist(i, j) < 1e-4)
            {
                // cout << i << '  ' << j << '\n';
                // exit(1);
            }
            /* code */
        }
    }
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
    {
        solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
