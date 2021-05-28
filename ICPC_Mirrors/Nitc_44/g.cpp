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
    int n = 1000, k = 100;
    cin >> n >> k;
    vector<vector<int>> arr(n);
    for (auto &x : arr)
    {
        x.resize(k);
        for (auto &y : x)
        {
            y = rand() % MOD;
            cin >> y;
            --y;
        }
    }
    sort(all(arr));
    auto comp = [&](int i, int j) -> int {
        vector<int> inv_mapper(n);
        for (size_t l = 0; l < k; l++)
            inv_mapper[arr[i][l]] = l;
        vector<int> other(n);
        for (size_t l = 0; l < k; l++)
            other[l] = inv_mapper[arr[j][l]];
        Bit b(k);
        int res = 0;
        for (int l = k - 1; l >= 0; l--)
        {
            b.update(other[l], 1);
            int curr = b.rangeSum(other[l], k - 1);
            res = max(res, curr);
        }
        return n - res;
    };

    vector<vector<int>> pre(n, vector<int>(n));
    for (size_t i = 0; i < n; i++)
        for (size_t j = i + 1; j < n; j++)
        {
            pre[j][i] = pre[i][j] = comp(i, j);
            db(i, j, pre[i][j]);
        }
    auto get_cost = [&](int i, int j) -> int {
        if (i <= 0 || j <= 0)
            return 0;
        return pre[i - 1][j - 1];
    };

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    function<int(int, int)> solve_dp = [&](int i, int prev) -> int {
        if (prev > i)
            swap(i, prev);
        if (i == (n + 1))
            return get_cost(i, prev);
        auto &ret = dp[i][prev];
        if (ret >= 0)
            return ret;
        ret = MOD;
        ret = min(ret, get_cost(i, i - 1) + solve_dp(i + 1, prev));
        ret = min(ret, get_cost(i, prev) + solve_dp(i + 1, i - 1));
        return ret;
    };
    cout << solve_dp(1, 0) << '\n';
}

int32_t main()
{
    srand(time(NULL));
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 5;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}