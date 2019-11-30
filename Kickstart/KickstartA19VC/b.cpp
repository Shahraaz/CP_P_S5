//Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define MULTI_TEST
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
auto TimeStart = chrono::steady_clock::now();

const int NAX = 500 + 10, MOD = 1000000007;
int n, m;
bool mat[NAX][NAX];
int d[NAX][NAX];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs()
{
    int x, y;
    memset(d, -1, sizeof d);
    queue<pair<int, int>> Q;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (mat[i][j])
            {
                d[i][j] = 0;
                Q.push({i, j});
            }
    while (!Q.empty())
    {
        x = Q.front().f;
        y = Q.front().s;
        db(x, y, d[x][y]);
        Q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx <= 0 || nx > n || ny <= 0 || ny > m)
                continue;
            if (d[nx][ny] >= 0)
                continue;
            d[nx][ny] = d[x][y] + 1;
            Q.push({nx, ny});
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (d[i][j] == -1)
                d[i][j] = MOD;
}

bool check(int x)
{
    int plus_max, plus_min, minus_max, minus_min;
    plus_max = 3 * NAX, plus_min = -3 * NAX;
    minus_max = 3 * NAX, minus_min = -3 * NAX;
    bool ok = true;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (d[i][j] > x)
            {
                plus_max = min(plus_max, i + j + x);
                plus_min = max(plus_min, i + j - x);
                minus_max = min(minus_max, i - j + x);
                minus_min = max(minus_min, i - j - x);
                ok = false;
            }
    if (ok)
        return ok;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            int plus = i + j;
            int minus = i - j;
            if (plus_min <= plus && plus <= plus_max)
                if (minus_min <= minus && minus <= minus_max)
                    return true;
        }
    return false;
}

void solveCase(int caseNo)
{
    cout << "Case #" << caseNo + 1 << ": ";
    cin >> n >> m;
    string s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s;
        for (int j = 0; j < m; ++j)
            mat[i][j + 1] = s[j] == '1';
    }
    bfs();
    int low = 0, high = 3 * NAX;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (check(mid))
            high = mid;
        else
            low = mid + 1;
    }
    cout << high << '\n';
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
    for (int i = 0; i < t; ++i)
    {
        solveCase(i);
#ifdef TIME
        cerr << "# " << i << ' ' << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}