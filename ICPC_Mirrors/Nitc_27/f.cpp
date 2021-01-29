#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

#define int ll

#define all(v) v.begin(), v.end()
#define pb push_back
using ll = long long;
const int NAX = 2e5 + 5, MOD = 1000000007;
const int B = 450;

int n, q;
ll dx[B + 1][B + 1];
ll naive[NAX];

void solveCase()
{
    cin >> n >> q;
    for (size_t i = 0; i < q; i++)
    {
        int t, a, b, c;
        cin >> t;
        if (t == 1)
        {
            cin >> a >> b >> c;
            if (b >= B)
            {
                int curr = a;
                while (curr <= n)
                {
                    naive[curr] += c;
                    curr += b;
                }
            }
            else
            {
                dx[a][b] += c;
            }
        }
        else
        {
            int d;
            cin >> d;
            ll curr = naive[d];
            for (size_t b = 1; b < B; b++)
            {
                int a = d % b;
                curr += dx[a][b];
            }
            cout << curr << '\n';
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
        solveCase();
    return 0;
}