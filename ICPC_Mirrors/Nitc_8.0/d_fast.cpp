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

struct Solution
{
    Solution() {}
    void solveCase()
    {
        const int s = 1 << 7;
        vector<int> v[10];
        // vector<vector<int>> v2[10];
        vector<int> col_elems[s];
        vector<int> max_elem_of_col(s);
        for (size_t i = 0; i < s; i++)
        {
            vector<int> a;
            for (size_t j = 0; j < 8; j++)
                if (i & (1 << j))
                    a.pb(j + 1);
            if (i == 0)
                max_elem_of_col[i] = 0;
            else
                max_elem_of_col[i] = a.back();
            v[a.size()].pb(i);
            // v2[a.size()].pb(a);
            col_elems[i] = a;
        }
        int g[s][s];
        for (size_t i = 0; i < s; i++)
            for (size_t j = 0; j < s; j++)
                if (col_elems[i].size() >= col_elems[j].size())
                {
                    bool ok = true;
                    for (size_t k = 0; k < col_elems[j].size(); k++)
                        if (col_elems[i][k] > col_elems[j][k])
                            ok = false;
                    g[i][j] = ok;
                }
                else
                    g[i][j] = 0;
        int k, n;
        int l[10];
        int col_sz[10];
        int dp[s][10];
        while (cin >> k)
        {
            for (size_t i = 0; i < k; i++)
                cin >> l[i];
            cin >> n;
            for (size_t i = 0; i < l[0]; i++)
            {
                col_sz[i] = 0;
                for (size_t j = 0; j < k; j++)
                    col_sz[i] += l[j] > i;
            }
            memset(dp, 0, sizeof dp);
            for (auto &x : v[col_sz[0]])
                if (max_elem_of_col[x] <= n)
                    dp[x][0] = 1;
            for (size_t j = 0; j + 1 < l[0]; j++)
                for (auto &p : v[col_sz[j]])
                    if (dp[p][j])
                        for (auto &o : v[col_sz[j + 1]])
                            if (max_elem_of_col[o] <= n && g[p][o])
                                dp[o][j + 1] += dp[p][j];
            int res = 0;
            for (auto &p : v[col_sz[l[0] - 1]])
                res += dp[p][l[0] - 1];
            cout << res << '\n';
        }
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
