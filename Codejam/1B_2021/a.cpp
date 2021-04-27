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
    vector<ll> vecc(3);
    for (auto &x : vecc)
        cin >> x;
    sort(all(vecc));
    do
    {
        // 0 hours;
        // 1  mins;
        // 2 seconds;

        // 1 second 1e9 ns
        // 1 min    60 1e9 ns
        // 1 hr     3600 1e9 ns

        /*
            time is t ns
            seconds hand is at 

        */

        // 1ns - 1 tick hours
        // 1ns - 12 tick mins
        // 1ns - 720 tick second

        ll h = vecc[0];
        ll m = vecc[1];
        ll s = vecc[2];

        // 1s - 1e9 tick hours
        // 1s - 12e9 tick mins
        // 1s - 720 e9 tick second

        // 1 tick 1/12 e-10 degree
        // 12 e10 tick is 1 degree
        // 12 hr 360 degree

        // 1 hr 30 degree -> 360 e10 tick -> period -> 21600 e10 ticks
        // 1 min 1/2 degree -> 6 e10 tick -> period -> 360 e10 ticks
        // 1 second 1/120 degree -> 1e9 ticks -> period -> 6 1e10 ticks
        // 1ns 1/120 e-9 degree -> 1/120 e-9 * 12*1e10 -> 1 tick -> period

        // T total ticks
        // H passed -> T / (216 e12)
        // M passed -> T / (360 e10)
        // S passed -> T / (6 e10)
        // ns passed -> T % (6 e10)

        const ll oneENine = 1000000000;
        const ll oneETen = 1000000000LL * 10;
        // if (m % 12 == 0 && s % 720 == 0)
        {
            ll H = h / (360 * oneETen);
            ll M = m / (12 * 6 * oneETen);

            ll ns = s / 720;

            ll seconds = ns / oneENine;

            ns = ns % oneENine;

            db(H, M, seconds, ns);
        }

    } while (next_permutation(all(vecc)));
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
    {
        cout << "Case #" << i << ": ";
        solveCase();
    }
    return 0;
}