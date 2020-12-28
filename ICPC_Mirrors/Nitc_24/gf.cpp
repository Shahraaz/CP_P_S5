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
const int NAX = 5e4 + 5, MOD = 1000000007;

int n, m, k, cnt, len;
ll ans;
int a[NAX], ehead[NAX], typ[NAX], mi[13];
int st[NAX], sum[NAX];

struct ed
{
    int to, nxt;
} e[NAX * 2];

vector<int> ziji[1024];
bool vis[NAX];

struct centretree
{
    int n, ans, mini;
    int son[NAX];
    void dfs(int u, int f)
    {
        son[u] = 1;
        int mx = 0, v;
        for (int i = ehead[u]; i; i = e[i].nxt)
        {
            v = e[i].to;
            if (v == f || vis[v])
                continue;
            dfs(v, u);
            son[u] += son[v];
            mx = max(mx, son[v]);
        }
        mx = max(mx, n - son[u]);
        db(u, son[u]);
        if (mx < mini)
        {
            mini = mx;
            ans = u;
        }
    }
    int getcenter(int u)
    {
        ans = 0, mini = MOD;
        db("getcenter", u);
        dfs(u, 0);
        db("end getcenter", u, ans);
        return ans;
    }
} ttree;

void add(int u, int v)
{
    e[++cnt].to = v;
    e[cnt].nxt = ehead[u];
    ehead[u] = cnt;
}

void getst(int u, int fa)
{
    db("getst", len, u, fa, st[u]);
    a[++len] = st[u];
    int v;
    for (int i = ehead[u]; i; i = e[i].nxt)
    {
        v = e[i].to;
        if (v == fa || vis[v])
            continue;
        st[v] = st[u] | mi[typ[v]];
        getst(v, u);
    }
}

ll calc(int u, int ss)
{
    db("calc", u, ss);
    len = 0;
    st[u] = mi[typ[u]];
    getst(u, 0);
    for (size_t i = 0; i < mi[k + 1]; i++)
        sum[i] = 0;
    ll ret = 0;
    for (size_t i = 1; i <= len; i++)
    {
        db(i, a[i]);
        for (auto &s0 : ziji[a[i]])
        {
#ifdef LOCAL
            cout << s0 << ' ';
#endif
            sum[s0]++;
        }
#ifdef LOCAL
        cout << '\n';
#endif
    }
    sum[0] = len;
    for (size_t i = 1; i <= len; i++)
    {
        int s = ss & a[i];
        ret += sum[ss ^ s];
    }
    return ret;
}

void solve(int u)
{
    db("solve", u, k, mi[k + 1] - 1);
    vis[u] = 1;
    ans += calc(u, mi[k + 1] - 1);
    int v, rt;
    for (int i = ehead[u]; i; i = e[i].nxt)
    {
        v = e[i].to;
        if (vis[v])
            continue;
        ans -= calc(v, (mi[k + 1] - 1) ^ (mi[typ[u]]));
        ttree.n = ttree.son[v];
        rt = ttree.getcenter(v);
        solve(rt);
    }
}

void solveCase()
{
    for (size_t i = 1; i <= n; i++)
        ehead[i] = 0, vis[i] = 0;
    for (size_t i = 1; i <= n; i++)
        cin >> typ[i];
    for (size_t i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    cnt = 0;
    ans = 0, ttree.n = n;
    int rt = ttree.getcenter(1);
    solve(rt);
    cout << ans << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    for (int i = 1; i < 12; i++)
        mi[i] = 1 << (i - 1);
    for (int i = 1; i < 1024; i++)
        for (int s0 = i; s0; s0 = (s0 - 1) & i)
            ziji[i].pb(s0);
    n, k;
    while (cin >> n >> k)
        solveCase();
    return 0;
}