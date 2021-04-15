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

using ld = long double;
vector<vector<pair<int, int>>> adj(NAX);
int n;
vector<int> cnt_total(3);
vector<vector<int>> cnt_child(NAX, vector<int>(3)), is_in_child(NAX, vector<int>(3));

void dfs(int node, int par)
{
    cnt_child[node] = is_in_child[node];
    for (auto &x : adj[node])
    {
        if (x.first == par)
            continue;
        dfs(x.first, node);
        for (int i = 0; i < 3; ++i)
            cnt_child[node][i] += cnt_child[x.first][i];
    }
    db(node, par, cnt_child[node]);
}

using ld = long double;

ld res = 0;

void dfs_2(int node, int par)
{
    auto back_node = cnt_child[node];
    for (auto &x : adj[node])
    {
        if (x.first == par)
            continue;

        for (size_t i = 0; i < 3; i++)
            cnt_child[node][i] -= cnt_child[x.first][i];
        for (int mask = 6; mask > 0; mask--)
        {
            ll cnt_a = 1;
            ll cnt_b = 1;
            for (int j = 0; j < 3; j++)
            {
                if ((mask >> j) & 1)
                    cnt_a *= cnt_child[node][j];
                else
                    cnt_b *= cnt_child[x.first][j];
            }
            db(x.second, bitset<3>(mask), cnt_a, cnt_b);
            res += x.second * (cnt_a * cnt_b);
        }
        auto back_child = cnt_child[x.first];
        cnt_child[x.first] = back_node;
        dfs_2(x.first, node);
        cnt_child[node] = back_node;
        cnt_child[x.first] = back_child;
    }
}

void solveCase()
{
    cin >> n;
    for (size_t i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    for (size_t i = 0; i < 3; i++)
    {
        cin >> cnt_total[i];
        for (size_t j = 0; j < cnt_total[i]; j++)
        {
            int x;
            cin >> x;
            --x;
            is_in_child[x][i] = 1;
        }
    }
    dfs(0, 0);
    dfs_2(0, 0);
    db(res, cnt_total);
    res /= (cnt_total[0] * 1LL * cnt_total[1] * cnt_total[2]);
    cout << fixed << setprecision(10) << res << '\n';
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