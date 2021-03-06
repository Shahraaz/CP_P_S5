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
        int n;
        cin >> n;
        vector<int> a(n);
        ll sum = 0;
        multiset<ll> s;
        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
            sum += a[i];
        }
        vector<int> ret;
        for (size_t i = 0; i < n; i++)
        {
            auto currSum = sum - a[i];
            s.erase(s.find(a[i]));
            if (currSum % 2 == 0 && s.count(currSum / 2))
                ret.pb(i + 1);
            s.insert(a[i]);
        }
        cout << ret.size() << '\n';
        for (auto &x : ret)
        {
            cout << x << ' ';
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
