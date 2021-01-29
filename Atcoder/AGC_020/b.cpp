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
    int k;
    cin >> k;
    vector<ll> vecc(k);
    for (auto &x : vecc)
        cin >> x;
    if (k == 1)
    {
        if (vecc[0] == 2)
        {
            cout << 2 << ' ' << 3 << '\n';
            return;
        }
        cout << -1 << '\n';
        return;
    }
    ll mini = 2, maxi = 2;
    ll mini_prev = mini, maxi_prev = maxi;
    for (int i = k - 1; i >= 0; i--)
    {
        mini_prev = ((mini + vecc[i] - 1) / vecc[i]) * vecc[i];
        maxi_prev = ((maxi) / vecc[i]) * vecc[i] + vecc[i] - 1;

        db(mini, maxi, vecc[i], mini_prev, maxi_prev);

        if (mini_prev > maxi_prev)
        {
            cout << -1 << '\n';
            return;
        }

        mini = mini_prev;
        maxi = maxi_prev;
    }
    cout << mini << ' ' << maxi << '\n';
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