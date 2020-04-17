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
        int n, m;
        cin >> n >> m;
        ll ggcd = 1;
        vector<ll> vv;
        db(n, m);
        for (size_t i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            vv.pb(x);
            ggcd = ggcd / __gcd(ggcd, x) * x;
            db(x, ggcd);
            if (ggcd > 2 * m)
            {
                db("abcd");
                cout << 0 << '\n';
                return;
            }
        }
        sort(all(vv));
        vv.resize(unique(all(vv)) - vv.begin());
        ll xy = 1LL << 32;
        ll a = -1;
        for (auto &x : vv)
        {
            ll g = __gcd(xy, x);
            if (a == -1)
                a = g;
            else if (a != g)
            {
                db(g, x, xy);
                cout << 0 << '\n';
                return;
            }
        }
        db(vv);
        ggcd /= 2;
        ll res = m / ggcd;
        res--;
        res /= 2;
        db(bitset<30>(res), bitset<30>(ggcd), bitset<30>(m));
        db(res, ggcd, m);
        while ((2 * res + 1) * ggcd <= m)
            res++;
        cout << res << '\n';
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
