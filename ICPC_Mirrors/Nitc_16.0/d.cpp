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

const int NAX = 500 + 5, MOD = 1000000007;

using ld = long double;

ld dp[NAX][NAX];
bool isSolved[NAX][NAX];

vector<int> dartBoard = {1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5, 20};

ld solve(int sc1, int sc2)
{
    sc1 = max(0, sc1);
    sc2 = max(0, sc2);
    if (sc1 == 0 && sc2 == 0)
        return 0;
    if (sc1 == 1)
        return 1;
    if (sc1 == 0 || sc2 == 1)
        return 0;
    auto &ret = dp[sc1][sc2];
    if (isSolved[sc1][sc2])
        return ret;
    isSolved[sc1][sc2] = 1;
    ret = 0;
    for (auto &x : dartBoard)
    {
        if (sc1 - x <= 0)
            continue;
        int prev = 19;
        int next = 1;
        ld tempeee = 1;
        for (size_t now = 0; now < 20; now++)
        {
            auto temp = solve(sc1 - x, sc2 - dartBoard[now]);
            temp += solve(sc1 - x, sc2 - dartBoard[next]);
            temp += solve(sc1 - x, sc2 - dartBoard[prev]);
            temp /= 3;
            // db(now, x, dartBoard[now], temp);
            // ret += temp;
            tempeee = min(tempeee, temp);
            prev = now;
            next++;
            if (next >= 20)
                next -= 20;
        }
        db(sc1, sc2, x, tempeee);
        ret += tempeee;
    }
    ret /= 20;
    db(sc1, sc2, ret);
    return ret;
}

void solveCase()
{
    int n;
    db(dartBoard.size());
    // solve(0, 0, 2);
    // return;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        cout << fixed << setprecision(8);
        cout << solve(n + 1, n + 1) << ' ';
        cout << '\n';
        // cout << solve(1, n + 1, n + 1) << '\n';
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
