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
const int NAX = 500 + 5, MOD = 1000000007;

int M[NAX][NAX];
int dp[NAX][NAX];
int n;

int solve(int idx, int len)
{
    if (idx < 0 || idx >= n || len <= 0)
        return 0;
    auto &ret = dp[idx][len];
    if (ret >= 0)
        return ret;
    int start_ptr = idx;
    int end_ptr = idx + len - 1;
    if (end_ptr >= n)
        end_ptr -= n;
    auto next = [&](int idx) -> int {
        if (idx == end_ptr)
            idx = start_ptr;
        else
        {
            idx++;
            if (idx >= n)
                idx -= n;
        }
        return idx;
    };
    int curr_idx = start_ptr;
    ret = solve(next(curr_idx), len - 1);
    for (int i = 1; i < len; i++)
    {
        curr_idx = next(curr_idx);
        if (!M[start_ptr][curr_idx])
            continue;

        int now = 1;
        if (next(start_ptr) == curr_idx)
        {
            now += solve(next(curr_idx), len - 2);
        }
        else if (next(curr_idx) == start_ptr)
        {
            now += solve(next(start_ptr), len - 2);
        }
        else
        {
            now += solve(next(start_ptr), i - 1);
            now += solve(next(curr_idx), len - 2 - (i - 1));
        }
        ret = max(ret, now);
        //  || next(second_ptr) == curr_idx)
    }
    db(idx, len, ret);
    return ret;
}

void solveCase()
{
    n = 500;
    cin >> n;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
        {
            if (i == j)
                M[i][j] = 0;
            else
                M[i][j] = 1;
            cin >> M[i][j];
        }
    memset(dp, -1, sizeof dp);
    auto ret = solve(0, n);
    cout << ret << '\n';
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