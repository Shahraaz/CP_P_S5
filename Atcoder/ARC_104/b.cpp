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
    string S;
    int n;
    cin >> n >> S;
    vector<int> cntA(n);
    vector<int> cntC(n);
    vector<int> cntT(n);
    vector<int> cntG(n);
    for (size_t i = 0; i < n; i++)
    {
        if (i > 0)
        {
            cntA[i] = cntA[i - 1];
            cntC[i] = cntC[i - 1];
            cntT[i] = cntT[i - 1];
            cntG[i] = cntG[i - 1];
        }
        cntA[i] += S[i] == 'A';
        cntC[i] += S[i] == 'C';
        cntT[i] += S[i] == 'T';
        cntG[i] += S[i] == 'G';
    }
    ll res = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i; j < n; j++)
        {
            int A = cntA[j];
            if (i > 0)
                A -= cntA[i - 1];
            int C = cntC[j];
            if (i > 0)
                C -= cntC[i - 1];
            int G = cntG[j];
            if (i > 0)
                G -= cntG[i - 1];
            int T = cntT[j];
            if (i > 0)
                T -= cntT[i - 1];
            if (A == T && C == G)
                res++;
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
