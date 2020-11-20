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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    ll res = 0;
    map<ll, ll> cnt;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            set<ll> temp;
            temp.insert(a[i] * a[j]);
            if (a[i] % a[j] == 0)
                temp.insert(a[i] / a[j]);
            if (a[j] % a[i] == 0)
                temp.insert(a[j] / a[i]);
            for (auto &x : temp)
            {
                auto it = cnt.find(x);
                if (it != cnt.end())
                    res += it->second;
            }
        }
        db(i, res, cnt);
        cnt[a[i]]++;
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