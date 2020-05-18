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
        int n, d;
        cin >> n >> d;
        db(n, d);
        map<ll, int> cnt;
        for (size_t i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            cnt[x]++;
        }
        db(n, d, cnt);
        if (d == 2)
        {
            for (auto &x : cnt)
            {
                if (x.s > 1)
                {
                    cout << 0 << '\n';
                    return;
                }
            }
            cout << 1 << '\n';
        }
        else
        {
            bool b = false;
            ll maxi = cnt.rbegin()->s;
            for (auto &x : cnt)
            {
                if (x.s > 2)
                {
                    cout << 0 << '\n';
                    return;
                }
                if (x.f != maxi)
                    b = b || x.s > 1;
            }
            if (!b)
            {
                for (auto &x : cnt)
                {
                    if (cnt[x.f * 2LL])
                    {
                        cout << 1 << '\n';
                        return;
                    }
                }
                cout << 2 << '\n';
            }
            else
            {
                cout << 1 << '\n';
            }
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
        cout << "Case #" << i << ": ";
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
