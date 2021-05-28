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

int n;

int solve(int idx)
{
    int ret = 1;
    if (idx == 0)
        return ret;
    ret = solve(idx / 2);
    ret = (ret * 1LL * ret) % MOD;
    if (idx & 1)
        ret = (ret * 1LL * 2) % MOD;
    // printf("%d %d\n", idx, ret);
    return ret;
} 

void solveCase()
{
    // cin >> A >> B >> C;
    scanf("%d", &n);
    // db(n, A, B, C);
    printf("%d\n", solve(n - 1));
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