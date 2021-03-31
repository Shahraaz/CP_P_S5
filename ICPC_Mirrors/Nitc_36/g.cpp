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
    string str;
    cin >> str;
    int rank = 25, conseq = 0, stars = 0;
    map<int, int> mp;
    mp[-21] = 2;
    mp[-16] = 3;
    mp[-11] = 4;
    mp[-1] = 5;
    for (auto &x : str)
    {
        if (rank == 0)
            break;
        db(x, rank, stars, conseq);
        if (x == 'W')
        {
            conseq++;
            if (rank >= 6 && conseq >= 3)
            {
                stars++;
                for (auto &x : mp)
                {
                    int r = -x.first;
                    if (rank >= r)
                    {
                        if (stars > x.second)
                        {
                            stars -= x.second;
                            rank--;
                        }
                        break;
                    }
                }
            }
            if (rank == 0)
                break;

            stars++;
            for (auto &x : mp)
            {
                int r = -x.first;
                if (rank >= r)
                {
                    if (stars > x.second)
                    {
                        stars -= x.second;
                        rank--;
                    }
                    break;
                }
            }
            if (rank == 0)
                break;
        }
        else
        {
            conseq = 0;
            if (rank >= 21)
                continue;
            stars--;
            if (stars < 0)
            {
                if (rank == 20)
                    stars = 0;
                else
                {
                    rank++;
                    if (rank >= 21)
                        stars = 1;
                    else if (rank >= 16)
                        stars = 2;
                    else if (rank >= 11)
                        stars = 3;
                    else
                        stars = 4;
                }
            }
        }
    }
    if (rank == 0)
        cout << "Legend\n";
    else
        cout << rank << '\n';
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