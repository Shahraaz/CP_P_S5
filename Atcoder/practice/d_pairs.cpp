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
    ll zeroCnt;
    int n;
    ll k;
    vector<ll> pos, neg;

    ll cntLessNumbersPos(vector<ll> &a, ll val)
    {
        ll cnt = 0;
        int i = 0, j = a.size() - 1;
        while (i < j)
        {
            while (j > i && a[j] * a[i] > val)
                --j;
            cnt += j - i;
            ++i;
        }
        // db("cntLesPos");
        // db(cnt, val);
        // pc(a);
        return cnt;
    }

    ll cntLessNumbersNeg(ll val)
    {
        ll cnt = pos.size() * neg.size();
        int j = neg.size() - 1;
        val--;
        for (auto &x : pos)
        {
            while (j >= 0 && neg[j] * x > val)
                --j;
            // db(x, j);
            cnt -= j + 1;
        }
        // db("cntLesNeg");
        // db(cnt, val);
        return cnt;
    }

    ll cntLessNumbers(ll val)
    {
        if (val > 0)
            return cntLessNumbersPos(pos, val) + cntLessNumbersPos(neg, val) + pos.size() * neg.size() + (n - zeroCnt) * zeroCnt + zeroCnt * (zeroCnt - 1) / 2;
        else if (val == 0)
            return pos.size() * neg.size() + (n - zeroCnt) * zeroCnt + zeroCnt * (zeroCnt - 1) / 2;
        return cntLessNumbersNeg(-val);
    }

public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        cin >> n;
        cin >> k;
        zeroCnt = 0;
        for (size_t i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x < 0)
                neg.pb(-x);
            else if (x > 0)
                pos.pb(x);
            else
                zeroCnt++;
        }
        sort(all(pos));
        sort(all(neg));
        pc(pos, neg);
        ll low = -1e18, high = 1e18, ans = 1e18;
#ifdef LOCAL
        // for (int i = -20; i <= 20; i++)
        // {
        //     db(cntLessNumbers(i), i);
        // }
        // return;
#else

#endif
        while (low <= high)
        {
            ll mid = ll((__int128_t(low) + __int128_t(high)) / 2);
            // db(low, mid, high);
            db(cntLessNumbers(mid), mid, low, high);
            if (cntLessNumbers(mid) >= k)
            {
                ans = min(ans, mid);
                // ans = max(mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
            db(ans);
        }
        cout << ans << '\n';
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