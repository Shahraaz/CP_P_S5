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
    int n, p;
    cin >> n >> p;
    vector<pair<int, string>> forbid;
    for (size_t i = 0; i < p; i++)
    {
        string str;
        cin >> str;
        forbid.pb({str.size(), str});
    }
    sort(all(forbid));
    vector<string> str;
    ll res = 1LL << n;
    for (int i = 0; i < p; i++)
    {
        bool ok = true;
        for (auto &x : str)
            if (forbid[i].second.substr(0, x.length()) == x)
                ok = false;
        db(str, ok, forbid[i]);
        if (ok)
        {
            str.pb(forbid[i].second);
            res -= 1LL << (n - forbid[i].first);
        }
    }
    cout << res << '\n';
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
#ifdef TIMER
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}