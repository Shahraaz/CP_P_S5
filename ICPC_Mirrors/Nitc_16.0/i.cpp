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

void solveCase(int n, int m)
{
    vector<pair<ll, ll>> events;
    for (size_t i = 0; i < n; i++)
    {
        int s, d;
        cin >> s >> d;
        cin >> s >> d;
        int e = s + d;
        events.pb({s, e});
        // events.pb({s, 2});
    }
    for (size_t i = 0; i < m; i++)
    {
        int s, d;
        cin >> s >> d;
        int e = s + d;
        int cnt = 0;
        for (auto x : events)
        {
            auto y = pair<ll, ll>{s, e};
            if (x > y)
                swap(x, y);
            db(x, y, cnt);
            if (x.s - y.f > 0)
                cnt++;
            db(cnt);
        }
        cout << cnt << '\n';
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
    int n, m;
    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        solveCase(n, m);
#ifdef LOCAL
        cerr << "Case #: Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
