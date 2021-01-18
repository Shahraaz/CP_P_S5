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

int n;

void solveCase()
{
    string str;
    cin >> str;
    int k;
    cin >> k;
    n = str.size();
    vector<string> mystrs;
    for (size_t i = 0; i < min(5, n); i++)
    {
        for (size_t j = 0; j + i < n; j++)
            mystrs.pb(str.substr(j, i + 1));
    }
    sort(all(mystrs));
    mystrs.erase(unique(all(mystrs)), mystrs.end());
    db(mystrs);
    cout << mystrs[k - 1] << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}