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

struct Solution
{
    Solution() {}
    void solveCase()
    {
        int n, k;
        cin >> n >> k;
        map<int, int> cnt;
        for (size_t i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            cnt[x]++;
        }
        priority_queue<pair<int, int>> Q;
        for (auto &x : cnt)
            Q.push({x.s, x.f});
        k = min(k, n);
        while (k-- && Q.size())
        {
            auto top = Q.top();
            Q.pop();
            if (top.f == 1)
                break;
            top.f--;
            Q.push(top);
        }
        ll res = n * (n - 1LL);
        while (Q.size())
        {
            auto top = Q.top();
            Q.pop();
            res -= top.f * (top.f - 1LL);
        }
        cout << res/2 << '\n';
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
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
