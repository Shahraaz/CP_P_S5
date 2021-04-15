#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

#define all(v) v.begin(), v.end()
#define pb push_back
const long long NAX = 2e5 + 5, MOD = 8589934592LL;

void solveCase()
{
    string str;
    cin >> str;
    if (str.size() > 10)
    {
        cout << MOD - 1 << '\n';
        return;
    }
    long long curr = 1;
    auto n = stoll(str);
    for (size_t i = 0; i < n; i++)
    {
        curr = curr * 2;
        if (curr > MOD * 2)
        {
            cout << MOD - 1 << '\n';
            return;
        }

    }
    cout << (curr - 1) % MOD << '\n';
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
        cout << "Case " << i << ": ";
        solveCase();
    }
    return 0;
}