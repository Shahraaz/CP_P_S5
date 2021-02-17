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

void NO()
{
    cout << "-1\n";
    exit(0);
}

void solveCase()
{
    int n, m;
    cin >> n >> m;
    if (m < 0 || m == n || (n >= 2 && m == (n - 1)))
        NO();
    if (m == 0)
    {
        for (size_t i = 0; i < n; i++)
            cout << 2 * i + 1 << ' ' << 2 * i + 2 << '\n';
        return;
    }
    int r = 1;
    for (size_t i = 1; i <= (m + 1); i++)
    {
        cout << 2 * i << ' ' << 2 * i + 1 << '\n';
        r = 2 * i + 2;
    }
    cout << 1 << ' ' << r << '\n';
    ++r;
    for (size_t i = m + 2; i < n; i++)
    {
        cout << r << ' ';
        ++r;
        cout << r << '\n';
        ++r;
    }
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