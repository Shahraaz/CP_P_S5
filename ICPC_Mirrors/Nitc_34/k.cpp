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

int n;
long long x, y, u, v, ans = 0;
vector<long long> ve;

struct event
{
    long long u, l, r, val;
    event(ll _u, ll _l, ll _r, ll _val) : u(_u), l(_l), r(_r), val(_val) {}
};

vector<event> sw;

struct segment_tree
{
#define m (l + r) / 2
#define lc 2 * i
#define rc 2 * i + 1
    ll eve[4 * NAX], odd[4 * NAX];
    pair<int, ll> mi[4 * NAX];
    int lz[4 * NAX];

    void apply(int i, int v)
    {
        lz[i] += v;
        mi[i].first += v;
        if (abs(v) % 2 == 1)
            swap(eve[i], odd[i]);
    }

    void down(int i)
    {
        apply(lc, lz[i]);
        apply(rc, lz[i]);
        lz[i] = 0;
    }

    void build(int l, int r, int i)
    {
        if (l == r)
        {
            eve[i] = mi[i].second = ve[l + 1] - ve[l];
            odd[i] = 0;
        }
        else
        {
            build(l, m, lc);
            build(m + 1, r, rc);
            eve[i] = eve[lc] + eve[rc];
            odd[i] = 0;
            mi[i].second = eve[i];
        }
    }

    void update(int l, int r, int i, int L, int R, int v)
    {
        if (l > R || r < L || L > R)
            return;
        else if (L <= l && r <= R)
            apply(i, v);
        else
        {
            down(i);
            update(l, m, lc, L, R, v);
            update(m + 1, r, rc, L, R, v);
            eve[i] = eve[lc] + eve[rc];
            odd[i] = odd[lc] + odd[rc];
            mi[i] = min(mi[lc], mi[rc]);
            if (mi[lc].first == mi[rc].first)
                mi[i].second = mi[lc].second + mi[rc].second;
        }
        db(l, r, i, eve[i], odd[i], mi[i]);
    }

#undef m
#undef lc
#undef rc
} seg;

void solveCase()
{
    cin >> n;
    for (size_t i = 1; i <= n; i++)
    {
        cin >> x >> y >> u >> v;
        if (x > u)
            swap(x, u);
        if (y > v)
            swap(y, v);
        if (x == u || y == v)
            continue;
        sw.pb(event(x, y, v, 1));
        sw.pb(event(u, y, v, -1));
        ve.pb(y);
        ve.pb(v);
    }
    if (sw.empty())
        return cout << 0, void();
    sort(all(ve));
    ve.erase(unique(all(ve)), ve.end());
    sort(all(sw), [](const event &l, const event &r) -> bool {
        return l.u < r.u;
    });
    int n = ve.size() - 1;
    seg.build(0, n - 1, 1);
    for (size_t i = 0; i + 1 < sw.size(); i++)
    {
        int l = distance(ve.begin(), lower_bound(all(ve), sw[i].l));
        int r = distance(ve.begin(), lower_bound(all(ve), sw[i].r)) - 1;
        seg.update(0, n - 1, 1, l, r, sw[i].val);
        db(seg.eve[1], seg.odd[1], seg.mi[1]);
        ans += (sw[i + 1].u - sw[i].u + 0LL) * (seg.eve[1] - (seg.mi[1].first == 0) * seg.mi[1].second);
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