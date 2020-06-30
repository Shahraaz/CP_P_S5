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
        int n, m, k;
        cin >> n >> m >> k;
        vector<ll> a(n), b(m);
        for (size_t i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (i > 0)
                a[i] = a[i - 1];
            a[i] += x;
        }
        for (size_t i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            if (i > 0)
                b[i] = b[i - 1];
            b[i] += x;
        }
        ll ret = 0;
        for (ll i = 0; i < n; ++i)
        {
            if (k < a[i])
                break;
            ll extra = k - a[i];
            ll it = upper_bound(all(b), extra) - b.begin();
            ret = max(ret, it + i + 1);
        }
        a.swap(b);
        swap(n, m);
        for (ll i = 0; i < n; ++i)
        {
            if (k < a[i])
                break;
            ll extra = k - a[i];
            ll it = upper_bound(all(b), extra) - b.begin();
            ret = max(ret, it + i + 1);
        }
        cout << ret << '\n';
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
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
