//Optimise
#include <bits/stdc++.h>
using namespace std;

#define multitest 1
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
auto TimeStart = chrono::steady_clock::now();

const int nax = 2e5 + 10;

void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> Adj(n + 1), indegree(n + 1);
    int u, v;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        Adj[u].pb(v);
        indegree[v]++;
    }
    vector<int> Oddways(n + 1), Evenways(n + 1);
    queue<int> Q;
    for (int i = 1; i <= n; ++i)
        if (!indegree[i])
            Q.push(i);
    Oddways[x] = 1;
    while (!Q.empty())
    {
        auto top = Q.front();
        Q.pop();
        for (int child : Adj[top])
        {
            Oddways[child] += Evenways[top];
            Evenways[child] += Oddways[top];
            Oddways[child] %= mod;
            Evenways[child] %= mod;
            indegree[child]--;
            if (!indegree[child])
                Q.push(child);
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << Evenways[i] << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
#ifdef multitest
    cin >> t;
#endif
    while (t--)
        solve();
#ifdef TIME
    cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
    return 0;
}