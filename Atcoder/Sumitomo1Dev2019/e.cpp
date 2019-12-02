//Optimise
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
auto TimeStart = chrono::steady_clock::now();

const int NAX = 2e5 + 10, MOD = 1000000007;
vector<int> adj[NAX];

void solveCase(int caseNo)
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, vector<int>> m;
    m[-1].pb(0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        m[a[i]].pb(i);
    }
    vector<int> degree(n + 1);
    for (int i = 0; i <= n; ++i)
    {
        for (auto elem : m[i])
            for (auto elem2 : m[i - 1])
            {
                if (elem2 < elem)
                {
                    // db("here");
                    degree[elem2]++;
                    adj[elem].pb(elem2);
                }
            }
    }
    vector<int> dp(n + 1);
    queue<int> Q;
    int cnt = 3;
    pc(degree);
    for (int i = n; i >= 0; --i)
    {
        // db(i,degree[i]);
        if (degree[i] == 0)
        {
            Q.push(i);
            dp[i] = cnt--;
            if(cnt < 0)
                cnt = 0;
        }
    }
    while (!Q.empty())
    {
        auto top = Q.front();
        Q.pop();
        // db(top, dp[top]);
        for (auto child : adj[top])
        {
            dp[child] += dp[top];
            dp[child] %= MOD;
            // db(child, dp[child]);
            degree[child]--;
            if (degree[child] == 0)
                Q.push(child);
        }
    }
    pc(dp);
    cout << dp[0] << '\n';
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