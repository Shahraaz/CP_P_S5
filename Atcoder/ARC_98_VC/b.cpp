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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> nextnonzero(n + 1, n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 0)
            nextnonzero[i] = nextnonzero[i + 1];
        else
            nextnonzero[i] = i;
    }
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        ll curr_sum = a[i], curr_xor = a[i];
        int rptr = i + 1;
        while (rptr < n)
        {
            if (a[rptr] == 0)
                rptr = nextnonzero[rptr];
            else
            {
                if ((curr_sum + a[rptr]) == (curr_xor ^ a[rptr]))
                {
                    curr_xor ^= a[rptr];
                    curr_sum += a[rptr];
                    ++rptr;
                }
                else
                    break;
            }
        }
        res += rptr - i;
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