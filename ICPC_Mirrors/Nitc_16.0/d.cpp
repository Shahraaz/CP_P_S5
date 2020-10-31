// Optimise
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()

const int NAX = 510, MOD = 1000000007;

using ld = long double;

ld dp[NAX][NAX][2];
vector<int> dartBoard = {1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5, 20, 1, 18};

void solveCase()
{
    cout << fixed << setprecision(8);

    for (size_t firstPlayer = 0; firstPlayer < NAX; firstPlayer++)
        dp[firstPlayer][0][0] = 0;
    for (size_t secondPlayer = 0; secondPlayer < NAX; secondPlayer++)
        dp[0][secondPlayer][1] = 0;

    for (int f = 1; f < NAX; f++)
        for (int s = 1; s < NAX; s++)
        {
            // db('~', f, s, dp[f][s][0], dp[f][s][1]);
            ld pr0 = 0, a0 = 0;
            for (int i = 1; i <= 20; i++)
                if (i <= f)
                    pr0 += 1 - dp[f - i][s][1];
                else
                    a0 += 1;

            pr0 /= 20;
            a0 /= 20;

            ld pr1[4];
            for (size_t i = 0; i < 4; i++)
                pr1[i] = -1;
            for (int i = 1; i < 21; i++)
            {
                int a1 = 0;
                ld pr1_now = 0;
                for (auto x : {-1, 0, 1})
                    if (dartBoard[i + x] <= s)
                        pr1_now += 1 - dp[f][s - dartBoard[i + x]][0];
                    else
                        a1++;
                pr1_now /= 3;
                pr1[a1] = max(pr1[a1], pr1_now);
            }

            dp[f][s][1] = -1e9;
            for (size_t i = 0; i < 4; i++)
                if (pr1[i] > -0.5)
                {
                    ld a1 = i / (ld)3;
                    dp[f][s][1] = max(dp[f][s][1], (pr1[i] + a1 * (1 - pr0 - a0)) / (1 - a1 * a0));
                }

            dp[f][s][0] = pr0 + a0 * (1 - dp[f][s][1]);
            db(f, s, dp[f][s][0], dp[f][s][1]);
        }

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        cout << dp[n][n][0] << ' ';
        cout << dp[n][n][1] << ' ';
        cout << '\n';
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
    {
        solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
