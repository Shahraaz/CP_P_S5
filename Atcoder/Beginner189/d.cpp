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
    vector<string> S(n + 1);
    for (size_t i = 0; i < n; i++)
        cin >> S[i];
    int rptr = n - 1;
    ll ret = 0;
    db(S);
    while (rptr >= 0)
    {
        int prev = rptr;
        // db(rptr);
        while (rptr >= 0)
        {
            // db(rptr);
            if (S[rptr] == "AND")
                --rptr;
            else
                break;
        }
        db(rptr, prev, 1LL << (rptr + 1));
        ret += 1LL << (rptr + 1);
        --rptr;
    }
    if (S[0] == "OR")
        ret++;
    cout << ret << '\n';
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