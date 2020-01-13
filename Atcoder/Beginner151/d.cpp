// Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define MULTI_TEST
#ifdef LOCAL
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
    while (*name == ',' || *name == ' ')
        name++;
    std::cerr << name << " { ";
    for (const auto &v : arg)
        cerr << v << ' ';
    cerr << " }\n";
}
template <typename Arg1, typename... Args>
void PC(const char *names, Arg1 &&arg1, Args &&... args)
{
    while (*names == ',' || *names == ' ')
        names++;
    const char *comma = strchr(names, ',');
    std::cerr.write(names, comma - names) << " { ";
    for (const auto &v : arg1)
        cerr << v << ' ';
    cerr << " }\n";
    PC(comma, args...);
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
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()
auto TimeStart = chrono::steady_clock::now();
auto seed = TimeStart.time_since_epoch().count();
std::mt19937 rng(seed);
template <typename T>
using Random = std::uniform_int_distribution<T>;

const int NAX = 2e5 + 5, MOD = 1000000007;

bool valid(int x, int y, int a, int b)
{
    return 0 <= x && x < a && 0 <= y && y < b;
}
int a[4] = {0, 0, 1, -1};
int b[4] = {1, -1, 0, 0};

void solveCase(int caseNo)
{
    int h, w;
    cin >> h >> w;
    vector<string> maze(h);
    for (auto &elem : maze)
        cin >> elem;
    int res = 1;
    // pc(maze);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (maze[i][j] == '#')
                continue;
            vector<vector<int>> dist(h, vector<int>(w, MOD));
            vector<vector<bool>> vis(h, vector<bool>(w, 0));
            queue<pair<int, int>> Q;
            Q.push({i, j});
            vis[i][j] = true;
            dist[i][j] = 0;
            while (!Q.empty())
            {
                auto top = Q.front();
                Q.pop();
                db(i, j, top);
                res = max(res, dist[top.f][top.s]);
                for (int k = 0; k < 4; k++)
                {
                    int x = top.f + a[k];
                    int y = top.s + b[k];
                    if (valid(x, y, h, w) && maze[x][y] == '.')
                    {
                        if (dist[x][y] > dist[top.f][top.s] + 1)
                        {
                            dist[x][y] = dist[top.f][top.s] + 1;
                            if (!vis[x][y])
                            {
                                vis[x][y] = true;
                                Q.push({x, y});
                            }
                        }
                    }
                }
            }
        }
    }
    cout << res << '\n';
}

int main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    for (int i = 1; i <= t; ++i)
    {
        solveCase(i);
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
