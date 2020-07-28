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

const int NAX = 2e5 + 5, MOD = 1000000007;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep2(i, l, r) for (ll i = (l); i < (r); i++)
#define rep2r(i, l, r) for (ll i = (r)-1; i >= (l); i--)
#define endl '\n'

const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int monthDays1[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Solution
{
    Solution() {}
    void solveCase()
    {
        string s;
        while (cin >> s)
        {
            int year = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
            int month = (s[5] - '0') * 10 + (s[6] - '0');
            int day = (s[8] - '0') * 10 + (s[9] - '0');
            int daysTillNow = day;
            rep2(i, 0, year)
            {
                if (i % 4 == 0)
                    daysTillNow += 366;
                else
                    daysTillNow += 365;
            }
            rep(i, month) daysTillNow += monthDays[i];
            if (year % 4 == 0 and month >= 3)
                daysTillNow += 1;
            int i = 0;
            // daysTillNow++;
            while (true)
            {
                if (i % 400 == 0)
                {
                    if (daysTillNow >= 366)
                        daysTillNow -= 366;
                    else
                        break;
                }
                else if (i % 100 == 0)
                {
                    if (daysTillNow >= 365)
                        daysTillNow -= 365;
                    else
                        break;
                }
                else if (i % 4 == 0)
                {
                    if (daysTillNow >= 366)
                        daysTillNow -= 366;
                    else
                        break;
                }
                else if (i % 4)
                {
                    if (daysTillNow >= 365)
                        daysTillNow -= 365;
                    else
                        break;
                }
                else
                    break;
                i++;
            }
            // i++;
            int j = 1;
            db(daysTillNow, i);
            if (i % 400 == 0)
            {
                while (daysTillNow >= monthDays1[j - 1])
                {
                    daysTillNow -= monthDays1[j - 1];
                    j++;
                }
            }
            else if (i % 100 == 0)
            {
                while (daysTillNow >= monthDays[j - 1])
                {
                    daysTillNow -= monthDays[j - 1];
                    j++;
                }
            }
            else if (i % 4 == 0)
            {
                while (daysTillNow >= monthDays1[j - 1])
                {
                    daysTillNow -= monthDays1[j - 1];
                    j++;
                }
            }
            else
            {
                while (daysTillNow >= monthDays[j - 1])
                {
                    daysTillNow -= monthDays[j - 1];
                    j++;
                }
            }
            // ++j;
            cout << i << "-" << j << "-" << daysTillNow << endl;
        }
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
