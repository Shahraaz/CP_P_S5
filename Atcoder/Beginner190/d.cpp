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
    ll N;
    cin >> N;
    int res = 0;
    for (ll curr = 1; curr * curr <= 2 * N; curr++)
        if ((2 * N) % curr == 0)
        {
            ll temp = (2 * N) / curr;
            temp -= (2 * curr - 1);
            db(curr, temp, N);
            if (temp % 2 == 0)
            {
                res++;
            }
            ll back = curr;
            {
                curr = 2 * N / back;
                temp = (2 * N) / curr;
                temp -= (2 * curr - 1);
                db(curr, temp, N);
                if (temp % 2 == 0)
                {
                    res++;
                }
            }
            curr = back;
        }
    cout << 2 * res << '\n';
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