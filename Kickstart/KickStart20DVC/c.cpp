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

const int NAX = 2e5 + 5, MOD = 1000000007;
vector<int> adj[NAX];
int a_child[NAX];
int b_child[NAX];
using ld = long double;
ld res;
int n;
ll a, b;

deque<int> st;
void dfs(int node)
{
    a_child[node]++;
    b_child[node]++;
    st.push_front(node);
    for (auto &child : adj[node])
        dfs(child);
    ld pa = a_child[node] / (ld)n;
    ld pb = b_child[node] / (ld)n;
    db(node, a_child[node], b_child[node]);
    res += pa * (1 - pb);
    res += pb * (1 - pa);
    res += pa * pb;
    if (st.size() > a)
        a_child[st[a]] += a_child[node];
    if (st.size() > b)
        b_child[st[b]] += b_child[node];
    st.pop_front();
};

void solveCase()
{
    cin >> n >> a >> b;
    for (size_t i = 0; i < n; i++)
    {
        adj[i].clear();
        a_child[i] = b_child[i] = 0;
    }
    for (size_t i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        --p;
        adj[p].pb(i);
    }
    res = 0;
    dfs(0);
    cout << fixed << setprecision(9);
    cout << res << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
