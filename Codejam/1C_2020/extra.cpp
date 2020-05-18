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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        const int U = 16;
        cout << 1 << '\n';
        cout << U << '\n';
        int ctr = 1e4;
        ll limit = pow(10, U) - 1;
        for (size_t i = 0; i < ctr; i++)
        {
            ll a = uniform_int_distribution<ll>(1LL, limit)(rng);
            ll b = uniform_int_distribution<ll>(1LL, a)(rng);
            cout << a << ' ';
            cout << b << '\n';
        }
    }
};

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
