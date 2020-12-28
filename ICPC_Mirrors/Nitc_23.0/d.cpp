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
const int NAX = 2e5 + 5, MOD = 1000000000;

int N;

int ask(int x)
{
    cout << "QUERY " << x << ' ' << (x + MOD / 2) % MOD << endl;
    cin >> x;
    return x - N / 2;
}

void yes(int x)
{
    cout << "YES " << x << endl;
    exit(0);
}

void solve(int l, int r)
{
    if (r <= l)
        yes(l);
    int mid = (l + r) / 2;
    auto q = ask(mid);
    db(l, r, mid, q);
    if (q == 0)
        yes(mid);
    if (q > 0)
        solve(mid + 1, r);
    return solve(l, mid - 1);
}

void solveCase()
{
    cin >> N;
    solve(0, MOD - 1);
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