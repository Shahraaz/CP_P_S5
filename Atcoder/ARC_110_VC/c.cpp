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

void no()
{
    cout << -1 << '\n';
    exit(0);
}

void solveCase()
{
    int n;
    cin >> n;
    vector<int> p(n + 1), vis(n + 1);
    vector<int> inv_p(n + 1);
    for (size_t i = 1; i <= n; i++)
    {
        cin >> p[i];
        inv_p[p[i]] = i;
    }
    vector<int> res;
    auto apply = [&](int idx) -> void {
        res.pb(idx);
        swap(p[idx], p[idx + 1]);
        inv_p[p[idx]] = idx;
        inv_p[p[idx + 1]] = idx + 1;
    };
    for (size_t i = 1; i < n; i++)
    {
        db(i, p);
        db(inv_p);
        db(vis);
        if (vis[i])
        {
            if (p[i] == i)
                continue;
            else
                no();
        }
        else
        {
            if (p[i] == i)
                no();
            int pos_i = inv_p[i];
            for (int j = pos_i - 1; j >= i; j--)
            {
                if (vis[j])
                    no();
                vis[j] = true;
                apply(j);
            }
            if (p[i] == i)
                continue;
            else
                no();
        }
    }
    for (auto &x : res)
    {
        cout << x << '\n';
    }
    // cout << '\n';
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