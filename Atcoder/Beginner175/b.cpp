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
    void solveCase();
};

void Solution::solveCase()
{
    int n;
    cin >> n;
    vector<int> v;
    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.pb(x);
    }
    int res = 0;
    for (size_t i = 0; i < n; i++)
    {
        int x = v[i];
        for (size_t j = 0; j < i; j++)
        {
            if (x == v[j])
                continue;
            for (size_t z = 0; z < j; z++)
            {
                if (x == v[z])
                    continue;
                if (v[j] == v[z])
                    continue;
                if (v[j] + v[z] > x)
                    if (x + v[z] > v[j])
                        if (v[j] + x > v[z])
                            res++;
            }
        }
    }
    cout << res << '\n';
}

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
