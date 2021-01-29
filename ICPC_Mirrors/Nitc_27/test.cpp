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
const int NAX = 100 + 5, MOD = 1000000007;

const int p1 = 29, p2 = 34483;
const p = p1 * p2;

int ncr_p1[NAX][NAX];
int ncr_p2[NAX][NAX];
int ncr_p[NAX][NAX];

void solveCase()
{
    for (size_t i = 0; i < N; i++)
    {
        ncr_p1[i][0] = ncr_p2[i][0] = ncr_p[i][0] = 1;
        
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