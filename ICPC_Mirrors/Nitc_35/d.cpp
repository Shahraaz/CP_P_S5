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
const int NAX = 3e5 + 10, MOD = 1000000007;

int n;
int f[NAX][256], b[256], a[NAX], val[NAX];
char s[NAX];

int gogo(int i, int mask)
{
    if (f[i][mask] != -1)
        return f[i][mask];
    auto ret = gogo(i - 1, (mask >> 1) | b[mask | a[i]]);
    db(i, bitset<8>(mask), ret);
    return f[i][mask] = ret;
}

void solveCase()
{
    cin >> n;
    memset(f, -1, sizeof f);
    for (size_t i = 1; i <= n; i++)
    {
        cin >> s;
        for (size_t j = 0; j < 8; j++)
            val[i] |= (1 << j) * (s[j] == 'W');
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= i + 8; j++)
        {
            a[i] += (1 << (8 - (j - i))) * (((8 - __builtin_popcount(val[i] ^ val[j])) < j - i) || (j > n));
        }
        db(i, bitset<8>(a[i]));
    }
    for (size_t i = 0; i < (1 << 8); i++)
        b[i] = 1 << 7;
    b[(1 << 8) - 1] = 1;
    for (size_t i = 0; i < (1 << 8); i++)
        f[1][i] = (a[1] | i) < ((1 << 8) - 1);
    for (int i = 1; i <= n; i++)
    {
        if (gogo(i, (1 << 8) - 1))
            cout << 1;
        else
            cout << 2;
    cout << '\n';
    }
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