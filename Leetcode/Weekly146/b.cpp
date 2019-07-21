// #define Debug
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
class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges, vector<vector<int>> &blue_edges)
    {
        vector<vector<int>> redEdges(n), blueEdges(n);
        for (auto c : red_edges)
        {
            redEdges[c[0]].pb(c[1]);
        }
        for (auto c : blue_edges)
        {
            blueEdges[c[0]].pb(c[1]);
        }
        vector<int> Dist[2](n, -1);
        vector<bool> Vis(n, 0), Vis1(n, 0);
        Dist[0][0] = Dist[1][0] = 0;
        queue<pair<int, int>> Q;
        Q.push({0, 0});
        Q.push({0, 1});
        while (!Q.empty())
        {
            auto top = Q.front();
            if (top.s)
            {
                for (auto c : redEdges[top.f])
                    if (!Vis[c])
                    {
                        Vis[c] = true;
                        Q.push({c, 0});
                        Dist[1][c] = Dist[0][top.f] + 1;
                    }
            }
            else
            {
                for (auto c : blueEdges[top.f])
                    if (!Vis1[c])
                    {
                        Vis1[c] = true;
                        Q.push({c, 1});
                        Dist[0][c] = Dist[1][top.f] + 1;
                    }
            }
        }
        vector<int> ret;
        for (int i = 0; i < n; ++i)
        {
            if (Vis[i] || Vis1[i])
            {
                if (Vis[i] && Vis1[i])
                {
                    ret.pb(min(Dist[0][i], Dist[1][i]));
                }
                else
                {
                    if (Vis[i])
                        ret.pb(Dist[0][i]);
                    else
                        ret.pb(Dist[1][i]);
                }
            }
            else
                ret.pb(-1);
        }
        return ret;
    }
};