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

const int N = 1001;

bitset<N> ans;
bitset<N> b[15];

void solveCase(int n)
{
    for (size_t i = 0; i < 10; i++)
        b[i].reset();
    for (size_t i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        while (a--)
        {
            int x;
            cin >> x;
            b[x].set(i);
        }
    }
#ifdef LOCAL
    for (size_t i = 0; i < 10; i++)
    {
        db(i, b[i]);
    }
#endif
    string str;
    cin >> str;
    ans.reset();
    auto sstr = str.c_str();
    db(str);
    for (size_t i = 0; i < str.size(); i++)
    {
        ans <<= 1;
        ans[0] = 1;
        db(i, str[i], ans, b[sstr[i] - '0']);
        ans &= b[sstr[i] - '0'];
        db(ans);
        if (ans[n - 1] == 1)
        {
            char tmp = sstr[i + 1];
            str[i + 1] = '\0';
            cout << (sstr + i - n + 1) << '\n';
            str[i + 1] = tmp;
        }
    }
    // cout << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1, n;
    // cin >> t;
    // for (int i = 1; i <= t; ++i)
    while (cin >> n)
        solveCase(n);
    return 0;
}