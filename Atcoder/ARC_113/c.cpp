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
    string str;
    cin >> str;
    int n = str.size();
    db(str, n);
    ll res = 0;
    vector<int> nextcnt(26);
    for (int i = n - 1; i >= 0; i--)
    {
        nextcnt[str[i] - 'a']++;
        if (i + 2 < n && str[i] == str[i + 1] && str[i + 1] != str[i + 2])
        {
            ll toright = n - i;
            toright -= nextcnt[str[i] - 'a'];
            
            db(i, str[i], nextcnt[str[i] - 'a'], toright);
            res += toright;
            for (size_t j = 0; j < 26; j++)
                if (j == (str[i] - 'a'))
                    nextcnt[j] = n - 1 - i + 1;
                else
                    nextcnt[j] = 0;
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
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}