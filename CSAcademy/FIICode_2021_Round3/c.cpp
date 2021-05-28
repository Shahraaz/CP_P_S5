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

#include <bits/stdc++.h>
using namespace std;

template <typename inpType, int (*func)(int, int)>
struct sparseTree
{
    int n, logLim, def;
    vector<vector<int>> lookup;

    void buildSparseTable(inpType &arr, int n, int def)
    {
        this->n = n;
        this->def = def;
        logLim = __lg(n) + 1;
        lookup.resize(n, vector<int>(logLim, def));
        for (int i = 0; i < n; i++)
            lookup[i][0] = arr[i];
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 0; i < n; i++)
                lookup[i][j] = lookup[lookup[i][j - 1]][j - 1];
    }

    int query(int L, int R)
    {
        if (L < 0 || L > n - 1 || R < 0 || R > n - 1 || L > R)
            return def;
        int j = __lg(R - L + 1);
        return func(lookup[L][j], lookup[R - (1 << j) + 1][j]);
    }
};

int left(int a, int b)
{
    return a;
}

void solveCase()
{
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> next_idx(1e6 + 10, n), base(n + 1, n);
    for (int i = n - 1; i >= 0; i--)
    {
        base[i] = min(base[i + 1], next_idx[a[i]]);
        next_idx[a[i]] = i;
    }
    db(base);
    sparseTree<vector<int>, left> stree;
    stree.buildSparseTable(base, n + 1, n);
    cin >> q;
    for (size_t i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int ans = 0;
        for (int j = stree.logLim - 1; j >= 0; j--)
        {
            if (stree.lookup[l][j] <= r)
            {
                l = stree.lookup[l][j];
                ans += 1 << j;
            }
        }
        cout << ans + 1 << '\n';
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