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
const int NAX = 1e5 + 5, MOD = 1000000007;
const int LG = __lg(NAX) + 1;

vector<int> adj[NAX];
vector<vector<int>> p(LG, vector<int>(NAX));
int n, m;
int ages[NAX];
vector<int> l_adj[NAX];

struct Bit
{
    int size;
    vector<int> table;
    Bit(int size)
    {
        this->size = size;
        table.resize(size);
    }
    void update(int i, int delta)
    {
        while (i < size)
        {
            table[i] += delta;
            i = i | (1 + i);
        }
    }
    int sum(int i)
    {
        int ret = 0;
        while (i >= 0)
        {
            ret += table[i];
            i = (i & (i + 1)) - 1;
        }
        return ret;
    }
    int rangeSum(int i, int j)
    {
        if (i == 0)
            return sum(j);
        return sum(j) - sum(i - 1);
    }
    void print()
    {
#ifdef LOCAL
        for (int i = 0; i < size; i++)
            cout << rangeSum(i, i) << ' ';
        cout << '\n';
#else

#endif
    }
};

void solveCase()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int age, p;
        cin >> age >> p;
        ::p[0][i] = p;
        if (i != p)
            adj[p].pb(i);
        ages[i] = age;
    }
    for (size_t i = 1; i < LG; i++)
        for (size_t j = 1; j <= n; j++)
            p[i][j] = p[i - 1][p[i - 1][j]];
    for (size_t i = 0; i < m; i++)
    {
        int o, l, r;
        cin >> o >> l >> r;
        int par = o;
        for (int i = LG - 1; i >= 0; i--)
            if (ages[p[i][par]] <= r)
                par = p[i][par];
        db(o, l, r, par);
        l_adj[par].pb(l);
    }
    Bit b(NAX);
    vector<int> res(n + 1);
    function<void(int)> dfs = [&](int top) {
        for (auto &l : l_adj[top])
            b.update(l, 1);
        b.print();
        db(top, ages[top]);
        res[top] = b.rangeSum(0, ages[top]);
        for (auto &child : adj[top])
        {
            if (child == p[0][top])
                continue;
            dfs(child);
        }
        for (auto &l : l_adj[top])
            b.update(l, -1);
    };
    dfs(1);
    for (size_t j = 1; j <= n; j++)
        cout << res[j] << ' ';
    cout << '\n';
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
        solveCase();
    return 0;
}