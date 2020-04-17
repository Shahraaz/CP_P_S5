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

const int _n = 1e5 + 10;
vector<int> Fact(_n), Inv(_n);
const int kmod = 1000000007;

int mul(int a, int b, int mod = kmod)
{
    return (long long)a * b % mod;
}

int add(int a, int b, int mod = kmod)
{
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b, int mod = kmod)
{
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int power(int base, int index, int mod = kmod)
{
    if (index == 0)
        return 1;
    int temp = power(base, index / 2, mod);
    temp = mul(temp, temp, mod);
    if (index & 1)
        temp = mul(temp, base, mod);
    return temp;
}

int mod_inv(int x, int mod = kmod)
{
    return power(x, kmod - 2);
}

void pre()
{
    Fact[0] = 1;
    for (int i = 1; i < _n; ++i)
        Fact[i] = mul(Fact[i - 1], i);
    Inv[_n - 1] = mod_inv(Fact[_n - 1]);
    for (int i = _n - 2; i >= 0; --i)
        Inv[i] = mul(Inv[i + 1], (1 + i));
}

int ncr(int n, int r)
{
    if (n < 0 || r < 0 || n - r < 0)
        return 0;
    return mul(Fact[n], mul(Inv[r], Inv[n - r]));
}

int vis[35][35];
class Solution
{
private:
public:
    Solution()
    {
        pre();
    }
    ~Solution()
    {
        pre();
    }
    void solveCase()
    {
        int sum = 0;
        cin >> sum;
#ifdef LOCAL
        if (sum < 32)
#else
        if (sum < 100)
#endif
        {
            // cout << sum << '\n';
            for (size_t i = 0; i < sum; i++)
                cout << i + 1 << ' ' << 1 << '\n';
            // cout << '\n';
            return;
        }
        int backSUm = sum;
        int duff = sum - 32;
        bool dir = false;
        vector<pair<int, int>> res;
        int pos = log2(duff);
        int rem = 32;
        for (size_t i = 0; i <= pos; i++)
        {
            if ((duff >> i) & 1)
            {
                if (dir)
                {
                    for (size_t j = 1; j <= (i + 1); j++)
                        res.pb({i + 1, j});
                }
                else
                {
                    for (size_t j = i + 1; j >= 1; j--)
                        res.pb({i + 1, j});
                }
                dir = !dir;
            }
            else
            {
                rem--;
                if (dir)
                    res.pb({i + 1, 1});
                else
                    res.pb({i + 1, i + 1});
            }
        }
        db(duff, res);
        for (size_t i = 0; i < rem; i++)
        {
            int b = res.back().f;
            if (dir)
                res.pb({b + 1, 1});
            else
                res.pb({b + 1, b + 1});
        }
        // cout << res.size() << '\n';
        int temp = 0;
        for (auto &x : res)
        {
            cout << x.f << ' ' << x.s << '\n';
            temp += ncr(x.f - 1, x.s - 1);
            db(x.f - 1, x.s - 1, ncr(x.f - 1, x.s - 1));
        }
        db(backSUm, temp);
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
        cout << "Case #" << i << ":  \n";
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
