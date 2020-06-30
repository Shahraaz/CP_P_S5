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

const int NAX = 2e5 + 5, MOD = 998244353;

class Solution
{
private:
    int power(int base, int idx)
    {
        if (idx == 0)
            return 1;
        ll temp = power(base, idx / 2);
        temp = (temp * temp) % MOD;
        if (idx & 1)
            temp = (temp * base) % MOD;
        return temp;
    }

public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        const int LIM = 3001;
        vector<int> ways(LIM);
        ways[0] = 1;
        for (size_t j = 0; j < n; j++)
        {
            vector<int> newWays(LIM);
            for (size_t i = 0; i < LIM; i++)
                newWays[i] = (ways[i] * 2LL) % MOD;
            for (size_t i = a[j]; i < LIM; i++)
                newWays[i] = (newWays[i] + ways[i - a[j]]) % MOD;
            ways.swap(newWays);
        }
        cout << ways[s] << '\n';
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
