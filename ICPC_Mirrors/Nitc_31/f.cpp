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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n), pop(n);
    int cntone = 0;
    ll timA = 0, timB = 0;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        timA += a[i];
        if (timA <= m)
            cntone++;
    }
    multiset<pair<int, int>> ms;
    for (size_t i = 0; i < n; i++)
    {
        cin >> b[i];
        if (i < cntone)
            ms.insert({b[i], i});
    }
    timA = timB = 0;
    int j = 0;
    for (size_t i = 0; i < n; i++)
    {
        timA += a[i];
        if (timA > m)
            continue;
        timB += a[i];
        db(i, j, a[i], b[j], timA, timB, ms);
        while (j < cntone && b[j] < timB)
        {
            timB -= b[j];
            ms.erase({b[j], j});
            ++j;
            db(i, j, a[i], b[j], timA, timB, ms);
        }
        if (ms.empty())
            break;
        timB -= (*ms.rbegin()).first;
        db(timB, ms);
        pop[(*ms.rbegin()).second]++;
    }
    int cnttwo = 0;
    timB = 0;
    vector<ll> slots;
    for (size_t i = 0; i < n; i++)
    {
        timB += b[i];
        for (size_t j = 0; j < pop[i]; j++)
        {
            if (timB <= m)
                slots.pb(timB);
            timB += b[i];
        }
        if (timB <= m)
            cnttwo++;
    }
    if (cnttwo < cntone)
    {
        cout << slots.size() << '\n';
        for (auto &x : slots)
            cout << x << ' ';
        cout << '\n';
    }
    else
        cout << "-1\n";
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