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

#define pb push_back
#define f first
#define s second

using flowUnit = long long;
struct Edge
{
    int from, to;
    flowUnit cap, flow;
    int index;
    Edge(int from, int to, flowUnit cap, flowUnit flow, int index) : from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushReLabel
{
    int n;
    vector<vector<Edge>> g;
    vector<flowUnit> excess;
    vector<int> height, active, count;
    queue<int> Q;

    PushReLabel(int n) : n(n), g(n), excess(n), height(n), active(n), count(2 * n) {}

    void addEdge(int from, int to, flowUnit cap)
    {
        g[from].pb(Edge(from, to, cap, 0, g[to].size()));
        if (from == to)
            g[from].back().index++;
        g[to].pb(Edge(to, from, 0, 0, g[from].size() - 1));
    }

    void enqueue(int node)
    {
        if (!active[node] && excess[node] > 0)
        {
            active[node] = 0;
            Q.push(node);
        }
    }

    void push(Edge &e)
    {
        flowUnit amt = min(excess[e.from], e.cap - e.flow);
        if (height[e.from] <= height[e.to] || amt == 0)
            return;
        e.flow += amt;
        g[e.to][e.index].flow -= amt;
        excess[e.to] += amt;
        excess[e.from] -= amt;
        enqueue(e.to);
    }

    void relabel(int node)
    {
        count[height[node]]--;
        int d = 2 * n;
        for (auto &it : g[node])
            if (it.cap - it.flow > 0)
                d = min(d, height[it.to] + 1);
        height[node] = d;
        count[height[node]]++;
        enqueue(node);
    }

    void gap(int k)
    {
        for (int node = 0; node < n; node++)
        {
            if (height[node] < k)
                continue;
            count[height[node]]--;
            height[node] = max(height[node], n + 1);
            count[height[node]]++;
            enqueue(node);
        }
    }

    void discharge(int node)
    {
        for (size_t i = 0; excess[node] > 0 && i < g[node].size(); i++)
            push(g[node][i]);
        if (excess[node] > 0)
        {
            if (count[height[node]] == 1)
                gap(height[node]);
            else
                relabel(node);
        }
    }

    flowUnit max_flow(int source, int dest)
    {
        count[0] = n - 1;
        count[n] = 1;
        height[source] = n;
        active[source] = active[dest] = 1;
        for (auto &it : g[source])
        {
            excess[source] += it.cap;
            push(it);
        }
        while (Q.size())
        {
            auto node = Q.front();
            Q.pop();
            active[node] = false;
            discharge(node);
        }
        flowUnit max_flow = 0;
        for (auto &it : g[source])
            max_flow += it.flow;
        return max_flow;
    }
};

void solveCase()
{
    int n;
    cin >> n;
    vector<pair<int, int>> red(n), blue(n);
    for (size_t i = 0; i < n; i++)
        cin >> red[i].first >> red[i].second;
    for (size_t i = 0; i < n; i++)
        cin >> blue[i].first >> blue[i].second;
    int res = 0;
    vector<vector<int>> adj(2 * n);
    PushReLabel p(2 * n + 2);
    for (size_t i = 0; i < n; i++)
    {
        p.addEdge(0, i + 1, 1);
        p.addEdge(n + i + 1, 2 * n + 1, 1);
        int x = red[i].first, y = red[i].second;
        // cin >> x >> y;
        for (size_t j = 0; j < n; j++)
        {
            auto &a = blue[j];
            if (x < a.first && y < a.second)
            {
                // adj[i].pb(j + n);
                // adj[j + n].pb(i);
                p.addEdge(i + 1, j + n + 1, 1);
            }
        }
    }
    cout << p.max_flow(0, 2 * n + 1) << '\n';
    // cout << res << '\n';
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