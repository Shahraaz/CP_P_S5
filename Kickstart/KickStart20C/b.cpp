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

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int n, m;
        cin >> n >> m;
        vector<string> vec(n);
        vector<bool> vis(26);
        vector<int> depth(26, -1);
        vector<int> inde(26, -1);
        vector<int> oude(26, -1);
        for (auto &x : vec)
            cin >> x;
        set<int> adj[26];
        for (int i = n - 2; i >= 0; i--)
            for (size_t j = 0; j < m; j++)
                adj[vec[i + 1][j] - 'A'].insert(vec[i][j] - 'A');
        for (size_t i = 0; i < 26; i++)
        {
            if (adj[i].size())
                db(i, adj[i]);
            for (auto &x : adj[i])
                if (i != x)
                    inde[x]++, oude[i]++;
        }
        queue<int> Q;
        for (size_t i = 0; i < 26; i++)
            if (inde[x] && !oude[i])
            {
                vis[x] = true;
                Q.push(x);
            }
        while (Q.size())
        {
            auto node = Q.front();
            Q.pop();
            for (auto &x : child[node])
            {
                inde[x]--;
                if (inde[x] == 0)
                {
                    if (vis[x])
                    {
                        cout << -1 << '\n';
                        return;
                    }
                    vis[x] = true;
                    Q.push(x);
                }
            }
        }
        for (size_t i = 0; i < 26; i++)
            if (!vis[i] && adj[i].size())
            {
                cout << -1 << '\n';
                return;
            }
        vector<pair<int, int>> res;
        for (size_t i = 0; i < 26; i++)
            if (depth[i] > 0 && adj[i].size())
                res.pb({depth[i], i});
        sort(all(res));
        db(res);
        for (auto &x : res)
            cout << x.s + 'A';
        cout << '\n';
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    cin >> t;
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
