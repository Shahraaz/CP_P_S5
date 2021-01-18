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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int res = MOD;
    auto check_if_removable = [&](int idx) -> bool {
        int lptr = idx, rptr = idx;
        while (rptr < n && a[rptr] >= a[idx])
            ++rptr;
        while (lptr >= 0 && a[lptr] >= a[idx])
            --lptr;
        db(lptr, idx, rptr);
        return (rptr - lptr - 1) >= k;
    };
    db(a);
    for (size_t i = 0; i < n; i++)
    {
        if (check_if_removable(i))
        {
            vector<deque<int>> dQ;
            deque<int> D;
            db(i);
            for (size_t j = 0; j < n; j++)
                if (i != j)
                {
                    db(j, D);
                    if (a[j] >= a[i])
                        D.pb(a[j]);
                    else if (D.size())
                    {
                        sort(all(D));
                        dQ.pb(D);
                        D.clear();
                    }
                }
            if (D.size())
            {
                sort(all(D));
                dQ.pb(D);
                D.clear();
            }
            db(dQ);
            bool ok = true;
            int maxi = a[i], mini = a[i];
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
            for (size_t z = 0; z < dQ.size(); z++)
                if (dQ[z].size() >= k)
                    Q.push({dQ[z][0], z});
            for (size_t j = 1; ok && j < q; j++)
            {
                int idx = -1;
                if (Q.size())
                {
                    auto top = Q.top();
                    Q.pop();
                    idx = top.second;
                    maxi = max(maxi, top.first);
                    dQ[idx].pop_front();
                    if (dQ[idx].size() >= k)
                        Q.push({dQ[idx][0], idx});
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                res = min(res, maxi - mini);
        }
    }
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