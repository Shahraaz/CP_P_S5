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

const int NAX = 1e6 + 5, MOD = 1000000007;

struct Solution
{
    Solution() {}
    void solveCase();
};

int cnt[NAX];
bool isPrime[NAX];
vector<int> divisors[NAX];

void Solution::solveCase()
{
    for (size_t i = 2; i < NAX; i++)
        isPrime[i] = true;
    for (size_t i = 2; i < NAX; i++)
    {
        if (isPrime[i])
            for (size_t j = i; j < NAX; j += i)
            {
                if (j != i)
                    isPrime[j] = false;
                divisors[j].pb(i);
            }
    }
    int n;
    cin >> n;
    vector<int> a(n);
    ll curr_gcd = -1;
    bool ok = true;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        for (auto &x : divisors[a[i]])
        {
            if (cnt[x])
                ok = false;
            cnt[x]++;
        }
        if (curr_gcd == -1)
            curr_gcd = a[i];
        else
            curr_gcd = __gcd(curr_gcd, (ll)a[i]);
    }
    db(ok);
    if (ok)
        cout << "pairwise coprime";
    else if (curr_gcd == 1)
        cout
            << "setwise coprime";
    else
        cout << "not coprime";
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
