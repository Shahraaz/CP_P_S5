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
        int x, y;
        string m;
        cin >> x >> y >> m;
        map<pair<int, int>, vector<int>> distMatrix;
        set<pair<int, int>> vis;
        distMatrix[{x, y}].pb(0);
        int ctr = 0;
        for (auto &c : m)
        {
            switch (c)
            {
            case 'S':
                --y;
                break;
            case 'N':
                ++y;
                break;
            case 'E':
                ++x;
                break;
            case 'W':
                --x;
                break;
            default:
                break;
            }
            distMatrix[{x, y}].pb(++ctr);
        }
        db(distMatrix);
        int res = INT_MAX;
        for (auto &d : distMatrix)
        {
            int temp = abs(d.f.f) + abs(d.f.s);
            for (auto &x : d.second)
                if (temp <= x)
                {
                    res = min(res, x);
                }
        }
        if (res == INT_MAX)
            cout << "IMPOSSIBLE\n";
        else
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
