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

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        ll n, D;
        cin >> n >> D;
        vector<ll> v(n);
        for (auto &x : v)
            cin >> x;
        auto check = [&](ll startDate) {
            ll endDate = startDate;
            for (auto &x : v)
                endDate = ceil(1.0 * endDate / x) * x;
            return endDate;
        };
        ll low = 0, high = D, ans = 0;
        db(v);
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            db(mid, check(mid));
            if (check(mid) <= D)
            {
                low = mid + 1;
                ans = max(ans, mid);
            }
            else
                high = mid - 1;
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
