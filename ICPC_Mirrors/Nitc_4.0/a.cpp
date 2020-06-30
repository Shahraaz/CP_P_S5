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

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binaryPower(u64 base, u64 e, u64 mod)
{
    u64 result = 1;
    base %= mod;
    while (e)
    {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool checkComposite(u64 n, u64 a, u64 d, int s)
{
    u64 x = binaryPower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    auto xCopy = x;
    for (int r = 1; r < s; ++r)
    {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool MillerRabin(u64 n)
{
    const int iter = 16;
    if (n < 4)
        return n == 2 || n == 3;
    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        s++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a)
            return true;
        if (checkComposite(n, a, d, s))
            return false;
    }
    return true;
}

set<ll> supporters;
class Solution
{
private:
public:
    Solution()
    {
        set<int> nice = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
        for (size_t j = 2; j <= 1e6; j++)
        {
            if (!MillerRabin(j))
                continue;
            ll curr = 1;
            for (size_t i = 0; i < 50; i++)
            {
                if (curr > 1e12)
                    break;
                if (nice.count(i + 1))
                    supporters.insert(curr);
                curr *= j;
            }
        }
        int cnt = 20;
        auto it = supporters.begin();
        db(supporters.size());
        while (cnt--)
        {
            db(*it);
            ++it;
        }
    }
    ~Solution() {}
    void solveCase()
    {
        int n;
        cin >> n;
        vector<ll> p(n);
        vector<int> pbs;
        for (size_t i = 0; i < n; i++)
        {
            cin >> p[i];
            if (supporters.count(p[i]))
                pbs.pb(i);
        }
        auto p2 = p;
        sort(all(p2));
        db(pbs);
        if (pbs.size() == 0)
            cout << "No supporter found.\n";
        else
        {
            vector<int> temp;
            for (auto &x : pbs)
            {
                auto rank = lower_bound(all(p2), p[x]) - p2.begin();
                // cout << n - rank << ' ';
                temp.pb(n - rank);
            }
            sort(all(temp));
            // for
            cout << '\n';
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
