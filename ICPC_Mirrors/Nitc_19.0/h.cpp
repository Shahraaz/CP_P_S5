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

const int NAX = 2e5 + 5;

int power(int base, int index, int MOD)
{
    int ret = 1;
    while (index)
    {
        if (index & 1)
            ret = (ret * 1LL * base) % MOD;
        base = (base * 1LL * base) % MOD;
        index /= 2;
    }
    return ret;
}

int inverse(int x, int MOD)
{
    return power(x, MOD - 2, MOD);
}

void solveCase()
{
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    vector<int> params[n];
    for (size_t i = 0; i < n; i++)
    {
        params[i].pb(i + 1);
        params[i].pb(i + 2);
    }
    for (auto &x : a)
        cin >> x;
    vector<map<int, int>> dp(n);
    map<int, deque<int>> idexes;
    map<int, vector<int>> additionalChecks;
    for (int i = n - 1; i >= 0; i--)
    {
        int currinv = inverse(a[i], p);
        for (auto &x : additionalChecks[a[i]])
            params[i].pb(x);
        sort(all(params[i]));
        db(params[i]);
        for (auto j : params[i])
        {
            if (j < n)
            {
                int q = (currinv * 1LL * a[j]) % p;
                additionalChecks[(a[i] * 1LL * inverse(q, p)) % p].pb(i);
                dp[i][q] = 2;
                int next = (a[j] * 1LL * q) % p;
                if (idexes[next].size())
                {
                    int ctr = 0;
                    if (idexes[next][0] == j)
                        ctr = 1;
                    if (idexes[next].size() > ctr)
                    {
                        if (dp[idexes[next][ctr]][q] == 0)
                            dp[idexes[next][ctr]][q] = 1;
                        dp[i][q] = 2 + dp[idexes[next][ctr]][q];
                    }
                }
            }
        }
        db(i, a[i], dp[i]);
        idexes[a[i]].push_front(i);
        if (idexes[a[i]].size() > 2)
            idexes[a[i]].pop_back();
    }
    int res = 1;
    for (auto &x : dp)
        for (auto &y : x)
            res = max(res, y.s);
    if (res * 2 < n)
        res = -1;
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
    {
        solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
