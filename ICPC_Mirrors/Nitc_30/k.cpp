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
using ld = long double;
const ld PI = acosl(-1), EPS = 1e-12;

bool eq(ld a, ld b)
{
    return (a - b) <= EPS;
}

bool l(ld a, ld b)
{
    return a + EPS < b;
}

bool g(ld a, ld b)
{
    return !l(b, a);
}

bool leq(ld a, ld b)
{
    return eq(a, b) || l(a, b);
}

bool geq(ld a, ld b)
{
    return eq(a, b) || g(a, b);
}

void solveCase()
{
    int n;
    cin >> n;
    vector<int> t(n), s(n), order(n), always_on(n);
    vector<ld> a(n), windowlen(n);
    priority_queue<pair<ld, int>, vector<pair<ld, int>>, greater<pair<ld, int>>> pQ_normal_l, pQ_normal_r, pQ_all_on_l, pQ_all_on_r;
    ld sum_normal_l = 0, sum_normal_r = 0, sum_all_on_l = 0, sum_all_on_r = 0;
    ld sum_si_l = 0, sum_si_r = 0, sum_si_on_l = 0, sum_si_on_r = 0;
    for (size_t i = 0; i < n; i++)
    {
        // order[i] = i;
        cin >> t[i] >> s[i] >> a[i];
        if (s[i] == 0 || (t[i] >= s[i] * (PI - EPS)))
        {
            always_on[i] = 1;
            ld left = a[i] - PI, middle = a[i], right = a[i] + PI;
            if (leq(left, 0) && leq(0, middle))
            {
                sum_all_on_l += t[i] + s[i] * a[i];
                sum_si_on_l += s[i];
                
            }
            else
            {
                sum_all_on_r += t[i] - s[i] * a[i];
                sum_si_on_r += s[i];
            }
        }
        else
        {
            windowlen[i] = ld(t[i]) / s[i];
        }
        db(i, t[i], s[i], a[i], always_on[i], windowlen[i]);
    }
    // sort(all(order), [&](int i, int j) -> bool { return a[i] < a[j]; });
    // db(order);
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