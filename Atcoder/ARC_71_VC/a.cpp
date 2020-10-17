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

void solveCase()
{
    int n;
    cin >> n;
    vector<int> maxCar(26, MOD);
    for (size_t i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        vector<int> maxCarNow(26);
        for (auto &x : s)
            maxCarNow[x - 'a']++;
        db(maxCarNow);
        for (size_t jk = 0; jk < 26; jk++)
        {
            maxCar[jk] = min(maxCar[jk], maxCarNow[jk]);
        }
    }
    for (size_t jk = 0; jk < 26; jk++)
    {
        while (maxCar[jk]--)
        {
            cout << char('a' + jk);
        }
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
