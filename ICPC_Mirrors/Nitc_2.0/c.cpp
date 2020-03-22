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

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int n, exp;
        cin >> n >> exp;
        vector<int> p(n);
        bool found = 0;
        for (auto &x : p)
        {
            cin >> x;
            // x /= exp;
            if (x == exp)
                found = true;
        }
        cout << fixed << setprecision(10);
        if (found)
        {
            for (auto &x : p)
            {
                if (!found)
                    cout << 0.0 << ' ';
                else if (x == exp)
                {
                    cout << 1.0 << ' ';
                    found = 0;
                }
                else
                    cout << 0.0 << ' ';
            }
            cout << '\n';
            return;
        }
        if (*max_element(all(p)) < exp || *min_element(all(p)) > exp)
            cout << -1 << '\n';
        else
        {
            int idx1 = min_element(all(p)) - p.begin();
            int idx2 = max_element(all(p)) - p.begin();
            long double p2 = exp - p[idx1];
            p2 /= p[idx2] - p[idx1];
            long double p1 = 1 - p2;
            assert(0 <= p1 && p1 <= 1);
            assert(0 <= p2 && p2 <= 1);
            for (size_t i = 0; i < n; i++)
            {
                if (idx1 == i)
                {
                    cout << p1 << ' ';
                }
                else if (idx2 == i)
                {
                    cout << p2 << ' ';
                }
                else
                    cout << 0.0 << ' ';
            }
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