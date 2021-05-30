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

struct node
{
    int count;
    node *left, *right;

    node(int _count, node *_left, node *_right) : count(_count), left(_left), right(_right) {}
    node *insert(int l, int r, int w, int dx);
};

node *null = new node(0, NULL, NULL);

node *node::insert(int l, int r, int w, int dx)
{
    if (l <= w && w <= r)
    {
        if (l == r)
            return new node(this->count + dx, null, null);

        int mid = (l + r) / 2;

        return new node(this->count + dx, this->left->insert(l, mid, w, dx), this->right->insert(mid + 1, r, w, dx));
    }
    return this;
}

int query(node *a, int start, int end, int qstart, int qend)
{
    if (qend < start || qstart > end || start > end)
        return 0;
    if (qstart <= start && end <= qend)
        return a->count;
    int mid = (start + end) / 2;
    int l = query(a->left, start, mid, qstart, qend);
    int r = query(a->right, mid + 1, end, qstart, qend);
    return l + r;
}

const int LIM = 1e5 + 5;
node *root[LIM];
// null->left = null->right = null;

void solveCase()
{
    null->left = null->right = null;
    int n;
    cin >> n;
    auto r = null;
    cin.ignore();
    root[0] = null;
    for (size_t i = 1; i <= n; i++)
    {
        string str;
        getline(cin, str);
        db(i, str);
        stringstream sin(str);
        while (sin >> str)
        {
            assert(str[0] == '+' || str[0] == '-');
            auto c = str[0];
            str = str.substr(1);
            int num = stoi(str);
            db(i, c, num);
            if (c == '+')
                r = r->insert(0, n - 1, num, 1);
            else
                r = r->insert(0, n - 1, num, -1);
        }
        root[i] = r;
#ifdef LOCAL
        for (size_t j = 0; j < n; j++)
            cout << query(root[i], 0, n - 1, j, j) << ' ';
        cout << '\n';
#endif
    }
    int x = 0;
    for (size_t i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        int q = query(root[d], 0, n - 1, x, n - 1);
        db(i, d, q);
        x = (x + q) % n;
    }
    cout << x << '\n';
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