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

class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges, vector<vector<int>> &blue_edges)
    {
        vector<vector<int>> adjBlue(n), adjRed(n);
        for (auto &edge : red_edges)
            adjRed[edge[0]].pb(edge[1]);
        for (auto &edge : blue_edges)
            adjBlue[edge[0]].pb(edge[1]);
        vector<int> retRed(n, MOD);
        vector<int> retBlue(n, MOD);
        vector<bool> visRed(n, 0);
        vector<bool> visBlue(n, 0);
        queue<pair<int, int>> Q;
        const bool RED = 0, BLUE = 1;
        Q.push({0, RED});
        Q.push({0, BLUE});
        retRed[0] = 0;
        retBlue[0] = 0;
        visRed[0] = visBlue[0] = true;
        while (!Q.empty())
        {
            auto top = Q.front();
            Q.pop();
            // cout << top.f << ' ' << top.s << '\n';
            if (top.s == RED)
            {
                for (auto &child : adjRed[top.f])
                    if (retBlue[child] > retRed[top.f] + 1)
                    {
                        retBlue[child] = retRed[top.f] + 1;
                        if (!visRed[child])
                        {
                            visRed[child] = true;
                            Q.push({child, BLUE});
                        }
                    }
            }
            else
            {
                for (auto &child : adjBlue[top.f])
                    if (retRed[child] > retBlue[top.f] + 1)
                    {
                        retRed[child] = retBlue[top.f] + 1;
                        if (!visBlue[child])
                        {
                            visBlue[child] = true;
                            Q.push({child, RED});
                        }
                    }
            }
        }
        vector<int> ret(n);
        for (int i = 0; i < n; i++)
        {
            if (min(retRed[i], retBlue[i]) >= MOD)
                ret[i] = -1;
            else
                ret[i] = min(retRed[i], retBlue[i]);
        }
        return ret;
    }
};

#ifdef LOCAL
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    Solution S;
    for (int i = 1; i <= t; ++i)
    {
        ;
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif