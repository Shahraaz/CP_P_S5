#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

#define all(v) v.begin(), v.end()
#define pb push_back
const int NAX = 5e5 + 5, MOD = 1000000007;

#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
using ll = long long;

int add(int a, int b, int mod)
{
    // assert(0 <= a && a < mod);
    // assert(0 <= b && b < mod);

    a += b;
    if (a >= mod)
        a -= mod;
    // assert(0 <= a && a < mod);
    return a;
}

struct Hash_RabinKarp
{
    const int maxSize = NAX;
    const long long p1 = 400291, p2 = 499957, p3 = 31;
    const int mod1 = 998244353, mod2 = 1000000009, mod3 = 1e9 + 9;
    vector<long long> p_pow1, p_pow2, p_pow3;
    vector<long long> p_sum1, p_sum2, p_sum3;
    vector<long long> inv_pow1, inv_pow2, inv_pow3;
    ll expo(ll base, int index, int mod)
    {
        if (index == 0)
            return 1;
        ll temp = expo(base, index / 2, mod);
        temp = (temp * temp) % mod;
        if (index & 1)
            temp = (temp * base) % mod;
        return temp;
    }
    Hash_RabinKarp()
    {
        p_pow1.resize(maxSize);
        p_pow2.resize(maxSize);
        p_pow3.resize(maxSize);
        inv_pow1.resize(maxSize);
        inv_pow2.resize(maxSize);
        inv_pow3.resize(maxSize);
        p_pow1[0] = p_pow2[0] = p_pow3[0] = 1;
        for (int i = 1; i < (int)p_pow1.size(); i++)
        {
            p_pow1[i] = (p_pow1[i - 1] * p1) % mod1;
            p_pow2[i] = (p_pow2[i - 1] * p2) % mod2;
            p_pow3[i] = (p_pow3[i - 1] * p3) % mod3;
        }

        p_sum1 = p_pow1;
        p_sum2 = p_pow2;
        p_sum3 = p_pow3;
        for (int i = 1; i < (int)p_pow1.size(); i++)
        {
            p_sum1[i] = add(p_pow1[i], p_sum1[i - 1], mod1);
            p_sum2[i] = add(p_pow2[i], p_sum2[i - 1], mod2);
            p_sum3[i] = add(p_pow3[i], p_sum3[i - 1], mod3);
        }

        inv_pow1[maxSize - 1] = expo(p_pow1[maxSize - 1], mod1 - 2, mod1);
        inv_pow2[maxSize - 1] = expo(p_pow2[maxSize - 1], mod2 - 2, mod2);
        inv_pow3[maxSize - 1] = expo(p_pow3[maxSize - 1], mod3 - 2, mod3);
        for (int i = maxSize - 2; i >= 0; --i)
        {
            inv_pow1[i] = (inv_pow1[i + 1] * p1) % mod1;
            inv_pow2[i] = (inv_pow2[i + 1] * p2) % mod2;
            inv_pow3[i] = (inv_pow3[i + 1] * p3) % mod3;
        }
    }
} hashTables;

struct Node
{
    pair<long long, long long> val;
    int len;
    Node(pair<long long, long long> _val = {0, 0}, int _len = 0) : val(_val), len(_len) {}
    Node lazylazyMerge(const Node &rhs)
    {
        Node a = *this;
        a.val.first = (a.val.first + rhs.val.first);
        return a;
    }
    Node seglazyMerge(const Node &rhs, const int &l, const int &r)
    {
        Node a = *this;
        a.val.first = add(a.val.first, (hashTables.p_sum1[r - l] * rhs.val.first) % hashTables.mod1, hashTables.mod1);
        a.val.second = add(a.val.second, (hashTables.p_sum2[r - l] * rhs.val.first) % hashTables.mod2, hashTables.mod2);
        // db(val, len, rhs.val, rhs.len, a.val, a.len);
        return a;
    }
    Node segSegMerge(const Node &rhs)
    {
        Node a = *this;
        a.val.first = add((a.val.first * hashTables.p_pow1[rhs.len]) % hashTables.mod1, rhs.val.first, hashTables.mod1);
        a.val.second = add((a.val.second * hashTables.p_pow2[rhs.len]) % hashTables.mod2, rhs.val.second, hashTables.mod2);
        a.len += rhs.len;
        // db(val, len, rhs.val, rhs.len, a.val, a.len);
        return a;
    }
};

