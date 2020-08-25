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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    deque<int> Q;
    auto check = [&]() -> bool {
        db("incheck", Q);
        if (Q.size() == n)
        {
            set<int> first, second, common;
            int prev = -1;
            for (size_t i = 0; i < n; i++)
            {
                if (prev <= Q[i])
                    first.insert(i);
                prev = max(prev, Q[i]);
            }
            prev = -1;
            for (size_t i = 0; i < n; i++)
            {
                if (prev <= Q[n - i - 1])
                {
                    if (first.count(n - i - 1))
                        common.insert(n - i - 1);
                    second.insert(n - i - 1);
                }
                prev = max(prev, Q[n - i - 1]);
            }
            db(first, second);
            db(a, b, c);
            return first.size() == a && second.size() == b && c == common.size();
        }
        db("false");
        return false;
    };
    if (n <= 5)
    {
        Q.resize(n, 1);
        function<int(int)> recur = [&](int pos) -> int {
            if (pos == n)
                return check();
            for (size_t i = 1; i <= n; i++)
            {
                Q[pos] = i;
                if (recur(pos + 1))
                    return true;
            }
            return false;
        };
        if (recur(0))
        {
            for (auto &x : Q)
            {
                cout << x << ' ';
            }
            cout << "\n";
        }
        else
            cout << "IMPOSSIBLE\n";
        return;
    }
    db(n, a, b, c);
    bool mark = false;
    if (b == c)
    {
        swap(a, b);
        mark = true;
    }
    for (size_t i = c; i < a; i++)
        Q.push_front(2);
    int tot = n + c - a - b;
    for (size_t i = 0; i < c; i++)
    {
        if (i == 1)
        {
            for (int i = 0; i < tot; i++)
                Q.push_back(1);
            tot = 0;
        }
        Q.pb(n);
    }
    for (int i = 0; i < tot; i++)
        Q.push_back(1);
    for (size_t i = c; i < b; i++)
        Q.push_back(2);
    if (check())
    {
        if (mark)
            reverse(all(Q));
        for (auto &x : Q)
            cout << x << ' ';
        cout << "\n";
        return;
    }
    cout << "IMPOSSIBLE";
    cout << '\n';
}

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
