#ifdef WIN32
#include <bits/stdc++.h>
using namespace std;
#endif
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

int a[] = {1, 2, 2, 1, -1, -2, -2, -1};
int b[] = {2, 1, -1, -2, -2, -1, 1, 2};

class Solution
{
public:
    int solve(int x, int y)
    {
        vector<vector<int>> Dist(1000, vector<int>(1000, INT_MAX));
        // vector<vector<bool>> Vis(1000, vector<bool>(1000, false));
        x += 500;
        y += 500;
        Dist[500][500] = 0;
        queue<pair<int, int>> Q;
        Q.push({500, 500});
        while (!Q.empty())
        {
            auto top = Q.front();
            Q.pop();
            if (top.f == x && top.s == y)
                return Dist[x][y];
            int dist = Dist[top.f][top.s];
            for (int i = 0; i < 8; ++i)
            {
                auto x1 = top.f + a[i];
                auto y1 = top.s + b[i];
                if (x1 < 0 || x1 >= 1000)
                    continue;
                if (y1 < 0 || y1 >= 1000)
                    continue;
                if (Dist[x1][y1] > dist + 1)
                {
                    Dist[x1][y1] = dist + 1;
                    Q.push({x1, y1});
                }
            }
        }
        return 0;
    }
    int minKnightMoves(int x, int y)
    {
        return solve(x, y);
    }
};

#ifdef WIN32
int main()
{
    Solution s;
    cout << s.minKnightMoves(114, -179);
}
#endif