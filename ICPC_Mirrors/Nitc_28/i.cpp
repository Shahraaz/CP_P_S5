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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

char mapc[5100][5100];

char ask(int even, int odd)
{
    if (mapc[even][odd])
        return mapc[even][odd];
    cout << "? " << even << ' ' << odd << endl;
    char c;
    cin >> c;
    return mapc[even][odd] = c;
}

pair<vector<int>, vector<int>> try_divide_group(vector<int> &odd, int even)
{
    pair<vector<int>, vector<int>> ans;
    for (auto o : odd)
    {
        ask(even, o);
        if (ask(even, o) == '<')
            ans.second.push_back(o);
        else
            ans.first.push_back(o);
    }

    return ans;
}

void solveCase()
{
    int n;
    cin >> n;
    vector<pair<int, int>> O, E;
    if (n == 2)
    {
        cout << "! 2 1" << endl;
        return;
    }
    vector<int> ans(n + 1, 0);
    ordered_set<int> evens;
    for (size_t i = 2; i <= n; i += 2)
        evens.insert(i / 2);
    vector<vector<int>> groups(1, vector<int>());
    for (size_t i = 1; i <= n; i += 2)
        groups[0].pb((i + 1) / 2);
    while (groups.size() != (n + 1) / 2)
    {
        int even = *evens.find_by_order(rand() % evens.size());
        evens.erase(even);
        int l = 0, r = groups.size() - 1;
        while (r - l > 1)
        {
            int m = (l + r) >> 1;
            int odd = groups[m][rand() % groups[m].size()];

            if (ask(even, odd) == '<')
                r = m;
            else
                l = m;
        }
        auto cur = try_divide_group(groups[l], even);
        bool isL = 1;
        if (cur.first.size() == 0 || cur.second.size() == 0)
            cur = try_divide_group(groups[r], even), isL = 0;
        if (cur.second.size() == 0)
        {
            ans[2 * even] = n;
            continue;
        }
        int indToChange = isL ? l : r;
        groups[indToChange] = cur.first;
        groups.insert(groups.begin() + indToChange + 1, cur.second);

        for (int i = 0; i <= indToChange; ++i)
            ans[2 * even] += 2 * groups[i].size();
    }
    {
        int cur = 1;
        for (auto &v : groups)
        {
            ans[2 * v[0] - 1] = cur;
            cur += 2;
        }
    }
    cout << "! ";
    for (size_t i = 2; i <= n; i += 2)
        cout << ans[i] << ' ';
    for (size_t i = 1; i <= n; i += 2)
        cout << ans[i] << ' ';
    cout << endl;
}

int32_t main()
{
#ifndef LOCAL
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}