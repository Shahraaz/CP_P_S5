#ifdef LOCAL
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

const int NAX = 2e5 + 10;

class Solution
{
    vector<int> adj[NAX];
    int values[NAX];
    pair<int, int> dfs(int node, int par = -1)
    {
        int sum = values[node], cnt = 1;
        for (auto child : adj[node])
            if (child != par)
            {
                auto temp = dfs(child, node);
                sum += temp.f;
                cnt += temp.s;
            }
        if (sum == 0)
            cnt = 0;
        return make_pair(sum, cnt);
    }

public:
    int deleteTreeNodes(int nodes, vector<int> &parent, vector<int> &value)
    {
        int root;
        for (int i = 0; i < nodes; ++i)
        {
            if (parent[i] >= 0)
            {
                adj[i].pb(parent[i]);
                adj[parent[i]].pb(i);
            }
            else
                root = i;
            values[i] = value[i];
        }
        auto ret = dfs(root);
        return ret.s;
    }
};
#ifdef LOCAL
int main()
{
    Solution s;
}
#endif