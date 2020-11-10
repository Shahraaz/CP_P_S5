// Optimise
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()

const int NAX = 3e5 + 5, MOD = 1000000007;
using ld = long double;

vector<int> adj[NAX];
ld dp[NAX];
ld num[NAX];
int cntden[NAX];
bool isCalc[NAX];

const ld EPS = 1e-12;

bool equal(ld a, ld b)
{
    return abs(a - b) <= EPS;
}

void solveCase()
{
    int n, m;
    cin >> n >> m;
    fill(dp, dp + n, 1e18);
    for (size_t i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dp[n - 1] = 0;
    priority_queue<pair<ld, int>, vector<pair<ld, int>>, greater<pair<ld, int>>> Q;
    Q.push({0, n - 1});
    cerr << fixed << setprecision(10);
    while (!Q.empty())
    {
        auto top = Q.top();
        Q.pop();
        if (!equal(top.f, dp[top.s]))
            continue;
        if (isCalc[top.s])
            continue;
        db(top);
        isCalc[top.s] = 1;
        for (auto &child : adj[top.s])
        {
            if (isCalc[child])
                continue;
            num[child] += top.f;
            cntden[child]++;
            ld cost = adj[child].size() + num[child];
            cost /= cntden[child];
            dp[child] = cost;
            Q.push({cost, child});
        }
    }
    cout << fixed << setprecision(10);
    cout << dp[0] << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
