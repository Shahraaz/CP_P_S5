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
const int NAX = 4e5 + 5, MOD = 1000000007;

int val[NAX], l[NAX], r[NAX], maxnode;
vector<int> ranges;

bool solve(int node, int a, int b)
{
    if (a == 0 && b == 0)
        return true;
    db(node, a, b);
    ranges.pb(node);
    maxnode = max(maxnode, node);
    l[node] = 2 * node;
    r[node] = 2 * node + 1;
    if (a == 0)
    {
        int cnt = __builtin_popcount(b + 1);
        if (cnt == 1)
        {
            // here 1 b
            val[node] = 2;
            --b;
            return solve(2 * node, a, b / 2) && solve(2 * node + 1, a, b - b / 2);
        }
        return false;
    }
    if (b == 0)
    {
        // 1 a
        --a;
        val[node] = 1;
        return solve(2 * node, a / 2, b) && solve(2 * node + 1, a - a / 2, b);
    }
    // here 1 b
    --b;
    val[node] = 2;
    if ((b & 1) && (a % 2 == 0))
    {
        return solve(2 * node, (a) / 2 + 1, b / 2) && solve(2 * node + 1, a - (a) / 2 - 1, b - b / 2);
    }
    return solve(2 * node, (a + 1) / 2, b / 2) && solve(2 * node + 1, a - (a + 1) / 2, b - b / 2);
}

void solveCase()
{
    int a, b;
    cin >> a >> b;
    // cout << solve(1, a, b) << '\n';
    if (!solve(1, a, b))
    {
        cout << "-1\n";
        return;
    }
    sort(all(ranges));
    vector<int> compress(maxnode + 1);
    db(maxnode);
    db(ranges);
    for (size_t i = 0; i < compress.size(); i++)
        compress[i] = lower_bound(all(ranges), i) - ranges.begin() + 1;
    db(compress);
    for (size_t i = 1; i <= maxnode; i++)
    {
        if (val[i])
        {
            // db(i, val[i], l[i], r[i]);
            cout << val[i] << ' ';
            if (val[l[i]] == 0)
                cout << 0 << ' ';
            else
                cout << compress[l[i]] << ' ';
            if (val[r[i]] == 0)
                cout << 0 << ' ';
            else
                cout << compress[r[i]] << ' ';
            cout << '\n';
        }
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