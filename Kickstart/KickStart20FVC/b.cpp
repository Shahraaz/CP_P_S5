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

#define int ll

void solveCase()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> vecc;
    for (size_t i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        vecc.pb({s, e});
    }
    sort(all(vecc));
    int res = 0;
    int prev_start = -MOD;
    for (auto &x : vecc)
    {
        db(prev_start, res, x);
        int eptr = prev_start + k;
        if (eptr <= x.f)
        {
            int dur = x.s - x.f;
            res += dur / k;
            prev_start = x.f + (dur / k) * k;
            if (dur % k)
                res++;
            else
                prev_start -= k;
        }
        else
        {
            if (eptr >= x.s)
            {
            }
            else
            {
                x.f = eptr;
                int dur = x.s - x.f;
                res += dur / k;
                prev_start = x.f + (dur / k) * k;
                if (dur % k)
                    res++;
                else
                    prev_start -= k;
            }
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
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
