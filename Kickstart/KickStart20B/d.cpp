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

double fact[NAX];
double pow2[NAX];

class Solution
{
private:
    ll factorial(int n)
    {
        if (n <= 1)
            return 1;
        return n * factorial(n - 1);
    }
    double ncr(int n, int r)
    {
        return exp(fact[n] - fact[r] - fact[n - r] - pow2[n]);
    }

public:
    Solution()
    {
        for (size_t i = 1; i < NAX; i++)
        {
            fact[i] = fact[i - 1] + log(i);
            pow2[i] = pow2[i - 1] + log(2);
        }
    }
    ~Solution() {}
    void solveCase()
    {
        // db("\n");
        int w, h, l, u, r, d;
        cin >> w >> h >> l >> u >> r >> d;
        // db(w, h, l, u, r, d);
        // memset(vis, 0, sizeof vis);
        // memset(prob, 0, sizeof prob);
        // prob[1][1] = 1;
        auto check = [&](int x, int y) {
            return 1 <= x && x <= w && 1 <= y && y <= h;
        };
        map<pair<int, int>, double> dp;
        function<double(int, int)> prob = [&](int x, int y) -> double {
            if (!check(x + 1, y + 1))
                return 0;
            auto it = dp.find({x, y});
            if (it != dp.end())
                return it->s;
            auto &ret = dp[{x, y}];
            if (x == 0 || y == 0)
                return ret = ncr(x + y, y);
            if (x == (w - 1) || y == (h - 1))
            {
                if (x == w - 1)
                    ret += prob(x, y - 1);
                else
                    ret += prob(x, y - 1) / 2;
                if (y == h - 1)
                    ret += prob(x - 1, y);
                else
                    ret += prob(x - 1, y) / 2;
                return ret;
            }
            return ret = ncr(x + y, y);
        };
        cout << fixed << setprecision(9);
        double curr = 0;
        int xCord = r + 1, yCord = u - 1;
        while (yCord >= 1)
        {
            if (check(xCord, yCord))
                curr += prob(xCord - 1, yCord - 1);
            xCord++;
            yCord--;
        }
        xCord = l - 1, yCord = d + 1;
        while (xCord >= 1)
        {
            if (check(xCord, yCord))
                curr += prob(xCord - 1, yCord - 1);
            xCord--;
            yCord++;
        }
        cout << curr << '\n';
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
        cout << "Case #" << i << ": ";
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
