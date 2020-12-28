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
const int NAX = 2e5 + 5, MOD = 1000000007;

const int K = 2;

struct Vertex
{
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p = -1, char ch = '$') : p(p), pch(ch)
    {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string &s)
{
    assert(s.size());
    int v = 0;
    for (auto &ch : s)
    {
        int c = ch - '0';
        if (t[v].next[c] == -1)
        {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
}

int go(int v, char ch);

int get_link(int v)
{
    // db("getlink", v, t[v].p, t[v].pch);
    if (t[v].link == -1)
    {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
        // db(v, t[v].link);
    }
    return t[v].link;
}

int go(int v, char ch)
{
    // db("go", v, ch);
    int c = ch - '0';
    if (t[v].go[c] == -1)
    {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
        // db(v, ch, t[v].go[c]);
    }
    return t[v].go[c];
}

void solveCase()
{
    int n;
    string pattern;
    cin >> n >> pattern;
    vector<string> all_patterns;
    all_patterns = {pattern};
    for (size_t i = 0; i < pattern.size(); i++)
    {
        auto x = pattern[i];
        if (x == '*')
        {
            int n = all_patterns.size();
            for (size_t j = 0; j < n; j++)
            {
                all_patterns[j][i] = '0';
                all_patterns.pb(all_patterns[j]);
                all_patterns.back()[i] = '1';
            }
        }
    }
    db(all_patterns);
    for (auto &x : all_patterns)
        add_string(x);
    db("ok");
    vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(t.size(), vector<ll>(2)));
    auto now = 0;
    auto nnext = 1;
    {
        auto next = go(0, '0');
        dp[now][next][t[next].leaf] += 1;
    }
    {
        auto next = go(0, '1');
        dp[now][next][t[next].leaf] += 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < t.size(); j++)
            for (int z = 0; z <= 1; z++)
                dp[nnext][j][z] = 0;
        for (int j = 0; j < t.size(); j++)
        {
            for (int z = 0; z <= 1; z++)
            {
                int next = go(j, '0');
                dp[nnext][next][z || t[next].leaf] += dp[now][j][z];
                next = go(j, '1');
                dp[nnext][next][z || t[next].leaf] += dp[now][j][z];
            }
        }
        swap(now, nnext);
    }
    ll res = 0;
    for (int j = 0; j < t.size(); j++)
        res += dp[nnext][j][1];
    cout << res << '\n';
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