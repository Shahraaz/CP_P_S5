// Optimise
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#define pc(...)
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
    vector<int> getSmallerLeft(vector<int> H)
    {
        stack<int> s;
        vector<int> ret(H.size());
        for (int i = 0; i < H.size(); i++)
        {
            while (s.size() && H[s.top()] >= H[i])
                s.pop();
            if (s.size())
                ret[i] = s.top();
            else
                ret[i] = i;
            s.push(i);
        }
        return ret;
    }

    vector<int> getSmallerRight(vector<int> H)
    {
        reverse(H.begin(), H.end());
        auto ret = getSmallerLeft(H);
        for (size_t i = 0; i < H.size(); ++i)
            ret[i] = H.size() - 1 - ret[i];
        reverse(ret.begin(), ret.end());
        return ret;
    }

public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int n;
        cin >> n;
        vector<int> v(n + 2);
        for (size_t i = 1; i <= n; i++)
        {
            cin >> v[i];
            // v[i - 1] = i;
        }
        v[0] = v[n + 1] = -1;
        auto left = getSmallerLeft(v);
        auto right = getSmallerRight(v);
        pc(v);
        pc(left, right);
        ll res = 0;
        for (ll i = 1; i <= n; i++)
        {
            db(i - left[i], right[i] - i);
            res += v[i] * max(1LL, i - left[i]) * max(1LL, right[i] - i);
        }
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