struct NodeMax
{
    long long val, idx;
    NodeMax(long long _val = 0, long long _idx = -1) : val(_val), idx(_idx) {}
    NodeMax lazylazyMerge(const NodeMax &rhs)
    {
        NodeMax a = *this;
        a.val = (a.val + rhs.val);
        return a;
    }
    NodeMax seglazyMerge(const NodeMax &rhs, const int &l, const int &r)
    {
        NodeMax a = *this;
        a.val += (rhs.val);
        return a;
    }
    NodeMax segSegMerge(const NodeMax &rhs)
    {
        NodeMax a = *this;
        if (a.val < rhs.val)
            return rhs;
        return a;
    }
};

template <typename segNode>
struct Segtree
{
    vector<segNode> Seg, Lazy;
    vector<segNode> Base;
    vector<bool> isLazy;
    int n;
    Segtree(int _n = 5e5)
    {
        this->n = _n;
        Seg.resize(4 * _n + 10);
        Lazy.resize(4 * _n + 10);
        isLazy.resize(4 * _n + 10);
    }
    void merge(segNode &curr, segNode &l, segNode &r)
    {
        curr = l + r;
    }
    void propagate(int node, int L, int R)
    {
        if (isLazy[node])
        {
            isLazy[node] = false;
            Seg[node] = Seg[node].seglazyMerge(Lazy[node], L, R);
            if (L != R)
            {
                Lazy[2 * node] = Lazy[2 * node].lazylazyMerge(Lazy[node]);
                Lazy[2 * node + 1] = Lazy[2 * node + 1].lazylazyMerge(Lazy[node]);
                isLazy[2 * node] = true;
                isLazy[2 * node + 1] = true;
            }
            Lazy[node] = segNode();
        }
    }
    void build(int node, int start, int end)
    {
        if (start == end)
        {
            Seg[node] = Base[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        Seg[node] = Seg[2 * node].segSegMerge(Seg[2 * node + 1]);
    }
    void build(vector<segNode> &Arr)
    {
        Base = Arr;
        n = Arr.size();
        Seg.resize(4 * n + 10);
        Lazy.resize(4 * n + 10);
        isLazy.resize(4 * n + 10);
        build(1, 0, n - 1);
    }
    segNode Query(int node, int start, int end, int qstart, int qend)
    {
        propagate(node, start, end);
        if (qend < start || qstart > end || start > end)
            return segNode();
        if (qstart <= start && end <= qend)
            return Seg[node];
        int mid = (start + end) / 2;
        segNode l = Query(2 * node, start, mid, qstart, qend);
        segNode r = Query(2 * node + 1, mid + 1, end, qstart, qend);
        auto ret = l.segSegMerge(r);
        // db(start, end, qstart, qend, l.val, r.val, ret.val);
        return ret;
    }
    segNode qQuery(int node, int start, int end, int pos)
    {
        propagate(node, start, end);
        if (start == end)
            return Seg[node];
        int mid = (start + end) / 2;
        if (pos <= mid)
            return qQuery(2 * node, start, mid, pos);
        return qQuery(2 * node + 1, mid + 1, end, pos);
    }
    void Update(int node, int start, int end, int qstart, int qend, segNode val)
    {
        propagate(node, start, end);
        if (qend < start || qstart > end || start > end)
            return;
        if (qstart <= start && end <= qend)
        {
            isLazy[node] = true;
            Lazy[node] = val;
            propagate(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        Update(2 * node, start, mid, qstart, qend, val);
        Update(2 * node + 1, mid + 1, end, qstart, qend, val);
        Seg[node] = Seg[2 * node].segSegMerge(Seg[2 * node + 1]);
    }
    void pUpdate(int node, int start, int end, int pos, segNode val)
    {
        propagate(node, start, end);
        if (start == end)
        {
            // isLazy[node] = true;
            // Lazy[node] = val;
            // propagate(node, start, end);
            Seg[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (pos <= mid)
            pUpdate(2 * node, start, mid, pos, val);
        else
            pUpdate(2 * node + 1, mid + 1, end, pos, val);
        Seg[node] = Seg[2 * node].segSegMerge(Seg[2 * node + 1]);
    }
    segNode query(int pos)
    {
        return qQuery(1, 0, n - 1, pos);
    }
    segNode query(int left, int right)
    {
        return Query(1, 0, n - 1, left, right);
    }
    void update(int pos, segNode val)
    {
        pUpdate(1, 0, n - 1, pos, val);
    }
    void update(int start, int end, segNode val)
    {
        Update(1, 0, n - 1, start, end, val);
    }
};

void solveCase()
{
    int n, q;
    n = 500000;
    q = 500000;
    cin >> n >> q;
    vector<Node> hashtree(n);
    vector<NodeMax> maxtree(n);
    for (size_t i = 0; i < n; i++)
    {
        int a = 65535;
        cin >> a;

        hashtree[i].len = 1;
        hashtree[i].val.first = a % hashTables.mod1;
        hashtree[i].val.second = a % hashTables.mod2;

        maxtree[i].idx = i;
        maxtree[i].val = a;
    }
    Segtree<Node> hashsegtree;
    Segtree<NodeMax> maxsegtree;

    hashsegtree.build(hashtree);
    maxsegtree.build(maxtree);

    for (size_t i = 0; i < q; i++)
    {
        int ch, l, r;
        ch = rand() % 2 + 1;
        l = 1, r = n;
        // l = 1, r = n / 2;
        cin >> ch >> l >> r;
        --l, --r;
        if (ch == 1)
        {
            // assert(maxsegtree.query(l, r).val < 65536);
            // if (maxsegtree.query(l, r).val < 65536)
            //     ;
            // else
            // {
            //     cout << l << ' ' << r << ' ' << maxsegtree.query(l, r).val << ' ' << maxsegtree.query(l, r).idx << '\n';
            //     // return;
            //     exit(5);
            // }
            hashsegtree.update(l, r, Node({1, 0}, 0));
            maxsegtree.update(l, r, NodeMax(1, -1));

            // fix overflow
            // db(maxsegtree.query(l, r).val);
            while (true)
            {
                // #ifdef LOCAL
                //                 for (size_t i = 0; i < n; i++)
                //                     cout << '[' << maxsegtree.query(i, i).val << ", " << maxsegtree.query(i, i).idx << "] ";
                //                 cout << '\n';
                // #endif
                auto q = maxsegtree.query(0, n - 1);
                // db(i, 49997 + i, l, r, q.val, q.idx);
                if (q.val < 65536)
                    break;
                // assert(q.val == 65536);
                // assert(l <= q.idx && q.idx <= r);
                if (q.val == 65536)
                    ;
                else
                {
                    cout << "q.val == 65536\n";
                    cout << l << ' ' << r << ' ' << q.idx << ' ' << q.val << '\n';
                    return;
                    // exit(7);
                }
                auto idx = q.idx;
                hashsegtree.update(idx, Node({0, 0}, 1));
                maxsegtree.update(idx, NodeMax(0, idx));
            }
        }
        else
        {
            int len = 1;
            cin >> len;
            auto one = hashsegtree.query(l, l + len - 1).val;
            auto two = hashsegtree.query(r, r + len - 1).val;
            if (one == two)
                cout << "yes\n";
            else
                cout << "no\n";
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
        solveCase();
    return 0;
}