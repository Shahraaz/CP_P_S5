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

struct Bit
{
    int size;
    vector<int> table;
    Bit(int size)
    {
        this->size = size;
        table.resize(size);
    }
    void update(int i, int delta)
    {
        while (i < size)
        {
            table[i] += delta;
            i = i | (1 + i);
        }
    }
    void find_and_replace(int i, int val)
    {
        update(i, val - (sum(i) - sum(i - 1)));
    }
    int sum(int i)
    {
        int ret = 0;
        while (i >= 0)
        {
            ret += table[i];
            i = (i & (i + 1)) - 1;
        }
        return ret;
    }
    int rangeSum(int i, int j)
    {
        if (i == 0)
            return sum(j);
        return sum(j) - sum(i - 1);
    }
    void print()
    {
#ifdef LOCAL
        for (int i = 0; i < size; i++)
            cout << sum(i) << ' ';
        cout << '\n';
#else

#endif
    }
};

void solveCase()
{
    int h, w, m;
    cin >> h >> w >> m;
    vector<pair<int, int>> vecc(m);
    vector<int> col(w + 1, h), row(h, w);
    vector<vector<int>> colidx(w + 1);
    for (auto &[x, y] : vecc)
    {
        cin >> x >> y;
        --x, --y;
        colidx[y].pb(x);
        col[y] = min(col[y], x);
        row[x] = min(row[x], y);
    }
    // sort(all(vecc));
    ll res = 0;
    res += row[0];
    db(row);
    db(col);
    for (size_t i = 1; i < col[0]; i++)
        res += row[i];
    db(res);
    Bit bit(h + 1);
    bit.find_and_replace(col[0], 1);
    for (size_t j = 1; j < row[0]; j++)
    {
        // res += col[j];
        int mini = min(col[0], col[j]);
        auto delta = bit.sum(mini - 1);
        bit.print();
        db(j, col[j], mini, delta);
        res += col[j] - mini;
        res += delta;
        for (auto &y : colidx[j])
            bit.find_and_replace(y, 1);
    }
    cout << res << '\n';
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