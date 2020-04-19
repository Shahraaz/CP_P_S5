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

const int NAX = 9999, MOD = 1000000007;

// double prob[NAX][NAX];
// int vis[NAX][NAX];
class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        srand(time(NULL));
        int t = 100;
        cout << t << '\n';
        while (t--)
        {
            vector<int> l{rand() % NAX, rand() % NAX, rand() % NAX};
            vector<int> r{rand() % NAX, rand() % NAX, rand() % NAX};
            sort(all(l));
            sort(all(r));
            cout << l[2] + 1 << ' ' << r[2] + 1 << ' ';
            cout << l[0] + 1 << ' ' << r[0] + 1 << ' ';
            cout << l[1] + 1 << ' ' << r[1] + 1 << ' ';
            cout << '\n';
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
        // cout << "Case #" << i << ": ";
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}