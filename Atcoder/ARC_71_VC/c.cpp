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
    string S, T;
    cin >> S >> T;
    int n = S.length();
    int m = T.length();
    vector<int> aS(n), bS(n);
    vector<int> aT(m), bT(m);
    for (size_t i = 0; i < n; i++)
    {
        if (i > 0)
        {
            aS[i] += aS[i - 1];
            bS[i] += bS[i - 1];
        }
        aS[i] += S[i] == 'A';
        bS[i] += S[i] == 'B';
    }
    for (size_t i = 0; i < m; i++)
    {
        if (i > 0)
        {
            aT[i] += aT[i - 1];
            bT[i] += bT[i - 1];
        }
        aT[i] += T[i] == 'A';
        bT[i] += T[i] == 'B';
    }
    int q;
    cin >> q;
    for (size_t i = 0; i < q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a, --b, --c, --d;

        vector<int> cntS(2);
        cntS[0] = aS[b];
        if (a > 0)
            cntS[0] -= aS[a - 1];
        cntS[1] = bS[b];
        if (a > 0)
            cntS[1] -= bS[a - 1];

        vector<int> cntT(2);
        cntT[0] = aT[d];
        if (c > 0)
            cntT[0] -= aT[c - 1];
        cntT[1] = bT[d];
        if (c > 0)
            cntT[1] -= bT[c - 1];

        db(cntS, cntT);
        int hashA = cntS[0] + cntS[1] * 2;
        int hashB = cntT[0] + cntT[1] * 2;

        if (hashA % 3 == hashB % 3)
            cout << "YES\n";
        else
            cout << "NO\n";
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
