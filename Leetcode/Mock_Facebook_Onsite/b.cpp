#include <bits/stdc++.h>
using namespace std;
#define Debug
#ifdef Debug
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
#define pc(...) PC(#__VA_ARGS__, __VA_ARGS__);
template <typename T, typename U>
ostream &operator<<(ostream &out, const pair<T, U> &p)
{
    out << '[' << p.first << ", " << p.second << ']';
    return out;
}
template <typename Arg>
void PC(const char *name, Arg &&arg)
{
    std::cerr << name << " { ";
    for (const auto &v : arg)
        cerr << v << ' ';
    cerr << " }\n";
}
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
#define pc(...)
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;

const int nax = 2e5 + 10;

int a[4] = {0, 0, 1, -1};
int b[4] = {1, -1, 0, 0};

class Solution
{
    bool isValid(int x, int y, int n, int m)
    {
        return 0 <= x && x < n && 0 <= y && y < m;
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        db("Start");
        int n = grid.size();
        if (n == 0)
            return 0;
        int m = grid[0].size();
        if (m == 0)
            return 0;
        vector<vector<bool>> vis(n, vector<bool>(m));
        queue<pair<int, int>> Q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '1')
                    Q.push({i, j});
        db("Start2");
        int cnt = 0;
        while (!Q.empty())
        {
            auto top = Q.front();
            Q.pop();
            int x = top.f, y = top.s;
            if (vis[x][y])
                continue;
            db(x, y);
            cnt++;
            queue<pair<int, int>> Q2;
            Q2.push(top);
            while (!Q2.empty())
            {
                auto top2 = Q2.front();
                Q2.pop();
                int x1 = top2.f, y1 = top2.s;
                if (vis[x1][y1])
                    continue;
                db("a", x1, y1);
                vis[x1][y1] = true;
                for (int i = 0; i < 4; i++)
                {
                    int x2 = x1 + a[i], y2 = y1 + b[i];
                    if (isValid(x2, y2, n, m) && !vis[x2][y2] && grid[x2][y2] == '1')
                    {
                        db(x2, y2);
                        Q2.push({x2, y2});
                    }
                }
            }
        }
        return cnt;
    }
};

#ifdef LOCAL
int main()
{
    Solution s;
    int n, m;
    cin >> n >> m;
    vector<vector<char>> input(n);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            input[i].pb(ch);
        }
    }
    cout << s.numIslands(input) << '\n';
}
#endif
