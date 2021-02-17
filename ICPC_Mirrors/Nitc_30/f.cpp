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
    map<int, int> cnt;
    ll left = 0, right = 0;
    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        right += x;
        cnt[x]++;
        cnt[x - 1];
        cnt[x + 1];
    }
    for (auto &x : cnt)
    {
        right -= x.first * 1LL * x.second;
        if (left == right)
        {
            cout << x.first << '\n';
            return;
        }
        left += x.first * 1LL * x.second;
    }
    assert(false);
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