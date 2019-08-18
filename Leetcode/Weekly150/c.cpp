#include<bits/stdc++.h>
using namespace std;
#define Debug
#ifdef Debug
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
template <typename Arg1>
void ZZ(const char *name, Arg1 &&arg1)
{
    std::cerr << name << " = " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void ZZ(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    std::cerr.write(names, comma - names) << " = " << arg1;
    ZZ(comma, args...);
}
#else
#define db(...)
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;

const int nax = 2e5 + 10;

#define f first
#define s second
int a[4] = {0, 0, 1, -1};
int b[4] = {1, -1, 0, 0};
class Solution
{
    int n, m;
    bool isValid(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

public:
    int maxDistance(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> Dist(n, vector<int>(m, 1e9));
        queue<pair<int, int>> Q;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                {
                    Dist[i][j] = 0;
                    Q.push({i, j});
                }
            }
        while (!Q.empty())
        {
            auto top = Q.front();
            Q.pop();
            for (int i = 0; i < 4; ++i)
            {
                auto x = top.f + a[i];
                auto y = top.s + b[i];
                if (isValid(x, y) && Dist[x][y] > (Dist[top.f][top.s] + 1))
                {
                    Dist[x][y] = (Dist[top.f][top.s] + 1);
                    Q.push({x, y});
                }
            }
        }
        int maxi = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                maxi = max(maxi, Dist[i][j]);
        if (maxi == 0)
            return -1;
        if (maxi > 1e7)
            return -1;
        return maxi;
    }
};