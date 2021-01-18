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
#define int ll

const int NAX = 2e5 + 5, MOD = 1000000007;

struct cmp
{
    bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
    {
        if (a.first.second != b.first.second)
            return a.first.second > b.first.second;
        return a.second < b.second;
    };
};

void solveCase()
{
    int n, p, q, s;
    cin >> n >> p >> q >> s;
    vector<int> x(p);
    vector<int> y(q);
    for (auto &a : x)
        cin >> a;
    for (auto &a : y)
        cin >> a;
    sort(all(x));
    sort(all(y));

    auto solve = [&](int maxd) -> int {
        db("\n\n", maxd, x, y);
        int lptr = 0, rptr = 0, ret = 0;
        vector<pair<pair<int, int>, int>> vecc;
        for (size_t i = 0; i < x.size(); i++)
        {
            lptr = lower_bound(all(y), x[i] - maxd) - y.begin();
            rptr = upper_bound(all(y), min(s - x[i], x[i] + maxd)) - y.begin();
            if (lptr < rptr)
                vecc.pb({{lptr, rptr - 1}, i});
        }
        sort(all(vecc));
        db(vecc);
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, cmp> Q;
        int head = 0;
        for (size_t i = 0; i < q; i++)
        {
            while (head < vecc.size() && vecc[head].first.first <= i)
            {
                Q.push(vecc[head]);
                head++;
            }

            if (Q.size())
            {
                auto Q1 = Q;
                while (Q1.size())
                {
                    db(Q1.top());
                    Q1.pop();
                }
            }

            while (Q.size())
            {
                auto top = Q.top();
                Q.pop();
                db(i, top, ret);
                if (top.first.second < i)
                    continue;
                ret++;
                break;
            }
        }
        db(maxd, ret);
        return ret;
    };

    db(n, p, q, s);
    int low = 0, right = 2 * MOD, ans = 2 * MOD;
    while (low <= right)
    {
        db(low, right);
        int mid = (low + right) / 2;
        if (solve(mid) >= n)
        {
            ans = min(ans, mid);
            right = mid - 1;
        }
        else
            low = mid + 1;
    }

    if (ans == 2 * MOD)
        ans = -1;

    cout << ans << '\n';
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
