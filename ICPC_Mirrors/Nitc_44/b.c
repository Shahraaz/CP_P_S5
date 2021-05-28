// #include <bits/stdc++.h>
// using namespace std;

#include <stdio.h>
#include <string.h>

// #ifdef LOCAL
// #include "/debug.h"
// #else
// #define db(...)
// #endif

#define all(v) v.begin(), v.end()
#define pb push_back
#define ll long long;
const int MOD = 1000000007;
#define NAX 455

int ncr(int n, int r)
{
    if (n < 0 || n < r || r < 0)
        return 0;
    __int128_t ret = 1;
    for (int idx = 1; idx <= r; idx++)
    {
        ret *= (n - idx + 1);
        ret /= (idx);
    }
    return ret % MOD;
}

int solve(int n)
{
    int ret = ncr(n, 4);
    ret += ncr(n - 1, 2);
    if (ret >= MOD)
        ret -= MOD;
    ret += n;
    if (ret >= MOD)
        ret -= MOD;
    return ret;
}

void solveCase()
{
    int n;
    // cin >> A >> B >> C;
    scanf("%d", &n);
    // db(n, A, B, C);
    printf("%d\n", solve(n));
    // cout << 3 * n - solve(0, 0, 0) << '\n';
}

int main()
{
    // #ifndef LOCAL
    //     ios_base::sync_with_stdio(0);
    //     cin.tie(0);
    // #endif
    int t = 1;
    // cin >> t;
    scanf("%d\n", &t);
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}