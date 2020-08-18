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

struct Solution
{
    Solution() {}
    void solveCase();
};

void Solution::solveCase()
{
    int n;
    cin >> n;
    vector<pair<int, int>> intervals;
    set<int> count;
    for (size_t i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        intervals.pb({l, r});
    }
    sort(all(intervals));
    int p;
    cin >> p;
    vector<int> pegs;
    for (size_t i = 0; i < p; i++)
    {
        int x;
        cin >> x;
        pegs.pb(x);
        count.insert(x);
    }
    vector<int> ret;
    auto check_count = [&](int l, int r) {
        int temp = 0;
        auto it = count.lower_bound(l);
        while (temp < 3 && it != count.end())
        {
            if (*it > r)
                break;
            ++it;
            ++temp;
        }
        return temp;
    };

    for (auto &x : intervals)
    {
        int len = x.s - x.f + 1;
        if (len == 1)
        {
            cout << "impossible\n";
            return;
        }
        else if (len == 2)
        {
            if (count.find(x.f) == count.end())
            {
                count.insert(x.f);
                ret.pb(x.f);
            }
            if (count.find(x.s) == count.end())
            {
                count.insert(x.s);
                ret.pb(x.s);
            }
        }
        int temp = check_count(x.f, x.s);
        if (temp > 2)
        {
            cout << "impossible\n";
            return;
        }
    }
    for (size_t i = 0; i + 1 < n; i++)
        if (intervals[i].s == intervals[i + 1].f)
        {
            if (count.find(intervals[i].s) != count.end())
                continue;
            int l = check_count(intervals[i].f, intervals[i].s);
            int r = check_count(intervals[i + 1].f, intervals[i + 1].s);
            if (l < 2 && r < 2)
            {
                // peg_set.insert(intervals[i].s);
                ret.pb(intervals[i].s);
                count.insert(intervals[i].s);
            }
        }
    for (size_t i = 0; i < n; i++)
    {
        int l = check_count(intervals[i].f, intervals[i].s);
        int len = intervals[i].s - intervals[i].f + 1;
        if (l == 2)
        {
        }
        else if (l == 1)
        {
            if (len >= 3)
            {
                int lptr = intervals[i].f + 1;
                int rptr = intervals[i].s - 1;
                int ctr = 0;
                while (lptr <= rptr)
                {
                    if (count.find(lptr) == count.end())
                    {
                        ctr++;
                        ret.pb(lptr);
                        count.insert(lptr);
                        if (ctr == 1)
                            break;
                    }
                    lptr++;
                }
                if (ctr != 1)
                {
                    cout << "impossible\n";
                    return;
                }
            }
            else
            {
                cout << "impossible\n";
                return;
            }
        }
        else if (l == 0)
        {
            if (len >= 4)
            {
                int lptr = intervals[i].f + 1;
                int rptr = intervals[i].s - 1;
                int ctr = 0;
                while (lptr <= rptr)
                {
                    if (count.find(lptr) == count.end())
                    {
                        ctr++;
                        ret.pb(lptr);
                        count.insert(lptr);
                        if (ctr == 2)
                            break;
                    }
                    lptr++;
                }
                if (ctr != 2)
                {
                    cout << "impossible\n";
                    return;
                }
            }
            else
            {
                cout << "impossible\n";
                return;
            }
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        int l = check_count(intervals[i].f, intervals[i].s);
        db(i, l);
        if (l != 2)
        {
            cout << "impossible\n";
            return;
        }
    }
    cout << ret.size() << '\n';
    for (auto &x : ret)
        cout << x << ' ';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}