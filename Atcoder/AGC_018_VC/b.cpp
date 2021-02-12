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
const int NAX = 300 + 5, MOD = 1000000007;

int n, m;
int fav[NAX][NAX];

int dp[1 << 10];

int solve(int mask)
{
    vector<int> cnt(m);
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (mask & (1 << fav[i][j]))
            {
                cnt[fav[i][j]]++;
                break;
            }
    return *max_element(all(cnt));
}

void solveCase()
{
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            // fav[i][j] = j;
            cin >> fav[i][j];
            fav[i][j]--;
        }
        // shuffle(fav[i], fav[i] + m, default_random_engine(time(NULL)));
        // for (size_t j = 0; j < m; j++)
        //     cout << fav[i][j] << ' ';
        // cout << '\n';
    }
    // for (size_t i = 1; i < 1 << m; i++)
    // {
    //     cout << bitset<10>(i) << ' ' << solve(i) << '\n';
    // }
    int ret = n;
    vector<int> deleted(m);
    for (size_t c = 0; c < m; c++)
    {
        vector<int> cnt(m);
        bool ok = true;
        for (size_t i = 0; i < n; i++)
        {
            bool ok2 = false;
            for (size_t j = 0; j < m; j++)
            {
                if (deleted[fav[i][j]])
                    continue;
                ok2 = true;
                cnt[fav[i][j]]++;
                break;
            }
            ok = ok && ok2;
        }
        if (!ok)
            break;
        auto idx = max_element(all(cnt)) - cnt.begin();
        ret = min(ret, cnt[idx]);
        deleted[idx] = 1;
    }
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