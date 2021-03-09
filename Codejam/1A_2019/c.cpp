#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

#define all(v) v.begin(), v.end()
#define pb push_back
using ll = long long;
const int NAX = 50 * 1000 + 5, MOD = 1000000007;

int t_trie[NAX][26], f[NAX], res, node_cnt;

void init()
{
    res = node_cnt = 0;
    node_cnt++;
    memset(t_trie, 0, sizeof t_trie);
    memset(f, 0, sizeof f);
}

void add(string str)
{
    int node = 0;
    for (auto &x : str)
    {
        int c = x - 'A';
        if (t_trie[node][c] == 0)
            t_trie[node][c] = node_cnt++;
        node = t_trie[node][c];
    }
    f[node]++;
}

int dfs(int node)
{
    for (size_t i = 0; i < 26; i++)
        if (t_trie[node][i] != 0)
            f[node] += dfs(t_trie[node][i]);
    db(node, f[node], res);
    if (f[node] >= 2 && node != 0)
    {
        res += 2;
        f[node] -= 2;
    }
    return f[node];
}

void solveCase()
{
    init();
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        reverse(all(str));
        add(str);
    }
    dfs(0);
    cout << res << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 100;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solveCase();
    }
    return 0;
}