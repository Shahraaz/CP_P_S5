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

struct Node
{
    long long sum, prefix, suffix, res;
    Node(ll _val = 0)
    {
        sum = _val;
        if (_val < 0)
            _val = 0;
        // max(_val)
        prefix = suffix = res = _val;
    }
    Node segSegMerge(const Node &rhs)
    {
        Node a = *this;
        a.sum = sum + rhs.sum;
        a.prefix = max(prefix, sum + rhs.prefix);
        a.suffix = max(rhs.suffix, rhs.sum + suffix);
        a.res = max({res, rhs.res, suffix + rhs.prefix});
        return a;
    }
};

template <typename segNode>
struct Segtree
{
    vector<segNode> Seg;
    vector<segNode> Base;
    int n;
    Segtree(int _n = 2e5)
    {
        this->n = _n;
        Seg.resize(4 * _n + 10);
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
        build(1, 0, n - 1);
    }
    segNode Query(int node, int start, int end, int qstart, int qend)
    {
        if (qend < start || qstart > end || start > end)
            return segNode();
        if (qstart <= start && end <= qend)
            return Seg[node];
        int mid = (start + end) / 2;
        segNode l = Query(2 * node, start, mid, qstart, qend);
        segNode r = Query(2 * node + 1, mid + 1, end, qstart, qend);
        return l.segSegMerge(r);
    }
    segNode query(int left, int right)
    {
        return Query(1, 0, n - 1, left, right);
    }
};

void solveCase()
{
    int n;
    cin >> n;
    vector<int> v(n), d(n);
    for (size_t i = 0; i < n; i++)
        cin >> v[i] >> d[i];
    vector<Segtree<Node>> forward(7);
    vector<Segtree<Node>> backward(7);
    vector<int> mult = {0, 1, 2, 3, 2, 1, 0};
    db(v);
    db(d);
    for (int i = 0; i < 7; i++)
    {
        int day = (7 - i) % 7;
        int curr = day;
        vector<int> val(n), diff(n);
        vector<Node> f(n);
        for (size_t j = 0; j < n; j++)
        {
            db(i, j, curr);
            val[j] = v[j] + mult[curr % 7] * d[j];
            curr++;
        }
        for (size_t j = 0; j + 1 < n; j++)
        {
            diff[j] = val[j + 1] - val[j];
            f[j] = Node(diff[j]);
        }
        db(i, "f", val, diff);

        forward[i].build(f);

        curr = day;
        for (int j = n - 1; j >= 0; j--)
        {
            val[j] = v[j] + mult[curr % 7] * d[j];
            curr++;
        }

        reverse(all(val));
        for (size_t j = 0; j + 1 < n; j++)
        {
            diff[j] = val[j + 1] - val[j];
            f[j] = Node(diff[j]);
        }
        db(i, "b", val, diff);

        backward[i].build(f);
    }
#ifdef LOCAL
    for (size_t i = 0; i < n; i++)
    {
        // db(i);
        for (size_t j = i + 1; j < n; j++)
        {
            int s = i, t = j;
            if (s <= t)
            {
                db(s, t, s % 7);
                cout << forward[s % 7].query(s, t - 1).res << ' ';
            }
            else // s > t
            {
                s = n - 1 - s;
                t = n - 1 - t;
                cout << backward[s % 7].query(s, t - 1).res << ' ';
            }
        }
        cout << '\n';
    }
#endif
    int q;
    cin >> q;
    for (size_t i = 0; i < q; i++)
    {
        int s, t;
        cin >> s >> t;
        --s, --t;
        if (s < t)
        {
            cout << forward[s % 7].query(s, t - 1).res << '\n';
        }
        else // s > t
        {
            s = n - 1 - s;
            t = n - 1 - t;
            cout << backward[s % 7].query(s, t - 1).res << '\n';
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