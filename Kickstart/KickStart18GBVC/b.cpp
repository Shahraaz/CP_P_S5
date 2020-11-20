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
const int NAX = 2e5 + 5, MOD = 1e9 + 7;
int start[MOD];
int endd[MOD];
int f[MOD];

void solveCase()
{
    int n, q;
    cin >> n >> q;
    vector<ll> x(n + 5), y(n + 5), z(q + 5);
    vector<ll> a(4), b(4), c(4), m(4);
    cin >> x[1] >> x[2] >> a[1] >> b[1] >> c[1] >> m[1];
    cin >> y[1] >> y[2] >> a[2] >> b[2] >> c[2] >> m[2];
    cin >> z[1] >> z[2] >> a[3] >> b[3] >> c[3] >> m[3];
    vector<int> l(n + 1), r(n + 1), k(q + 1);

    for (size_t i = 3; i <= n; i++)
    {
        x[i] = (a[1] * x[i - 1] + b[1] * x[i - 2] + c[1]) % m[1];
        y[i] = (a[2] * y[i - 1] + b[2] * y[i - 2] + c[2]) % m[2];
    }
    for (size_t i = 3; i <= q; i++)
        z[i] = (a[3] * z[i - 1] + b[3] * z[i - 2] + c[3]) % m[3];

    for (size_t i = 1; i <= n; i++)
        l[i] = min(x[i], y[i]) + 1, r[i] = max(x[i], y[i]) + 1;

    for (size_t i = 1; i <= q; i++)
        k[i] = z[i] + 1;

    //solving start
    for (size_t i = 1; i <= n; i++)
    {
        endd[r[i]]++;
        start[l[i]]++;
    }
    int currCnt = 0;
    ll sum = 0;
    for (int i = MOD - 2; i >= 0; i--)
    {
        f[i] = f[i + 1];
        currCnt += endd[i];
        f[i] += currCnt;
        currCnt -= start[i];
        if (f[i])
        {
            db(i, f[i]);
        }
        start[i] = endd[i] = 0;
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
#ifdef TIMER
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}