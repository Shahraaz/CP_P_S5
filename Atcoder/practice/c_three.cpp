// Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define MULTI_TEST
#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#define pc(...)
#endif

#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()
auto TimeStart = chrono::steady_clock::now();
auto seed = TimeStart.time_since_epoch().count();
std::mt19937 rng(seed);
using ll = long long;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using Random = std::uniform_int_distribution<T>;

const int NAX = 2e5 + 5, MOD = 1000000007;

vector<int> adj[NAX];
deque<int> mod[3];
vector<int> listOfNodes[2];
int original[NAX];
int color[NAX];

class Solution
{
private:
    void dfs(int node, int par)
    {
        listOfNodes[color[node]].pb(node);
        for (auto &chils : adj[node])
            if (chils != par)
            {
                color[chils] = 1 - color[node];
                dfs(chils, node);
            }
    }

public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int n;
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            --u, --v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(0, 0);
        for (size_t i = 1; i <= n; i++)
            mod[i % 3].pb(i);
        if (listOfNodes[0].size() > listOfNodes[1].size())
            listOfNodes[0].swap(listOfNodes[1]);
        if (listOfNodes[0].size() <= n / 3)
        {
            db("a");
            while (listOfNodes[0].size())
            {
                int x = listOfNodes[0].back();
                listOfNodes[0].pop_back();
                int clr = mod[0].back();
                mod[0].pop_back();
                original[x] = clr;
            }
            while (listOfNodes[1].size())
            {
                int x = listOfNodes[1].back();
                listOfNodes[1].pop_back();
                for (size_t i = 0; i < 3; i++)
                {
                    if (mod[i].size())
                    {
                        int clr = mod[i].back();
                        mod[i].pop_back();
                        original[x] = clr;
                        break;
                    }
                }
            }
        }
        else
        {
            db("b");
            pc(mod[0], mod[1], mod[2]);
            pc(listOfNodes[0], listOfNodes[1]);
            while (mod[1].size())
            {
                auto clr = mod[1].front();
                mod[1].pop_front();
                int node = listOfNodes[0].back();
                listOfNodes[0].pop_back();
                original[node] = clr;
            }
            while (mod[2].size())
            {
                auto clr = mod[2].front();
                mod[2].pop_front();
                int node = listOfNodes[1].back();
                listOfNodes[1].pop_back();
                original[node] = clr;
            }
            for (size_t i = 0; i < 2; i++)
                while (listOfNodes[i].size())
                {
                    auto clr = mod[0].front();
                    mod[0].pop_front();
                    int node = listOfNodes[i].back();
                    listOfNodes[i].pop_back();
                    original[node] = clr;
                }
        }
        for (int i = 0; i < n; i++)
            cout << original[i] << ' ';
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}