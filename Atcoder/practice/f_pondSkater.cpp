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
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int H, W, K;
        int x1, y1, x2, y2;
        cin >> H >> W >> K;
        cin >> x1 >> y1 >> x2 >> y2;
        vector<string> c(H);
        for (auto &x : c)
            cin >> x;
        vector<vector<ll>> dist(H, vector<ll>(W, INT_MAX));
        vector<vector<bool>> goRight(H, vector<bool>(W, true));
        vector<vector<bool>> goLeft(H, vector<bool>(W, true));
        vector<vector<bool>> goUp(H, vector<bool>(W, true));
        vector<vector<bool>> goDown(H, vector<bool>(W, true));
        x1--, y1--, x2--, y2--;
        queue<pair<int, int>> Q;
        Q.push({x1, y1});
        dist[x1][y1] = 0;
        auto isValid = [&](int x, int y) -> bool {
            return 0 <= x && x < H && 0 <= y && y < W && c[x][y] == '.';
        };
        auto isVisited = [&](int x, int y) -> bool {
            return !isValid(x, y) || dist[x][y] != INT_MAX;
        };
        while (Q.size())
        {
            auto top = Q.front();
            if (top.f == x2 && top.s == y2)
                break;
            db(top);
            if (isValid(top.f, top.s))
            {
                db(dist[top.f][top.s])
            }
            Q.pop();
            if (goLeft[top.f][top.s])
            {
                for (int i = 1; i <= K; i++)
                {
                    int x = top.f - i;
                    int y = top.s;
                    if (!isValid(x, y))
                        break;
                    if (i == K || !isValid(x - 1, y))
                        goLeft[x][y] = true;
                    else
                        goLeft[x][y] = false;
                    goRight[x][y] = false;
                    if (!isVisited(x, y))
                    {
                        dist[x][y] = dist[top.f][top.s] + 1;
                        Q.push({x, y});
                    }
                }
                goLeft[top.f][top.s] = false;
            }
            if (goRight[top.f][top.s])
            {
                for (int i = 1; i <= K; i++)
                {
                    int x = top.f + i;
                    int y = top.s;
                    if (!isValid(x, y))
                        break;
                    if (i == K || !isValid(x + 1, y))
                        goRight[x][y] = true;
                    else
                        goRight[x][y] = false;
                    goLeft[x][y] = false;
                    if (!isVisited(x, y))
                    {
                        dist[x][y] = dist[top.f][top.s] + 1;
                        Q.push({x, y});
                    }
                }
                goRight[top.f][top.s] = false;
            }

            if (goUp[top.f][top.s])
            {
                for (int i = 1; i <= K; i++)
                {
                    int x = top.f;
                    int y = top.s - i;
                    if (!isValid(x, y))
                        break;
                    if (i == K || !isValid(x, y - 1))
                        goUp[x][y] = true;
                    else
                        goUp[x][y] = false;
                    goDown[x][y] = false;
                    if (!isVisited(x, y))
                    {
                        dist[x][y] = dist[top.f][top.s] + 1;
                        Q.push({x, y});
                    }
                }
                goUp[top.f][top.s] = false;
            }
            if (goDown[top.f][top.s])
            {
                for (int i = 1; i <= K; i++)
                {
                    int x = top.f;
                    int y = top.s + i;
                    if (!isValid(x, y))
                        break;
                    if (i == K || !isValid(x, y + 1))
                        goDown[x][y] = true;
                    else
                        goDown[x][y] = false;
                    goUp[x][y] = false;
                    if (!isVisited(x, y))
                    {
                        dist[x][y] = dist[top.f][top.s] + 1;
                        Q.push({x, y});
                    }
                }
                goDown[top.f][top.s] = false;
            }
        }
        // db(dist);
        if (dist[x2][y2] == INT_MAX)
            cout << -1 << '\n';
        else
            cout << dist[x2][y2] << '\n';
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
