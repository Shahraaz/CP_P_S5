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
    int k, n;
    cin >> n >> k;
    // vector<int> cnt(n);
    set<pair<int, int>> ss;
    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        // cnt[x]++;
        ss.insert({x, i});
    }
    ll res = 0;
    while (ss.size() && k)
    {
        auto curr = 0;
        db(ss, k);
        while (ss.size())
        {
            auto it = ss.lower_bound({curr, 0});
            if (it == ss.end() || it->first != curr)
                break;
            ss.erase(it);
            curr++;
        }
        k--;
        db(curr);
        res += curr;
        if (curr == 0)
            break;
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