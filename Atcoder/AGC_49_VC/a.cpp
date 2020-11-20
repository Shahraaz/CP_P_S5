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
    vector<vector<int>> adj(n, vector<int>(n));
    for (size_t i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        adj[i][i] = 1;
        for (size_t j = 0; j < n; j++)
            if (str[j] == '1')
                adj[i][j] = 1;
    }
    for (size_t i = 0; i < 100; i++)
        for (size_t j = 0; j < n; j++)
            for (size_t k = 0; k < n; k++)
                for (size_t l = 0; l < n; l++)
                    if (adj[j][k] && adj[k][l])
                        adj[j][l] = 1;
    using ld = long double;
    vector<ld> p_exist(n, 1);
    vector<vector<ld>> vecc(101);
    vector<vector<ld>> moves(101);
    ld expected_den = n;
    ld res = 0;
    for (size_t time = 1; time <= 100; time++)
    {
        if (expected_den < 1e-12)
            break;
        vector<ld> p_next(n);
        for (size_t i = 0; i < n; i++)
        {
            ld pdead = 0;
            for (size_t j = 0; j < n; j++)
                if (adj[j][i])
                    pdead += p_exist[j] / expected_den;
            p_next[i] = p_exist[i] * (1 - pdead);
        }
        db(time, expected_den, p_next);
        vecc[time] = p_exist;
        p_exist = p_next;
        expected_den = 0;
        for (size_t i = 0; i < n; i++)
            expected_den += p_exist[i];
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
#ifdef TIMER
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}