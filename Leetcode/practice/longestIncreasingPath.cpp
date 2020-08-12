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
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        if (m == 0)
            return 0;
        vector<int> adj[n * m];
        auto getIdx = [&](int x, int y) -> int {
            return x * m + y;
        };
        auto isValid = [&](int x, int y) -> bool {
            return 0 <= x && x < n && 0 <= y && y < m;
        };
        int a[] = {0, 0, 1, -1};
        int b[] = {1, -1, 0, 0};
        int LIM = n * m;
        vector<int> degree(LIM, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < 4; k++)
                {
                    int x = i + a[k];
                    int y = j + b[k];
                    if (isValid(x, y))
                    {
                        if (matrix[i][j] == matrix[x][y])
                            continue;
                        if (matrix[i][j] < matrix[x][y])
                        {
                            adj[getIdx(x, y)].pb(getIdx(i, j));
                            degree[getIdx(i, j)]++;
                        }
                        else
                        {
                            adj[getIdx(i, j)].pb(getIdx(x, y));
                            degree[getIdx(x, y)]++;
                        }
                    }
                }
        vector<int> longestPath(LIM, -1);
        // vector<int> vis(LIM, 0);
        queue<int> Q;
        for (int i = 0; i < n * m; i++)
            if (degree[i] == 0)
            {
                Q.push(i);
                longestPath[i] = 1;
                // vis[i] = 1;
            }
        while (Q.size())
        {
            auto top = Q.front();
            Q.pop();
            for (auto &x : adj[top])
            {
                degree[x]--;
                longestPath[x] = max(longestPath[x], longestPath[top] + 1);
                if (degree[x] == 0)
                    Q.push(x);
            }
        }
        return *max_element(all(longestPath));
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