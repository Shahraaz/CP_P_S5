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
            cout << rangeSum(i, i) << ' ';
        cout << '\n';
#else

#endif
    }
};

void solveCase()
{
    int n;
    cin >> n;
    vector<pair<char, int>> ca(2 * n);
    map<pair<char, int>, int> inv_mapper;
    Bit b(2 * n);
    for (size_t i = 0; i < 2 * n; i++)
    {
        char c;
        int a;
        cin >> c >> a;
        --a;
        ca[i] = {c, a};
        inv_mapper[ca[i]] = i;
        b.update(i, 1);
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, MOD));
    vector<vector<pair<int, int>>> prev(n + 1, vector<pair<int, int>>(n + 1, make_pair(-1, -1)));
    vector<vector<ll>> vis(n + 1, vector<ll>(n + 1, 0));
    dp[0][0] = 0;
    db(inv_mapper);
    for (int i = 0; i <= n; i++)
    {
        auto idx_w_new = inv_mapper[make_pair('W', i)];
        db(i, idx_w_new);
        for (int j = 0; j <= n; j++)
        {
            // db(i, j, dp[i][j], prev[i][j]);
            // b.print();
            /*
                i white are placed
                j black are placed
            */
            int newpos = i + j;
            int idx_b_j = inv_mapper[make_pair('B', j)];
            // db(idx_w_new, idx_b_j, newpos);
            assert(dp[i][j] <= MOD);
            if (i + 1 <= n) // try placing i+1 th white at new pos
            {
                // if (idx_w_new <= newpos)
                //     dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
                // else
                // {
                // db(i + 1, j, b.rangeSum(0, idx_w_new));
                auto newval = b.rangeSum(0, idx_w_new) - 1 + dp[i][j];
                if (newval < dp[i + 1][j])
                {
                    prev[i + 1][j] = {i, j};
                    dp[i + 1][j] = newval;
                }
                // }
            }
            if (j + 1 <= n) // try placing j+1 th black at new pos
            {
                // if (idx_b_j <= newpos)
                //     dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
                // else
                // {
                // db(i, j + 1, b.rangeSum(0, idx_b_j), '\n');
                auto nval = b.rangeSum(0, idx_b_j) - 1 + dp[i][j];
                if (nval < dp[i][j + 1])
                {
                    dp[i][j + 1] = nval;
                    prev[i][j + 1] = {i, j};
                }
                // }
            }
            if (j != n)
                b.update(idx_b_j, -1);
        }
        db(i, dp[i]);
        db(prev[i], "\n\n");
        for (size_t j = 0; j < n; j++)
        {
            int idx_b_j = inv_mapper[make_pair('B', j)];
            b.update(idx_b_j, 1);
        }
        int idx_w_i = inv_mapper[make_pair('W', i)];
        b.update(idx_w_i, -1);
    }
    db(n, dp[n]);
    cout << dp[n][n] << '\n';
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