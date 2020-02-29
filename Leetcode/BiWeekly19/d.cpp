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
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> adj[n];
        map<int, vector<int>> imp;
        for (int i = 0; i < n; ++i)
            imp[arr[i]].pb(i);
        for (int i = 0; i < (n - 1); ++i)
            adj[i].pb(i + 1);
        for (int i = 1; i < (n); ++i)
            adj[i].pb(i - 1);
        vector<bool> vis(n);
        vector<int> dist(n, MOD);
        queue<int> Q;
        set<int> visSecond;
        Q.push(0);
        vis[0] = true;
        dist[0] = 0;
        while (!Q.empty())
        {
            auto top = Q.front();
            db(top);
            Q.pop();
            for (auto &child : adj[top])
                if (!vis[child])
                {
                    dist[child] = dist[top] + 1;
                    vis[child] = true;
                    Q.push(child);
                }
            if (visSecond.count(arr[top]) == 0)
            {
                visSecond.insert(arr[top]);
                for (auto &child : imp[arr[top]])
                    if (!vis[child])
                    {
                        dist[child] = dist[top] + 1;
                        vis[child] = true;
                        Q.push(child);
                    }
            }
        }
        return dist[n - 1];
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto &x : arr)
            cin >> x;
        cout << S.minJumps(arr) << '\n';
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif