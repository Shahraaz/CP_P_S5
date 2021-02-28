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

struct BIT
{
    int N;
    vector<long long> bit;

    void init(int n)
    {
        N = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, long long val)
    {
        while (idx <= N)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    long long pref(int idx)
    {
        long long ans = 0;
        while (idx > 0)
        {
            ans += bit[idx];
            idx -= idx & -idx;
        }
        return ans;
    }

    long long rsum(int l, int r)
    {
        return pref(r) - pref(l - 1);
    }
};

struct VeniceSet
{
    multiset<pair<int, int>> S;
    int water_level = 0;
    void add(pair<int, int> v)
    {
        v.first += water_level;
        S.insert(v);
    }
    void remove(pair<int, int> v)
    {
        v.first += water_level;
        S.erase(S.find(v));
    }
    void updateAll(int v)
    {
        water_level += v;
    }
    pair<int, int> getMin()
    {
        auto ret = *S.begin();
        ret.first -= water_level;
        return ret;
    }
    int size()
    {
        return S.size();
    }
    void show()
    {
#ifdef LOCAL
        for (auto x : S)
        {
            x.first += water_level;
            cout << x << ' ';
        }
        cout << '\n';
#endif
    }
};

void solveCase()
{
    int n, k;
    cin >> n >> k;
    vector<int> base(n + 1);
    BIT b;
    b.init(n + 1);
    for (size_t i = 1; i <= n; i++)
    {
        cin >> base[i];
        b.update(i, base[i]);
    }
    for (size_t i = 1; i <= n; i++)
        if (base[i] == 0)
            b.update(i, 1);
    vector<vector<pair<int, pair<int, int>>>> events(n + 1);
    for (size_t i = 0; i < k; i++)
    {
        int l, r, c;
        cin >> l >> r >> c;
        if (b.rsum(l, r) < c)
        {
            cout << "Impossible\n";
            return;
        }
        events[l].pb({0, {b.rsum(l, r) - c, i}});
        events[r].pb({1, {c, i}});
    }
    vector<int> d(k);
    VeniceSet vset;
    for (size_t i = 1; i <= n; i++)
    {
        // sort(all(events[i]));
        db(i, events[i]);
        for (auto &event : events[i])
            if (event.first == 0)
                vset.add(event.second);
        if (base[i] == 0)
        {
            while (vset.size())
            {
                auto mini = vset.getMin();
                vset.show();
                db(i, mini);
                if (d[mini.second])
                    vset.remove(mini);
                else if (mini.first >= 2)
                {
                    vset.updateAll(2);
                    base[i] = -1;
                    break;
                }
                else
                {
                    base[i] = 1;
                    break;
                }
            }
            if (base[i] == 0)
                base[i] = -1;
        }
        for (auto &event : events[i])
            if (event.first == 1)
                d[event.second.second] = 1;
    }
    for (size_t i = 1; i <= n; i++)
        cout << base[i] << ' ';
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