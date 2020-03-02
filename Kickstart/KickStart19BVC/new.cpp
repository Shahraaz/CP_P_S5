#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> P1;
typedef pair<P, P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i, x) for (int i = 0; i < x; i++)
#define repn(i, x) for (int i = 1; i <= x; i++)
#define SORT(x) sort(x.begin(), x.end())
#define ERASE(x) x.erase(unique(x.begin(), x.end()), x.end())
#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())

int q, n, x;
int a[100005];
vector<int> pos[100005];

class segtree
{
public:
#define s (1 << 17)

    ll seg[s * 2];
    ll lazy[s * 2];
    void init()
    {
        memset(seg, 0, sizeof(seg));
        memset(lazy, 0, sizeof(lazy));
    }
    void lazy_evaluate(int k)
    {
        if (k * 2 + 2 >= s * 2)
            return;
        lazy[k * 2 + 2] += lazy[k];
        lazy[k * 2 + 1] += lazy[k];
        seg[k * 2 + 2] += lazy[k];
        seg[k * 2 + 1] += lazy[k];
        lazy[k] = 0;
    }
    ll update(int beg, int end, int idx, int lb, int ub, ll num)
    {
        if (ub < beg || end < lb)
            return seg[idx];
        if (beg <= lb && ub <= end)
        {
            lazy[idx] += num;
            seg[idx] += num;
            return seg[idx];
        }
        if (lazy[idx])
            lazy_evaluate(idx);
        return seg[idx] = max(
                   update(beg, end, idx * 2 + 1, lb, (lb + ub) / 2, num),
                   update(beg, end, idx * 2 + 2, (lb + ub) / 2 + 1, ub, num));
    }
    ll query(int beg, int end, int idx, int lb, int ub)
    {
        if (ub < beg || end < lb)
        {
            return -1000000000000000000LL;
        }
        if (beg <= lb && ub <= end)
        {
            return seg[idx];
        }
        if (lazy[idx])
        {
            lazy_evaluate(idx);
        }
        return max(
            query(beg, end, idx * 2 + 1, lb, (lb + ub) / 2),
            query(beg, end, idx * 2 + 2, (lb + ub) / 2 + 1, ub));
    }
} kaede;

int main()
{
    scanf("%d", &q);
    repn(tt, q)
    {
        kaede.init();
        rep(i, 100005) pos[i].clear();
        scanf("%d%d", &n, &x);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            pos[a[i]].pb(i);
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            kaede.update(i, i, 0, 0, s - 1, 1);
            int t = POSL(pos[a[i]], i);
            t++;
            if (t <= x)
            {
                kaede.update(1, i - 1, 0, 0, s - 1, 1);
            }
            else
            {
                int p = pos[a[i]][t - x - 1];
                kaede.update(p + 1, i - 1, 0, 0, s - 1, 1);
                int q = 1;
                if (t - x - 1 > 0)
                    q = pos[a[i]][t - x - 2] + 1;
                kaede.update(q, p, 0, 0, s - 1, -x);
            }
            ans = max(ans, kaede.query(1, i, 0, 0, s - 1));
            //cout<<kaede.query(1,i,0,0,s-1)<<endl;
        }
        printf("Case #%d: %d\n", tt, ans);
    }
}