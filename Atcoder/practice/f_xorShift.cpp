// Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define MULTI_TEST
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

vector<int> Z_function(string S)
{
    int n = S.size();
    vector<int> z(n);
    int l = -1, r = -1;
    for (int i = 1; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && S[z[i]] == S[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i];
    }
    return z;
}

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;
        vector<int> ans(n);
        for (size_t k = 0; k < 30; k++)
        {
            string s(3 * n, '*');
            string t(3 * n, '*');
            for (size_t i = 0; i < n; i++)
            {
                s[i] = (b[i] >> k & 1) + '0';
                t[i] = (~b[i] >> k & 1) + '0';
                t[i + n] = t[i + 2 * n] = s[i + n] = s[i + 2 * n] = (a[i] >> k & 1) + '0';
            }
            auto z0 = Z_function(s);
            auto z1 = Z_function(t);
            for (size_t i = 0; i < n; i++)
            {
                if (ans[i] == -1)
                    continue;
                if (z0[i + n] >= n)
                    continue;
                else if (z1[i + n] >= n)
                    ans[i] ^= 1 << k;
                else
                    ans[i] = -1;
            }
        }
        for (size_t i = 0; i < n; i++)
            if (ans[i] != -1)
                cout << i << ' ' << ans[i] << '\n';
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
        mySolver.solveCase();
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}