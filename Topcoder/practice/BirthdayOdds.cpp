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

class BirthdayOdds
{
public:
    int minPeople(int minOdds, int daysInYear)
    {
        double prob = 1;
        int ctr = 1;
        while (true)
        {
            prob = (daysInYear - ctr) * prob / daysInYear;
            db(ctr, prob);
            if (100 * (1 - prob) > minOdds)
                break;
            ctr++;
        }
        return ctr;
    }
};

#ifndef LOCAL
//<%:testing-code%>
#endif

#ifdef LOCAL
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    // Solution S;
    BirthdayOdds b;
    for (int i = 1; i <= t; ++i)
    {
        db(b.minPeople(50, 365));
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!