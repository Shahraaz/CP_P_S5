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
    vector<int> vecc(6);
    string key = "harbin";
    for (auto &x : vecc)
    {
        string y;
        cin >> y;
        int mask = 0;
        for (auto &c : y)
            for (size_t j = 0; j < 6; j++)
                if (c == key[j])
                    mask = mask | (1 << j);
        x = mask;
    }
    sort(all(vecc));
    bool ok = false;
    do
    {
        ok = true;
        for (size_t i = 0; i < 6; i++)
            ok = ok && ((vecc[i] >> i) & 1);
        if (ok)
            break;
    } while (next_permutation(all(vecc)));
    if (ok)
        cout << "Yes\n";
    else
        cout << "No\n";
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