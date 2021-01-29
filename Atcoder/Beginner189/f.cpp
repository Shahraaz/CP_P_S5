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
    // pre();
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> feck(n + 1);
    using ld = long double;
    vector<ld> computed(n + m + 2);
    vector<ld> myXCnt(n + m + 2);
    for (size_t i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        feck[x] = 1;
        computed[x] = 0;
        myXCnt[x] = 1;
    }
    ld comp = 0, xcnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int torem = i + m + 1;
        {
            comp -= computed[torem];
            xcnt -= myXCnt[torem];
        }
        int toadd = i + 1;
        {
            comp += computed[toadd];
            xcnt += myXCnt[toadd];
        }
        db(i, comp, xcnt);
        if (!feck[i])
        {
            myXCnt[i] = xcnt / m;
            computed[i] = 1 + comp / m;
        }
        db(i, myXCnt[i], computed[i]);
    }
    ld a = computed[0];
    ld frac = 1 - myXCnt[0];
    db(a, frac);
    cout << fixed << setprecision(10);
    if (frac >= 1e-12)
    {
        ld x = a / (frac);
        cout << x << '\n';
    }
    else
    {
        cout << -1 << '\n';
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