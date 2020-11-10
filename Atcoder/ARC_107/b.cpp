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

const int NAX = 2e5 + 5, MOD = 1000000007;

void solveCase()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> cnt(2 * n + 10);
    for (size_t i = 1; i <= n; i++)
    {
        cnt[i + 1]++;
        cnt[i + n + 1]--;
    }
    ll res = 0;
    for (int i = 2; i <= 2 * n; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 2; i <= 2 * n; i++)
    {
        db(i, cnt[i]);
        if (0 <= k + i && k + i <= 2 * n)
            res += cnt[i] * cnt[k + i];
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
