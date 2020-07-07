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

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        // for (size_t a = 1; a <= 50; a++)
        // {
        //     for (size_t n = 1; n <= 50; n++)
        //     {
        bool ok = false;
        int num = 0, num2 = 0;
        ll a, n;
        cin >> a >> n;
        for (size_t b = 0; b < 1000000; b++)
        {
            if ((b * n + 1) % a == 0)
            {
                ok = true;
                num2 = b;
                num = (b * n + 1) / a;
                break;
            }
        }
        if (ok)
        {
            cout << num << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
        // else if (__gcd(a, n) == 1)
        // {
        //     cout << a << ' ' << n << '\n';
        //     exit(0);
        // }
        //     }
        // }
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    cin >> t;
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
