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

void solveCase()
{
    int n;
    cin >> n;
    vector<vector<int>> xyar(n, vector<int>(4));
    for (auto &x : xyar)
        for (auto &y : x)
            cin >> y;
    vector<vector<int>> adj(n);
    vector<int> indegree(n), vis(n);
    using ld = long double;
    ld PI = acosl(-1), EPS = 1e-12;
    queue<int> Q;
    for (size_t i = 0; i < n; i++)
    {
        ld FACE_ANGLE = xyar[i][2] * PI / 180;
        const ld LIM_RANGE = xyar[i][3] * PI / 180;
        if (FACE_ANGLE < 0)
            FACE_ANGLE += 2 * PI;

        db(i, FACE_ANGLE, LIM_RANGE);
        for (size_t j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            int num = xyar[j][1] - xyar[i][1];
            int den = xyar[j][0] - xyar[i][0];
            ld ang = atan2l(num, den);

            if (ang < 0)
                ang += 2 * PI;

            db(i, j, ang);
            bool in = false;
            for (auto a : {FACE_ANGLE - 2 * PI, FACE_ANGLE, FACE_ANGLE + 2 * PI})
                for (auto b : {ang - 2 * PI, ang, ang + 2 * PI})
                    if (abs(a - b) <= LIM_RANGE + EPS)
                        in = true;
            if (in)
            {
                adj[i].pb(j);
                indegree[j]++;
            }
        }
        db(i, adj[i]);
    }
    for (size_t i = 0; i < n; i++)
        if (indegree[i] == 0)
        {
            Q.push(i);
            vis[i] = true;
        }
    vector<int> order_res;
    while (Q.size())
    {
        auto top = Q.front();
        Q.pop();
        order_res.pb(top);
        for (auto &x : adj[top])
        {
            if (vis[x])
            {
                cout << -1 << '\n';
                return;
            }
            indegree[x]--;
            if (indegree[x] == 0)
            {
                vis[x] = 1;
                Q.push(x);
            }
        }
    }
    if (order_res.size() != n)
    {
        cout << -1 << '\n';
        return;
    }
    for (auto &x : order_res)
        cout << x + 1 << ' ';
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