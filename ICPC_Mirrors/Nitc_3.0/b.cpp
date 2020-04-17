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
        int minX, maxX, n;
        cin >> n >> minX >> maxX;
        vector<pair<int, int>> ww(n);
        for (auto &x : ww)
            cin >> x.f >> x.s;
        int constant = 0, coef = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            constant = (constant + coef * ww[i].s) % 2;
            coef = (coef * ww[i].f) % 2;
        }
        db(coef, constant);
        bool forOdd = (coef + constant) % 2;
        bool forEven = constant;
        int evenCnt = 0;
        int oddCnt = 0;
        evenCnt = maxX / 2 - (minX - 1) / 2;
        oddCnt = maxX - minX + 1 - evenCnt;
        db(evenCnt, oddCnt);
        ll arr[] = {0, 0};
        arr[forEven] += evenCnt;
        arr[forOdd] += oddCnt;
        cout << arr[0] << ' ' << arr[1] << '\n';
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
