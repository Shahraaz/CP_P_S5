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
    string a, b;
    cin >> a >> b;
    vector<int> hasha(26);
    vector<int> hashb(26);
    ll res = 0;
    set<string> allstr;
    for (size_t i = 0; i < n; i++)
        for (size_t j = i; j < n; j++)
        {
            auto s = b.substr(i, j - i + 1);
            sort(all(s));
            allstr.insert(s);
        }
    for (size_t i = 0; i < n; i++)
        for (size_t j = i; j < n; j++)
        {
            auto s = a.substr(i, j - i + 1);
            sort(all(s));
            // allstr.insert(s);
            res += allstr.count(s);
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
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solveCase();
    }
    return 0;
}