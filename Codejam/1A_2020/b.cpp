// Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define MULTI_TEST
#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#define pc(...)
#endif

#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()
auto TimeStart = chrono::steady_clock::now();
auto seed = TimeStart.time_since_epoch().count();
std::mt19937 rng(seed);
using ll = long long;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using Random = std::uniform_int_distribution<T>;

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

class Solution
{
private:
public:
    Solution()
    {
        pre();
    }
    ~Solution() {}
    void solveCase()
    {
        int sum = 0;
        cin >> sum;
        auto backSum = sum;
        db(sum);
        if (sum <= 100)
        {
            for (size_t i = 0; i < sum; i++)
            {
                cout << i + 1 << ' ' << 1 << '\n';
            }
            return;
        }
        vector<bool> isSet(32);
        int cntLift = 0;
        if (sum & 1)
        {
        }
        else
        {
            cntLift--;
        }
        sum--;
        for (int i = 0; i < 31; i++)
            if (sum & (1 << i))
                isSet[i + 1] = true;
        vector<pair<int, int>> res;
        isSet[1] = true;
        res.pb({1, 1});
        for (size_t i = 2; i < 32 && sum > 0; i++)
        {
            db(i, isSet[i]);
            if (isSet[i])
            {
                db(1 << i);
                sum -= 1 << (i);
                if (isSet[i - 1])
                {
                    if (res.back().s == 1)
                    {
                        for (size_t j = 1; j <= i; j++)
                            res.pb({i, j});
                    }
                    else
                    {
                        for (size_t j = i; j >= 1; j--)
                            res.pb({i, j});
                    }
                }
                else
                {
                    cntLift++;
                    if (res.back().s == 1)
                    {
                        // res.pb({i - 1, 1});
                        res.pb({i - 1, 2});
                        for (size_t j = 3; j <= i; j++)
                            res.pb({i, j});
                    }
                    else
                    {
                        // res.pb({i - 1, i});
                        res.pb({i - 1, i - 2});
                        for (size_t j = i - 2; j >= 1; j--)
                            res.pb({i, j});
                    }
                }
            }
            else
            {
                if (res.back().s == 1)
                    res.pb({i, 1});
                else
                    res.pb({i, i});
            }
            db(backSum - sum, backSum, sum);
            pc(res);
            db("----");
        }
        db(cntLift);
        if (cntLift < 0)
        {
            res.pop_back();
        }
        else
        {
            int x = res.back().f;
            int y = res.back().s;
            while (cntLift--)
            {
                ++x;
                if (y == 1)
                    res.pb({x, 1});
                else
                    res.pb({x, x});
            }
        }
        pc(isSet);
        sum = 0;
        // sort(all(res));
        // res.resize(unique(all(res)) - res.begin());
        for (auto &x : res)
        {
            cout << x.f << ' ' << x.s << '\n';
            sum += ncr(x.f - 1, x.s - 1);
        }
        db(sum, backSum);
        if (sum != backSum)
            exit(0);
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": \n";
        mySolver.solveCase();
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}