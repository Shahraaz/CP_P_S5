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

using ld = double;

ld FACT[NAX];
ld LOG_2[NAX];

struct Solution
{
    double ways(double c, double d)
    {
        if (c == 0)
            return d;
        if (d == 0)
            return 0;
        auto ret = (c * (1 + ways(c - 1, d)) + d * (1 + ways(c, d - 1))) / (c + d);
        db(c, d, ret);
        return ret;
    }

    Solution()
    {
        for (size_t i = 1; i < NAX; i++)
        {
            LOG_2[i] = log2(i);
            FACT[i] = FACT[i - 1] + LOG_2[i];
        }
    }
    void solveCase()
    {
        int DCnt, CCnt;
        cin >> CCnt >> DCnt;
        cout << ways(CCnt, DCnt) << '\n';
        return;
        ll res = 0;

        auto ncr = [&](int n, int r) {
            return FACT[n] - FACT[(r)] - FACT[n - r];
        };

        ld num = 0, den = ncr(DCnt + CCnt, CCnt);
        for (size_t i = DCnt; i <= DCnt + CCnt; i++)
        {
            /*
                LCnt = i - DCnt;
                d d d d
                DCnt gaps
                x1 + x2 + ... xDCnt = LCnt
                (LCnt + Dnct - 1) C (DCnt - 1)
            */
            auto curr = ncr(i - 1, DCnt - 1);
            num += pow(2, curr + LOG_2[i] - den);
            db(i, curr, pow(2, curr));
            db(pow(2, curr + LOG_2[i] - den));
        }
        // db(ways(CCnt, DCnt));
        // db(num, den, num * 1.0 / den);
        cout << fixed << setprecision(10);
        cout << num << '\n';
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
