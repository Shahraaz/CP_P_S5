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
    int n, s, q;
    cin >> n >> s >> q;
    if (n == 1)
    {
        cout << 0 << '\n'
             << 1 << '\n';
        return;
    }
    --s, --q;
    vector<int> vecc(n);
    for (size_t i = 0; i < n; i++)
        vecc[i] = i;
    if (vecc[q] == s)
    {
        cout << 1 << '\n';
        for (auto &x : vecc)
            cout << x + 1 << ' ';
        cout << '\n';
        return;
    }
    reverse(all(vecc));
    if (vecc[q] == s)
    {
        cout << 1 << '\n';
        for (auto &x : vecc)
            cout << x + 1 << ' ';
        cout << '\n';
        return;
    }
    reverse(all(vecc));
    int best = MOD;
    cout << 2 << '\n';
    vector<int> arr;
    for (size_t i = 1; i <= n; i += 2)
        arr.pb(i);
    int rptr = n;
    if (n & 1)
        rptr--;
    while (rptr >= 1)
    {
        arr.pb(rptr);
        rptr -= 2;
    }
    for (size_t i = 0; i < n; i++)
        arr.pb(arr[i]);
    for (size_t i = 0; i < n; i++)
        arr.pb(arr[i]);
    db(arr);
    db(n, s, q);
    ++s;
    ++q;
    rptr = -1;
    for (int i = n; i < 2 * n; i++)
        if (arr[i] == s)
        {
            db(i, arr[i], i - q + 1);
            rptr = i - q + 1;
            break;
        }
    assert(rptr >= 0);
    while (n--)
        cout << arr[rptr++] << ' ';
    cout << '\n';
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
        solveCase();
    return 0;
}