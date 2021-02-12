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
const int NAX = 1e5 + 1, MOD = 1000000007;
const int MAX = 3e5 + 1;

int n, m;
vector<string> dict(NAX), nvwl(NAX);
vector<int> total_len(NAX), consonant_len(NAX), nvwl_len(NAX);
string toform;
vector<int> dp(MAX, -1), curr_idx(MAX, -1), nice_name(MAX, false);
// vector<map<int, pair<int, int>>> states(MAX);
vector<vector<pair<int, int>>> states(MAX, vector<pair<int, int>>(450, {-1, -1}));
vector<int> lens;

bool isvovel(char c) { return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'; }

const int ALPHA = 26;

struct aho_corasick
{
    struct node
    {
        // map<int, int> nxt, go;
        vector<int> nxt, go;
        int p, pch;
        int suf, ssuf;
        vector<pair<int, int>> vals;
        bool term;

        node()
        {
            nxt.resize(ALPHA, -1);
            go.resize(ALPHA, -1);
            suf = ssuf = -1;
            term = false;
            // vals.resize(450, {-1, -1});
            p = -1, pch = -1;
        }
    };

    vector<node> nodes;

    aho_corasick()
    {
        nodes = vector<node>(1, node());
    }

    int add(const string &s, int idx)
    {
        // db("add", s, idx);
        int v = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            int c = s[i] - 'A';
            if (nodes[v].nxt[c] == -1)
            {
                nodes.push_back(node());
                nodes[v].nxt[c] = int(nodes.size()) - 1;
                nodes.back().p = v;
                nodes.back().pch = c;
            }
            v = nodes[v].nxt[c];
        }
        if (!nodes[v].term)
            nodes[v].vals.resize(450, {-1, -1});
        nodes[v].term = true;
        nodes[v].vals[nvwl_len[idx]] = max(nodes[v].vals[nvwl_len[idx]], {total_len[idx] - nvwl_len[idx], idx});
        // db(v, nodes[v].vals);
        return v;
    }

    void feed(const string &s)
    {
        int v = 0;
        // int ans = -1;
        for (size_t i = 0; i < s.size(); i++)
        {
            int c = s[i] - 'A';
            v = go(v, c);
            int u = v;
            db(i, c, v);
            // continue;
            if (!nice_name[u])
            {
                function<void(int)> nice_function = [&](int node) -> void {
                    if (node == 0 || nice_name[node])
                        return;
                    nice_name[node] = 1;
                    int next = ssuf(node);
                    nice_function(next);
                    int lim = min(nodes[node].vals.size(), nodes[next].vals.size());
                    for (size_t i = 0; i < lim; i++)
                        nodes[node].vals[i] = max(nodes[node].vals[i], nodes[next].vals[i]);
                };
                nice_function(u);
            }
            // db(u, nodes[u].vals);
            for (size_t j = 0; j < nodes[u].vals.size(); j++)
            {
                if (nodes[u].vals[j].second == -1)
                    continue;
                db(j, nodes[u].vals[j]);
                int totallen = lens[j];
                int vwlcnt = nodes[u].vals[j].first;
                int idx = nodes[u].vals[j].second;

                states[i - totallen + 1][j] = max(states[i - totallen + 1][j], {vwlcnt, idx});
                // assert(states[i - totallen + 1].size() <= 500);
            }
        }
    }
    // return ans;

    int go(int v, int c)
    {
        // db(v, c);
        if (nodes[v].go[c] != -1)
            return nodes[v].go[c];
        if (nodes[v].nxt[c] != -1)
            return nodes[v].go[c] = nodes[v].nxt[c];
        if (v == 0)
            return nodes[v].go[c] = 0;
        return nodes[v].go[c] = go(suf(v), c);
    }

    int suf(int v)
    {
        if (nodes[v].suf != -1)
            return nodes[v].suf;
        if (v == 0 || nodes[v].p == 0)
            return nodes[v].suf = 0;
        return nodes[v].suf = go(suf(nodes[v].p), nodes[v].pch);
    }

    int ssuf(int v)
    {
        if (nodes[v].ssuf != -1)
            return nodes[v].ssuf;
        if (v == 0 || nodes[v].p == 0)
            return nodes[v].ssuf = 0;
        int s = suf(v);
        if (nodes[s].term)
            return nodes[v].ssuf = s;
        return nodes[v].ssuf = ssuf(s);
    }
};

aho_corasick ac;

void solveCase()
{
    n = 440;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        dict[i] = string(i + 1, 'B');
        cin >> dict[i];
        total_len[i] = dict[i].size();
        for (auto &x : dict[i])
            if (!isvovel(x))
                nvwl[i] += x;
        nvwl_len[i] = nvwl[i].size();
        lens.pb(nvwl_len[i]);
        // db(i, dict[i], nvwl[i]);
        // auto idx = ac.add(nvwl[i], i);
        // ac.nodes[idx][total_len[i]] = max(ac.nodes[idx][total_len[i]], {total_len[i] - nvwl_len[i], i});
    }
    sort(all(lens));
    lens.erase(unique(all(lens)), lens.end());
    for (size_t i = 0; i < n; i++)
    {
        nvwl_len[i] = lower_bound(all(lens), nvwl_len[i]) - lens.begin();
        ac.add(nvwl[i], i);
    }
    db("Added");
    toform = string(3e5, 'B');
    cin >> toform;
    // ac.analysis();
    ac.feed(toform);
    // return;
    dp[toform.size()] = 0;
    for (int i = toform.size() - 1; i >= 0; i--)
    {
        db(i, states[i].size());
        dp[i] = -1;
        curr_idx[i] = -1;
        for (size_t j = 0; j < lens.size(); j++)
        {
            if (states[i][j].first == -1)
                continue;
            int totallen = lens[j];
            int vwlcnt = states[i][j].first;
            int idx = states[i][j].second;
            if (dp[i + totallen] != -1)
            {
                int cost = dp[i + totallen] + vwlcnt;
                if (dp[i] < cost)
                {
                    dp[i] = cost;
                    curr_idx[i] = idx;
                }
            }
        }

        db(i, dp[i], curr_idx[i]);
    }
    auto idx = 0;
    while (curr_idx[idx] != -1)
    {
        cout << dict[curr_idx[idx]] << ' ';
        idx += lens[nvwl_len[curr_idx[idx]]];
    }
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