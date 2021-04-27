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
const int NAX = 5e5 + 5, MOD = 1000000007;

int n, a, b;
vector<int> u;

void solveCase()
{
    n = 20;
    a = rand() % 20 + 1;
    b = rand() % 20 + 1;
    // cin >> n >> a >> b;
    u.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        u[i] = 20;
        // cin >> u[i];
    }
    reverse(all(u));

    const int LIM = NAX;
    vector<int> cnt(LIM + 1);
    db(u);
    db(n, a, b, LIM);
    cnt[0] = 1;
    for (int i = 0; i <= LIM; i++)
    {
        if (i - a >= 0)
        {
            cnt[i] += cnt[i - a];
            cnt[i] = min(cnt[i], 100);
        }
        if (i - b >= 0)
        {
            cnt[i] += cnt[i - b];
            cnt[i] = min(cnt[i], 100);
        }
        db(i, cnt[i]);

        // if (i >= b)
        {
            int jptr = max(0, i - b);
            map<int, int> cnt2;
            while (jptr <= i)
            {
                if (jptr + b >= i + 1)
                {
                    cnt2[jptr + b] += cnt[jptr];
                    cnt2[jptr + b] = min(cnt2[jptr + b], 100);
                }
                if (jptr + a >= i + 1)
                {
                    cnt2[jptr + a] += cnt[jptr];
                    cnt2[jptr + a] = min(cnt2[jptr + a], 100);
                }
                ++jptr;
            }
            db(cnt2);
            bool ok = true;
            for (size_t j = 1; j <= n; j++)
            {
                if (cnt2[i + j] < u[j - 1])
                {
                    ok = false;
                    break;
                }
                int excess = cnt2[i + j] - u[j - 1];

                cnt2[i + j + a] += excess;
                cnt2[i + j + a] = min(100, cnt2[i + j + a]);

                cnt2[i + j + b] += excess;
                cnt2[i + j + b] = min(100, cnt2[i + j + b]);
            }
            if (ok)
            {
                cout << i + n + 1 << '\n';
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 100;
    // cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solveCase();
    }
    return 0;
}