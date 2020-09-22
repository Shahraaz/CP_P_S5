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

class Solution
{
public:
    int maxProductPath(vector<vector<int>> &grid)
    {
        ll res = LLONG_MIN;
        int n = grid.size(), m = grid[0].size();
        vector<vector<ll>> maxProd(n, vector<ll>(m, -1e15));
        vector<vector<ll>> minProd(n, vector<ll>(m, 1e15));
        maxProd[n - 1][m - 1] = minProd[n - 1][m - 1] = grid[n - 1][m - 1];
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
            {
                if (i + 1 < n)
                {
                    maxProd[i][j] = max(maxProd[i][j], maxProd[i + 1][j] * grid[i][j]);
                    maxProd[i][j] = max(maxProd[i][j], minProd[i + 1][j] * grid[i][j]);

                    minProd[i][j] = min(minProd[i][j], minProd[i + 1][j] * grid[i][j]);
                    minProd[i][j] = min(minProd[i][j], maxProd[i + 1][j] * grid[i][j]);
                }
                if (j + 1 < m)
                {
                    maxProd[i][j] = max(maxProd[i][j], maxProd[i][j + 1] * grid[i][j]);
                    maxProd[i][j] = max(maxProd[i][j], minProd[i][j + 1] * grid[i][j]);

                    minProd[i][j] = min(minProd[i][j], maxProd[i][j + 1] * grid[i][j]);
                    minProd[i][j] = min(minProd[i][j], minProd[i][j + 1] * grid[i][j]);
                }
                cout << i << ' ' << j << ' ' << minProd[i][j] << ' ' << maxProd[i][j] << '\n';
            }

        res = max(res, maxProd[0][0]);
        if (res < 0)
            return -1;
        return res % MOD;
    }
};

#ifdef LOCAL
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    Solution S;
    for (int i = 1; i <= t; ++i)
    {
        ;
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif