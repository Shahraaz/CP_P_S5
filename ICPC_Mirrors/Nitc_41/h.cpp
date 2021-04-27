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
    vector<int> cap(n);
    vector<int> toll(n - 1);
    vector<int> pol(n - 1);
    for (auto &x : cap)
        cin >> x;
    for (auto &x : toll)
        cin >> x;
    for (auto &x : pol)
        cin >> x;
    long long res = 0, curr_cost = 0;
    for (size_t i = 0; i < n; i++)
    {
        curr_cost += cap[i];
        res = max(res, curr_cost);
        if (i + 1 < n)
            curr_cost -= pol[i] * toll[i];
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