// Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define MULTI_TEST
#ifdef LOCAL
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
#define pc(...) PC(#__VA_ARGS__, __VA_ARGS__);
template <typename T, typename U>
ostream &operator<<(ostream &out, const pair<T, U> &p)
{
    out << '[' << p.first << ", " << p.second << ']';
    return out;
}
template <typename Arg>
void PC(const char *name, Arg &&arg)
{
    while (*name == ',' || *name == ' ')
        name++;
    std::cerr << name << " { ";
    for (const auto &v : arg)
        cerr << v << ' ';
    cerr << " }\n";
}
template <typename Arg1, typename... Args>
void PC(const char *names, Arg1 &&arg1, Args &&... args)
{
    while (*names == ',' || *names == ' ')
        names++;
    const char *comma = strchr(names, ',');
    std::cerr.write(names, comma - names) << " { ";
    for (const auto &v : arg1)
        cerr << v << ' ';
    cerr << " }\n";
    PC(comma, args...);
}
template <typename Arg1>
void ZZ(const char *name, Arg1 &&arg1)
{
    std::cerr << name << " = " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void ZZ(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    std::cerr.write(names, comma - names) << " = " << arg1;
    ZZ(comma, args...);
}
#else
#define db(...)
#define pc(...)
#endif

using ll = long long;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()
auto TimeStart = chrono::steady_clock::now();
auto seed = TimeStart.time_since_epoch().count();
std::mt19937 rng(seed);
template <typename T>
using Random = std::uniform_int_distribution<T>;

const int NAX = 2e5 + 5, MOD = 1000000007, s = 1 << 17;
int q, n, x, a[NAX];
vector<int> pos[NAX];

class segtree
{
public:
    ll seg[s * 2], lazy[2 * s];
    void init()
    {
        memset(seg, 0, sizeof seg);
        memset(lazy, 0, sizeof lazy);
    }
    void lazy_evaluate(int k)
    {
        if ((k * 2 + 2) >= s * 2)
            return;
        lazy[2 * k + 2] += lazy[k];
        lazy[2 * k + 1] += lazy[k];
        seg[2 * k + 1] += lazy[k];
        seg[2 * k + 2] += lazy[k];
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
        // db("Query", beg, end, idx, lb, ub);
        if (ub < beg || end < lb)
            return -1000000000000000000LL;
        if (beg <= lb && ub <= end)
            return seg[idx];
        if (lazy[idx])
            lazy_evaluate(idx);
        return max(
            query(beg, end, idx * 2 + 1, lb, (lb + ub) / 2),
            query(beg, end, idx * 2 + 2, (lb + ub) / 2 + 1, ub));
    }
} kaede;

void solveCase(int caseNo)
{
    // db("a");
    kaede.init();
    for (int i = 0; i < NAX; ++i)
        pos[i].clear();
    // db("b");
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pos[a[i]].pb(i);
    }
    // db("c");
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        // db(i, "D");
        kaede.update(i, i, 0, 0, s - 1, 1);
        int t = lower_bound(pos[a[i]].begin(), pos[a[i]].end(), i) - pos[a[i]].begin();
        t++;
        // db(i, "E");
        if (t <= x)
            kaede.update(1, i - 1, 0, 0, s - 1, 1);
        else
        {
            int p = pos[a[i]][t - x - 1];
            kaede.update(p + 1, i - 1, 0, 0, s - 1, 1);
            int q = 1;
            if (t - x - 1 > 0)
                q = pos[a[i]][t - x - 2] + 1;
            kaede.update(q, p, 0, 0, s - 1, -x);
        }
        // db(i, "F");
        ans = max(ans, kaede.query(1, i, 0, 0, s - 1));
    }
    cout << "Case #" << caseNo << ": ";
    cout << ans << '\n';
    // db("e");
}

#include<stdio.h>
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==42) break ;
        printf("%d\n",n);
    }
}

int main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    for (int i = 1; i <= t; ++i)
    {
        solveCase(i);
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
