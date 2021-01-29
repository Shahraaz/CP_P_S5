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

int n, a, b;

map<pair<int, int>, int> cache;

int solve(int me, int he)
{
    if (me < 0 || me >= n || he < 0 || he >= n || me == he)
        return true;
    if (cache.count({me, he}))
        return cache[{me, he}];
    auto &ret = cache[{me, he}];
    ret = false;
    ret = ret || !solve(he, me - 1);
    ret = ret || !solve(he, me + 1);
    db(me, he, ret);
    return ret;
}

void solveCase()
{
    cin >> n >> a >> b;
    --a, --b;
    if (solve(a, b))
        cout << "Alice\n";
    else
        cout << "Borys\n";
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