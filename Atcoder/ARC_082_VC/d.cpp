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
    vector<int> a(n);
    for (size_t i = 0; i < n; i++)
        cin >> a[i];
    int res = 0;
    for (size_t i = 0; i < n; i++)
    {
        --a[i];
        if (a[i] == i)
        {
            ++res;
            if ((i + 1) < n)
                swap(a[i], a[i + 1]);
            // if ((i + 1) < n)
            else
                swap(a[i], a[i - 1]);
        }
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
    // cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}