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
    map<int, int> dp;
    int question(int x)
    {
        if (dp.find(x) != dp.end())
            return dp[x];
        cout << 1 << ' ' << x << endl;
        int a;
        cin >> a;
        return dp[x] = a;
    }
    void answer(int x)
    {
        cout << 2 << ' ' << x << endl;
    }

public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        dp.clear();
        int n;
        cin >> n;
        int first = question(1);
        int low = 2, high = n - 1, freqA = 1;
        while (low <= high)
        {
            int mid = ((ll)low + high) / 2;
            int qfirst = question(mid);
            if (qfirst == first)
            {
                freqA = max(freqA, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        int last = question(n);
        int ans;
        if (question(n - freqA + 1) == last)
        {
            if (question(n - freqA) == last)
            {
                answer(first);
                return;
            }
            else
                ans = freqA;
        }
        else
        {
            answer(last);
            return;
        }
        int distinctNumbers = (n / ans) + 1;
        int oddCountguyCount = (n % ans);
        int k = ans;
        low = 2, high = distinctNumbers - 1, ans = high;
        db(distinctNumbers, oddCountguyCount);
        while (low <= high)
        {
            int mid = ((ll)low + high) / 2;
            db(low, high, mid);
            int qfirst = question(k * (mid - 1) + 1);
            int qlast = question(k * (mid));
            if (qlast == qfirst)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
                ans = min(ans, mid);
            }
        }
        answer(question(k * (ans - 1) + 1));
    }
};

int32_t main()
{
#ifndef LOCAL
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
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