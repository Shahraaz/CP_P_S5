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

class Solution
{
private:
    int k, q;
    vector<int> d, dd;

public:
    Solution()
    {
        cin >> k >> q;
        d.resize(k);
        dd.resize(k);
        for (auto &x : d)
            cin >> x;
    }
    ~Solution() {}
    void solveCase()
    {
        while (q--)
        {
            int n, x, m;
            cin >> n >> x >> m;
            --n;
            ll s, z;
            s = z = 0;
            for (int i = 0; i < k; ++i)
            {
                dd[i] = d[i] % m;
                s += dd[i];
                if (dd[i] == 0)
                    ++z;
            }
            ll y = x % m + n / k * s;
            int l = n % k;
            z *= n / k;
            for (int i = 0; i < l; ++i)
            {
                y += dd[i];
                if (dd[i] == 0)
                    ++z;
            }
            cout << (n - z - y / m) << '\n';
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