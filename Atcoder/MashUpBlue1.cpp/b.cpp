// Optimise
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#define pc(...)
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()

const int NAX = 2e5 + 5, MOD = 1000000007;

struct Node
{
    long long val;
    Node(long long one = 0) : val(one) {}
    Node operator+(const Node &rhs)
    {
        Node a = *this;
        a.val = max(a.val, rhs.val);
        return a;
    }
    Node lazylazyMerge(const Node &rhs)
    {
        Node a = *this;
        a.val = (a.val + rhs.val);
        return a;
    }
    Node seglazyMerge(const Node &rhs)
    {
        Node a = *this;
        a.val = (a.val + rhs.val);
        return a;
    }
    Node segSegMerge(const Node &rhs)
    {
        Node a = *this;
        a.val = a.val + rhs.val;
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
    Segtree(int _n = 2e5)
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
            Seg[node] = Seg[node].seglazyMerge(Lazy[node]);
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
        return l.segSegMerge(r);
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
            isLazy[node] = true;
            Lazy[node] = val;
            propagate(node, start, end);
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

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int n;
        ll k;
        cin >> n >> k;
        vector<int> a(n + 1);
        vector<ll> prefSum(n + 1);
        for (size_t i = 1; i <= n; i++)
        {
            cin >> a[i];
            prefSum[i] = prefSum[i - 1] + a[i];
        }
        for (size_t i = 1; i <= n; i++)
            prefSum[i] -= i * k;
        pc(prefSum);
        auto dup = prefSum;
        sort(all(dup));
        dup.resize(unique(all(dup)) - dup.begin());
        for (size_t i = 0; i <= n; i++)
            prefSum[i] = lower_bound(all(dup), prefSum[i]) - dup.begin();
        Segtree<Node> S(2 * n);
        pc(prefSum);
        ll res = 0;
        for (size_t i = n; i >= 1; i--)
        {
            S.update(prefSum[i], Node(1));
            res += S.query(prefSum[i - 1], 2 * n).val;
            db(S.query(prefSum[i - 1], 2 * n).val);
        }
        cout << res << '\n';
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}