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
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (auto &x : points)
        cin >> x.first >> x.second;
    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }
    sort(all(points));
    int res = 2;
    db(points);
    vector<vector<pair<pair<int, int>, int>>> res_dp(n);
    for (size_t i = 0; i < n; i++)
    {
        map<int, pair<int, int>> mp;
        for (int j = i - 1; j >= 0; j--)
        {
            int dx = points[i].first - points[j].first;
            int dy = points[i].second - points[j].second;
            auto g = __gcd(abs(dy), abs(dx));
            dy /= g;
            dx /= g;
            db(dy, dx, j, res_dp[j]);
            auto it = lower_bound(res_dp[j].begin(), res_dp[j].end(), make_pair(make_pair(dy, dx), 0), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) -> bool {
                auto ret = a.first.first * 1LL * b.first.second < b.first.first * 1LL * a.first.second;
                db(a, b, ret);
                return ret;
            });
            // auto it = lower_bound(res_dp[j].begin(), res_dp[j].end(), make_pair(make_pair(dy, dx), 0));
            if (it != res_dp[j].end())
            {
                db(*it, it - res_dp[j].begin());
                if (mp.find(it->second + 1) == mp.end())
                {
                    mp[it->second + 1] = make_pair(dy, dx);
                }
                else
                {
                    auto other = mp[it->second + 1];
                    if (other.first * 1LL * dx < dy * 1LL * other.second)
                        mp[it->second + 1] = make_pair(dy, dx);
                }
            }
        }
        res_dp[i].pb({{MOD, 1}, 1});
        for (auto &x : mp)
            res_dp[i].pb({x.second, x.first});
        sort(all(res_dp[i]), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) -> bool {
            return a.first.first * 1LL * b.first.second < b.first.first * 1LL * a.first.second;
        });
        db(i, res_dp[i]);
        for (int j = (int)res_dp[i].size() - 2; j >= 0; j--)
        {
            res_dp[i][j].second = max(res_dp[i][j].second, res_dp[i][j + 1].second);
        }
        res = max(res, res_dp[i][0].second);
        db(i, res_dp[i]);
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
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}