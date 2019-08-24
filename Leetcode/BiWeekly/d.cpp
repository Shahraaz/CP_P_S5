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

class Solution
{
    vector<int> Parent, rank;
    int find(int u)
    {
        return u == Parent[u] ? u : (Parent[u] = find(Parent[u]));
    }
    bool Union(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (rank[u] > rank[v])
            Parent[v] = u;
        else
        {
            Parent[u] = v;
            rank[v] += rank[v] == rank[u];
        }
        return true;
    }

public:
    int minCostToSupplyWater(int n, vector<int> &wells, vector<vector<int>> &pipes)
    {
        vector<vector<int>> V;
        Parent.pb(0);
        rank.pb(0);
        for (int i = 1; i <= n; ++i)
        {
            Parent.pb(i);
            rank.pb(0);
            V.pb({wells[i - 1], 0, i});
        }
        for (auto p : pipes)
            V.pb({p[2], p[0], p[1]});
        sort(V.begin(), V.end());
        ll ret = 0;
        for (int i = 0; i < V.size(); ++i)
            if (Union(V[i][1], V[i][2]))
                ret += V[i][0];
        return ret;
    }
};