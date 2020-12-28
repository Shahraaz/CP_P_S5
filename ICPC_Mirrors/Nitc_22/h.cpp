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

int n, m;
vector<vector<int>> row, cols;
vector<vector<int>> rowmask;

bool check(int &n, int &mask, vector<int> &tocheck)
{
    int k = tocheck.size();
    if (k == 0)
        return mask == 0;
    int cur = 0, j = 0;
    for (int i = 0; i <= n; i++)
    {
        cur += mask >> i & 1;
        if (cur > 0 && !(mask >> i & 1))
        {
            if (j < k && cur != tocheck[j])
                return false;
            ++j;
            cur = 0;
        }
    }
    return j == k;
}

void solveCase()
{
    cin >> n >> m;
    row.resize(n);
    for (auto &x : row)
    {
        int sz;
        cin >> sz;
        x.resize(sz);
        for (auto &y : x)
            cin >> y;
    }
    cols.resize(m);
    for (auto &x : cols)
    {
        int sz;
        cin >> sz;
        x.resize(sz);
        for (auto &y : x)
            cin >> y;
    }
    rowmask.resize(n);
    const int LIM = 5;
    for (size_t i = 0; i < n; i++)
        for (int mask = 0; mask < (1 << m); mask++)
            if (check(m, mask, row[i]))
                rowmask[i].pb(mask);
    int ans = 0;
    vector<int> masks(n);
    function<void(int)> attempt = [&](int i) -> void {
        if (i == n)
        {
            vector<int> mask_cols(m);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (masks[i] >> j & 1)
                        mask_cols[j] |= 1 << i;
            for (size_t i = 0; i < m; i++)
                if (!check(n, mask_cols[i], cols[i]))
                    return;
            ans++;
            return;
        }
        for (auto x : rowmask[i])
        {
            masks[i] = x;
            attempt(i + 1);
        }
    };
    attempt(0);
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