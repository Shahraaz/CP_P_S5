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
using ld = long double;
class Solution
{
    map<string, vector<pair<string, ld>>> G;

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int n = equations.size();
        for (int i = 0; i < n; ++i)
        {
            G[equations[i][0]].pb({equations[i][1], values[i]});
            G[equations[i][1]].pb({equations[i][0], 1 / values[i]});
        }
        vector<double> ret;
        for (auto q : queries)
        {
            if (G[q[0]].size() == 0 || G[q[1]].size() == 0)
                ret.pb(-1);
            else
            {
                map<string, bool> vis;
                queue<pair<string, ld>> Q;
                Q.push({q[0], 1});
                vis[q[0]] = true;
                while (!Q.empty())
                {
                    auto top = Q.front();
                    if (top.f == q[1])
                    {
                        ret.pb(top.s);
                        break;
                    }
                    Q.pop();
                    for (auto elem : G[top.f])
                        if (!vis[elem.f])
                        {
                            vis[elem.f] = true;
                            Q.push({elem.f, elem.s * top.s});
                        }
                }
                if (vis[q[1]])
                {
                }
                else
                    ret.pb(-1);
            }
        }
        return ret;
    }
};
#ifdef WIN32
int main()
{
    Solution s;
    cout << s.fun();
}
#endif