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
const int NAX = 22, MOD = 1000000007;

int r, c;
int getIdx(int x, int y)
{
    return x * c + y;
}
pair<int, int> getX_Y(int idx)
{
    return make_pair(idx / c, idx % c);
}
bool check_compat(int idx1, int idx2)
{
    auto i = getX_Y(idx1);
    auto j = getX_Y(idx2);
    return !(i.first == j.first || i.second == j.second || (i.first - i.second) == (j.first - j.second) || (i.first + i.second) == (j.first + j.second));
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(permutation.begin(), permutation.end(), rng);

vector<int> res, vis;
vector<int> order;
vector<int> adj[500];

bool compat(int node)
{
    return res.empty() || check_compat(res.back(), node);
}

void dfs(int node)
{
    res.pb(node);
    vis[node] = 1;
    for (auto &x : adj[node])
        if (!vis[x])
            return dfs(x);
}

bool doable()
{
    shuffle(order.begin(), order.end(), rng);
    for (size_t i = 0; i < r * c; i++)
        shuffle(all(adj[i]), rng);
    fill(all(vis), 0);
    res.clear();
    db(r, c, order);
    for (auto &x : order)
        if (!vis[x])
        {
            if (compat(x))
                dfs(x);
            else
                return false;
        }
    return count(all(vis), 1) == (r * c);
}

void solveCase()
{
    r = 20, c = 20;
    cin >> r >> c;
    order.clear();
    vis.resize(r * c);
    for (size_t i = 0; i < r * c; i++)
    {
        adj[i].clear();
        order.pb(i);
        for (size_t j = 0; j < r * c; j++)
            if (check_compat(i, j))
                adj[i].pb(j);
    }
    const int TRIES = 100;
    for (size_t i = 0; i < TRIES; i++)
    {
        if (doable())
        {
            cout << "POSSIBLE\n";
            for (auto &x : res)
            {
                auto x_y = getX_Y(x);
                cout << x_y.first + 1 << ' ' << x_y.second + 1 << '\n';
            }
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 100;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solveCase();
    }
    return 0;
}