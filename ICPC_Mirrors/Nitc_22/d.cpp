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

void read_time(int &h, int &m)
{
    string s;
    cin >> s;
    s[2] = ' ';
    stringstream ss(s);
    ss >> h >> m;
}

pair<int, int> standardize(pair<int, int> a)
{
    int g = __gcd(a.first, a.second);
    return {a.first / g, a.second / g};
}

vector<vector<pair<int, pair<int, int>>>> ans(181);

void init(int alpha)
{
    int cur = alpha;
    if (cur < 0)
        cur += 360;
    if (cur > 180)
        cur -= 180;
    for (int h = 0; h < 12; h++)
    {
        // 30h - 5.5m = alpha
        // 60h - 11m = 2*alpha
        // 11m = 60h - 2*alpha
        pair<int, int> m = standardize({60 * h - alpha * 2, 11});
        if (m.first >= 0 && m.first < 60 * m.second)
        {
            ans[cur].pb({h, m});
            ans[cur].pb({h + 12, m});
        }
        if (alpha == 0)
            continue;
        // 30h - 5.5m =- alpha
        // 60h - 11m = -2*alpha
        // 11m = 60h + 2*alpha
        m = standardize({60 * h + alpha * 2, 11});
        if (m.first >= 0 && m.first < 60 * m.second)
        {
            ans[cur].pb({h, m});
            ans[cur].pb({h + 12, m});
        }
    }
    sort(all(ans[cur]));
    db(cur, ans[cur]);
}

void solveCase()
{
    int h1, m1;
    read_time(h1, m1);

    int h2, m2;
    read_time(h2, m2);

    int alpha;
    cin >> alpha;

    int res = 0;

    for (auto T : ans[alpha])
    {
        if (T.first < h2 || (T.first == h2 && T.second.first <= m2 * T.second.second))
            ++res;
        if (T.first < h1 || (T.first == h1 && T.second.first < m1 * T.second.second))
            --res;
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
    init(0);
    init(90);
    init(180);
    init(270);
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}