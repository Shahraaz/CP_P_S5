#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

#define all(v) v.begin(), v.end()
#define pb push_back
using ll = long long;
const int NAX = 2e5 + 5, MOD = 1000000007;

void solveCase()
{
    int n;
    cin >> n;
    vector<pair<int, int>> O, E;
    if (n == 1)
    {
        cout << "! 1" << endl;
        return;
    }
    int evencnt = n / 2;
    int oddcnt = n - evencnt;
    vector<int> oidx(oddcnt + 1), eidx(evencnt + 1);
    O.insert({1, n - !(n & 1)});
    set<int> eidxes;
    for (size_t i = 2; i <= n; i += 2)
        eidxes.insert(i / 2);
    while (O.size() != oddcnt)
    {
        auto eidx = 
    }
}

int32_t main()
{
#ifndef LOCAL
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}