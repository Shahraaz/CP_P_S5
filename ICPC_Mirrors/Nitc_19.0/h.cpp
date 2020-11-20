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

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solveCase()
{
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    auto solve = [&](int q) -> int {
        unordered_map<int, int, custom_hash> dp;
        int ret = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int next = (a[i] * 1LL * q) % p;
            // db(i, a[i], next);
            dp[a[i]] = max(dp[a[i]], dp[next] + 1);
            ret = max(ret, dp[a[i]]);
        }
        // db(q, ret, dp);
        return ret;
    };
    unordered_map<int, int, custom_hash> potential_q;
    for (int i = n - 1; i >= 0; i--)
    {
        int currinv = inverse(a[i], p);
        for (auto j : {i + 1, i + 2})
            if (j < n)
            {
                int q = (currinv * 1LL * a[j]) % p;
                potential_q[q]++;
            }
    }
    int res = 1;
    vector<pair<int, int>> invq;
    for (auto &x : potential_q)
        invq.push_back({x.s, x.f});
    sort(all(invq));
    reverse(all(invq));
    db(invq);
    int lim = min(10, (int)invq.size());
    for (size_t i = 0; i < lim; i++)
        res = max(res, solve(invq[i].s));
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
