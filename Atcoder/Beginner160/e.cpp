// Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define MULTI_TEST
#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#define pc(...)
#endif

#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()
auto TimeStart = chrono::steady_clock::now();
auto seed = TimeStart.time_since_epoch().count();
std::mt19937 rng(seed);
using ll = long long;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using Random = std::uniform_int_distribution<T>;

const int NAX = 2e5 + 5, MOD = 1000000007;

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int x, y, a, b, c;
        cin >> x >> y >> a >> b >> c;
        vector<ll> p(a), q(b), r(c);
        for (auto &x : p)
            cin >> x;
        for (auto &x : q)
            cin >> x;
        for (auto &x : r)
            cin >> x;
        sort(all(p));
        sort(all(q));
        sort(all(r));
        reverse(all(p));
        reverse(all(q));
        reverse(all(r));
        // for (size_t i = 1; i < a; i++)
        //     p[i] += p[i - 1];
        // for (size_t i = 1; i < b; i++)
        //     q[i] += q[i - 1];
        // for (size_t i = 1; i < c; i++)
        //     r[i] += r[i - 1];
        vector<ll> v;
        for (size_t i = 0; i < x; i++)
            v.pb(p[i]);
        for (size_t i = 0; i < y; i++)
            v.pb(q[i]);
        // pc(p, q, v);
        sort(all(v));
        reverse(all(v));
        pc(p, q, v, r);
        ll res = accumulate(all(v), 0LL);
        int ptr = 0;
        ll sum = res;
        // pc(v);
        while (ptr < r.size() && v.size())
        {
            sum -= v.back();
            v.pop_back();
            sum += r[ptr];
            ++ptr;
            res = max(res, sum);
            db(ptr, res);
            pc(v);
        }
        cout << res << '\n';
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}