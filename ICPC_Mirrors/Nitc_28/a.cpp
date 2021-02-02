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

#define int ll

vector<int> ranges;
vector<pair<int, pair<int, int>>> Q;
// vector<pair<int, pair<int, int>>> compressedQ;

void add_to_range(int x)
{
    ranges.pb(x - 1);
    ranges.pb(x);
    ranges.pb(x + 1);
}

int compress_int(int x)
{
    return lower_bound(all(ranges), x) - ranges.begin();
}

struct Node
{
    set<int> val;
    Node() {}
    Node lazylazyMerge(const Node &rhs)
    {
        Node a = *this;
        // a.val = (a.val + rhs.val);
        return a;
    }
    Node seglazyMerge(const Node &rhs, const int &l, const int &r)
    {
        Node a = *this;
        // a.val += (r - l + 1) * (rhs.val);
        return a;
    }
    Node segSegMerge(const Node &rhs)
    {
        Node a = *this;
        // a.val = (a.val + rhs.val);
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
    void insert(int node, int start, int end, int qstart, int qend, int val)
    {
        if (qend < start || qstart > end || start > end)
            return;
        if (qstart <= start && end <= qend)
        {
            // isLazy[node] = true;
            // Lazy[node] = val;
            // propagate(node, start, end);
            Seg[node].val.insert(val);
            return;
        }
        int mid = (start + end) / 2;
        insert(2 * node, start, mid, qstart, qend, val);
        insert(2 * node + 1, mid + 1, end, qstart, qend, val);
        // Seg[node] = Seg[2 * node].segSegMerge(Seg[2 * node + 1]);
    }
    void remove(int node, int start, int end, int qstart, int qend, int val)
    {
        if (qend < start || qstart > end || start > end)
            return;
        if (qstart <= start && end <= qend)
        {
            // isLazy[node] = true;
            // Lazy[node] = val;
            // propagate(node, start, end);
            Seg[node].val.erase(val);
            return;
        }
        int mid = (start + end) / 2;
        remove(2 * node, start, mid, qstart, qend, val);
        remove(2 * node + 1, mid + 1, end, qstart, qend, val);
        // Seg[node] = Seg[2 * node].segSegMerge(Seg[2 * node + 1]);
    }
    bool check(int circle_idx, int point_idx)
    {
        ll dist = (Q[circle_idx].second.first - Q[point_idx].second.first) * 1LL * (Q[circle_idx].second.first - Q[point_idx].second.first);
        dist += (Q[circle_idx].second.second - Q[point_idx].second.second) * 1LL * (Q[circle_idx].second.second - Q[point_idx].second.second);
        return dist < Q[circle_idx].second.second * Q[circle_idx].second.second;
    }
    int check_node_pos(int node, int idx)
    {
        assert(Seg[node].val.size() < 100);
        for (auto &x : Seg[node].val)
        {
            if (check(x, idx))
                return x;
        }
        return -1;
    }
    int query(int node, int start, int end, int pos, int idx)
    {
        if (start > end)
            return -1;
        auto check_node = check_node_pos(node, idx);
        if (check_node != -1)
            return check_node;
        if (start == end)
            return -1;
        int mid = (start + end) / 2;
        if (pos <= mid)
            return query(2 * node, start, mid, pos, idx);
        return query(2 * node + 1, mid + 1, end, pos, idx);
    }
};

void solveCase()
{
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;
        Q.pb({t, {x, y}});
        if (t == 1)
        {
            add_to_range(x);
            add_to_range(x + y);
            add_to_range(x - y);
        }
        else
        {
            add_to_range(x);
        }
    }
    sort(all(ranges));
    ranges.erase(unique(all(ranges)), ranges.end());
    Segtree<Node> stree(ranges.size());
    for (size_t i = 0; i < n; i++)
    {
        if (Q[i].first == 1)
        {
            stree.insert(1, 0, ranges.size() - 1, compress_int(Q[i].second.first - Q[i].second.second), compress_int(Q[i].second.first + Q[i].second.second), i);
        }
        else
        {
            auto idx = stree.query(1, 0, ranges.size() - 1, compress_int(Q[i].second.first), i);
            if (idx != -1)
            {
                stree.remove(1, 0, ranges.size() - 1, compress_int(Q[idx].second.first - Q[idx].second.second), compress_int(Q[idx].second.first + Q[idx].second.second), idx);
                idx++;
            }
            cout << idx << '\n';
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