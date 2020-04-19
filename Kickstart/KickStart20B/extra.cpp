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

const int NAX = 300 + 5, MOD = 1000000007;

double prob[NAX][NAX];
int vis[NAX][NAX];
class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        db("\n");
        int w, h, l, u, r, d;
        cin >> w >> h >> l >> u >> r >> d;
        db(w, h, l, u, r, d);
        memset(vis, 0, sizeof vis);
        memset(prob, 0, sizeof prob);
        prob[1][1] = 1;
        auto check = [&](int x, int y) {
            return 1 <= x && x <= w && 1 <= y && y <= h;
        };
        auto checkInHole = [&](int x, int y) {
            return l <= x && x <= r && u <= y && y <= d;
        };
        queue<pair<int, int>> Q;
        Q.push({1, 1});
        while (Q.size())
        {
            auto top = Q.front();
            Q.pop();
            if (vis[top.f][top.s])
                continue;
            if (checkInHole(top.f, top.s))
            {
                // prob[top.f][top.s] = 0;
                // continue;
            }
            db(top, prob[top.f][top.s]);
            vis[top.f][top.s] = true;
            int cnt = check(top.f + 1, top.s);
            cnt += check(top.f, top.s + 1);
            if (check(top.f + 1, top.s))
            {
                prob[top.f + 1][top.s] += prob[top.f][top.s] / cnt;
                Q.push({top.f + 1, top.s});
            }
            if (check(top.f, top.s + 1))
            {
                prob[top.f][top.s + 1] += prob[top.f][top.s] / cnt;
                Q.push({top.f, top.s + 1});
            }
        }
        cout << fixed << setprecision(9);
#ifdef LOCAL
        for (size_t i = 1; i <= w; i++)
        {
            for (size_t j = 1; j <= h; j++)
                cout << prob[i][j] << ' ';
            cout << '\n';
        }
#else

#endif
        double curr = 0;
        if (check(l, d + 1))
        {
            curr += prob[l][d + 1];
            curr -= prob[l][d];
        }
        if (check(r + 1, u))
        {
            curr += prob[r + 1][u];
            curr -= prob[r][u];
        }
        cout << prob[w][h] << '\n';
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