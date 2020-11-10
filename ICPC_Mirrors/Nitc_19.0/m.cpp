// Optimise
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()

const int NAX = 1e5 + 5, MOD = 1000000007;
ll a[NAX];
ll b[NAX];
int vis[NAX];

void solveCase()
{
    int n;
    cin >> n;
    for (size_t i = 1; i <= n; i++)
        cin >> a[i];
    for (size_t i = 1; i <= n; i++)
        cin >> b[i];
    ll res = a[1];
    for (size_t i = 2; i <= n; i++)
    {
        if (vis[i])
            continue;
        ll j = i;
        vector<ll> vecc;
        while (j <= n)
        {
            vecc.pb(j);
            vis[j] = 1;
            j *= i;
        }
        ll tempRes = 0;
        for (int mask = (1 << vecc.size()) - 1; mask >= 1; mask--)
        {
            ll temp = 0;
            for (size_t i = 0; i < vecc.size(); i++)
                if (mask & (1 << i))
                {
                    temp += a[vecc[i]];
                    int x = vecc[i];
                    for (size_t j = i + 1; j < vecc.size(); j++)
                        if (mask & (1 << j))
                        {
                            int y = vecc[j];
                            if (x != 1)
                                while (y > 1 && y % x == 0)
                                    y /= x;
                            db(i, j, x, vecc[j], y);
                            if (y == 1)
                                temp -= b[vecc[j]];
                        }
                }
            db(mask, temp);
            tempRes = max(temp, tempRes);
        }
        db(i, vecc, tempRes);
        res += tempRes;
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
    {
        solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
