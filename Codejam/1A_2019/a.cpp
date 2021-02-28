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
const int NAX = 22, MOD = 1000000007;

int mask[1 << NAX][NAX];
int r, c;
int getIdx(int x, int y)
{
    return x * c + y;
}
pair<int, int> getX_Y(int idx)
{
    return make_pair(idx / c, idx % c);
}
bool check_compat(int idx1, int idx2)
{
    auto i = getX_Y(idx1);
    auto j = getX_Y(idx2);
    return !(i.first == j.first || i.second == j.second || (i.first - i.second) == (j.first - j.second) || (i.first + i.second) == (j.first + j.second));
}
vector<pair<int, int>> ret;
int solve(int s, int prev = 25)
{
    int cnt = __builtin_popcount(s);
    if (cnt == r * c)
    {
        // cout << "POSSIBLE\n";
        return true;
    }
    auto &ret = mask[s][prev];
    if (ret >= 0)
        return ret;
    ret = false;
    for (size_t i = 0; i < r * c; i++)
    {
        if (s & (1 << i))
            continue;
        if (prev == 25 || check_compat(prev, i))
            if (solve(s | (1 << i), i))
            {
                ::ret.pb(getX_Y(i));
                return ret = true;
            }
    }
    return ret;
}

void solveCase()
{
    // cin >> r >> c;
    for (size_t i = 2; i <= 5; i++)
    {
        // cout << '\n';
        for (size_t j = 2; j <= 5; j++)
        {
            memset(mask, -1, sizeof mask);
            r = i, c = j;
            ret.clear();
            db(r, c, solve(0));
            auto now = solve(0);
            // cout << solve(0) << ' ';
            // cout << flush;
            if (!now)
                cout << "IMPOSSIBLE\n";
            else
            {
                cout << "POSSIBLE\n";
                reverse(all(ret));
                for (auto &x : ret)
                    cout << x.first << ' ' << x.second << '\n';
            }
        }
    }
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
    {
        cout << "Case #" << i << ": ";
        solveCase();
    }
    return 0;
}