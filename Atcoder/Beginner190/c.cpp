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

void solveCase()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ab(m);
    for (size_t i = 0; i < m; i++)
    {
        cin >> ab[i].first >> ab[i].second;
        ab[i].first--;
        ab[i].second--;
    }
    int k;
    cin >> k;
    vector<pair<int, int>> cd(k);
    for (size_t i = 0; i < k; i++)
    {
        cin >> cd[i].first >> cd[i].second;
        cd[i].first--;
        cd[i].second--;
    }
    vector<int> cnt(n);
    int res = 0;
    function<void(int)> solve = [&](int idx) -> void {
        if (idx == k)
        {
            int curr = 0;
            for (size_t i = 0; i < m; i++)
                curr += cnt[ab[i].first] && cnt[ab[i].second];
            res = max(res, curr);
            return;
        }
        cnt[cd[idx].first]++;
        solve(idx + 1);
        cnt[cd[idx].first]--;
        cnt[cd[idx].second]++;
        solve(idx + 1);
        cnt[cd[idx].second]--;
    };
    solve(0);
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