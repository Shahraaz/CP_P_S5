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

map<ll, int> ok[36][36][2];
vector<int> g[36];
int id[20][20];

void dfs(int v, ll &mask, ll ban)
{
    db(v, mask, ban);
    if (mask & (1LL << v))
        return;
    mask |= 1LL << v;
    for (auto &x : g[v])
    {
        if (ban & (1LL << x))
            continue;
        dfs(x, mask, ban);
    }
}

bool can_move(ll ban, int a)
{
    for (auto &x : g[a])
    {
        if (ban & (1LL << x))
            continue;
        return true;
    }
    return false;
}

int calc(int s, ll ban, int a, int b, int who)
{
    // db(s, ban, a, b, who);
    ll msk = 0ll;
    dfs(a, msk, ban);
    dfs(b, msk, ban);
    for (size_t i = 0; i < s * s; i++)
    {
        if (msk & (1LL << i))
            continue;
        ban |= 1LL << i;
    }
    // db(s, ban, a, b, who);
    if (ok[a][b][who].count(ban))
        return ok[a][b][who][ban];
    auto &ret = ok[a][b][who][ban];
    if (!can_move(ban, a) && !can_move(ban, b))
        return ret = 0;
    else
    {
        if (who == 0)
        {
            if (can_move(ban, a))
            {
                ret = -MOD;
                for (auto &x : g[a])
                {
                    if (ban & (1LL << x))
                        continue;
                    ret = max(ret, 1 + calc(s, ban | (1LL << x), x, b, 1));
                }
                return ret;
            }
            return ret = calc(s, ban, a, b, 1);
        }
        else
        {
            if (can_move(ban, b))
            {
                ret = MOD;
                for (auto &x : g[b])
                {
                    if (ban & (1LL << x))
                        continue;
                    ret = min(ret, -1 + calc(s, ban | (1LL << x), a, x, 0));
                }
                return ret;
            }
            return ret = calc(s, ban, a, b, 0);
        }
    }
}

void solveCase()
{
    int s, ra, pa, rb, pb, c;
    cin >> s >> ra >> pa >> rb >> pb >> c;
    --ra, --pa, --rb, --pb;
    int ptr = 0;
    for (size_t i = 0; i < s; i++)
        for (size_t j = 0; j < 2 * i + 1; j++)
        {
            id[i][j] = ptr++;
            g[id[i][j]].clear();
        }
    auto add_edge = [&](int ra, int pa, int rb, int pb) {
        int u = id[ra][pa], v = id[rb][pb];
        g[u].pb(v);
        g[v].pb(u);
    };
    for (int i = 0; i < 36; i++)
        for (size_t j = 0; j < 36; j++)
        {
            ok[i][j][0].clear();
            ok[i][j][1].clear();
        }

    for (size_t i = 0; i < s; i++)
    {
        for (size_t j = 1; j < 2 * i + 1; j++)
            add_edge(i, j, i, j - 1);
        for (size_t j = 0; j < 2 * i + 1; j++)
            if (i + 1 < s && j % 2 == 0)
                add_edge(i, j, i + 1, j + 1);
    }
    ll ban = 0;
    for (size_t i = 0; i < c; i++)
    {
        int r, p;
        cin >> r >> p;
        --r, --p;
        ban |= 1LL << id[r][p];
    }
    ban |= 1LL << (id[ra][pa]);
    ban |= 1LL << (id[rb][pb]);
    cout << calc(s, ban, id[ra][pa], id[rb][pb], 0) << '\n';
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
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
