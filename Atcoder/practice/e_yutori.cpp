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

int storeL[NAX], storeR[NAX];
int idxL[NAX], idxR[NAX];

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int n, k, c;
        cin >> n >> k >> c;
        string a;
        cin >> a;
        a = '$' + a;
        int prev = -1e9, val = 0;
        for (size_t i = 1; i <= n; i++)
        {
            idxL[i] = prev;
            if (a[i] == 'x')
                storeL[i] = val;
            else
            {
                if (i - prev > c)
                {
                    val++;
                    prev = i;
                    storeL[i] = val;
                }
            }
        }
        prev = 1e9, val = 0;
        for (size_t i = n; i >= 1; i--)
        {
            idxR[i] = prev;
            if (a[i] == 'x')
                storeR[i] = val;
            else
            {
                if (prev - i > c)
                {
                    val++;
                    prev = i;
                    storeR[i] = val;
                }
            }
        }
        vector<int> ans;
        for (size_t i = 1; i <= n; i++)
        {
            int l = idxL[i];
            int r = idxR[i];
            // cout << i << ' ' << l << ' ' << r << ' ' << storeL[i] << ' ' << storeR[i] << '\n';
            if (l == -1e9 && r == 1e9)
                ans.pb(i);
            else if (l == -1e9)
            {
                if (storeR[r] < k)
                    ans.pb(i);
            }
            else if (r == 1e9)
            {
                if (storeL[l] < k)
                    ans.pb(i);
            }
            else
            {
                if (abs(r - l) > c)
                {
                    if (storeL[l] + storeR[r] < k)
                        ans.pb(i);
                }
                else
                {
                    if (storeL[l] + storeR[r] - 1 < k)
                        ans.pb(i);
                }
            }
        }
        for (auto &x : ans)
            cout << x << '\n';
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