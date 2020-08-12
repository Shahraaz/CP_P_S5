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

string s;
int sum[NAX], twig[NAX], ball[NAX], numNodes, totBalls;
pair<int, int> child[NAX];

int parse(int start, int end)
{
    int len = end - start + 1;
    if (len <= 3)
    {
        twig[start] = true;
        int bcnt = 0;
        for (size_t i = start; i <= end; i++)
            bcnt += s[i] == 'B';
        ball[start] = bcnt;
        totBalls += bcnt;
        // sum[start] += bcnt;
        // numNodes++;
        child[start] = {-1, -1};
    }
    else
    {
        // start++;
        int ptr;
        int ctr = 0;
        for (ptr = start + 1; ptr <= end; ptr++)
        {
            if (s[ptr] == '(')
                ctr++;
            else if (s[ptr] == ')')
                ctr--;
            if (ctr == 0)
                break;
        }
        child[start].f = parse(start + 1, ptr);
        child[start].s = parse(ptr + 1, end - 1);
        twig[start] = false;
        // sum[start] = sum[child[start].f] + sum[child[start].s];
        ball[start] = 0;
        // numNodes++;
    }
    db(start, end, child[start], ball[start], sum[start], twig[start]);
    return start;
}

ll solve(int root, int given)
{
    ll res = MOD;
    if (root == -1)
    {
        if (given == 0)
            res = 0;
        // return MOD;
    }
    else if (twig[root])
    {
        if (given == 0)
            res = ball[root];
        if (given == 1)
            res = 1 - ball[root];
    }
    else if (given % 2 == 0)
    {
        auto l = solve(child[root].f, given / 2);
        auto r = solve(child[root].s, given / 2);
        res = min(res, l + r);
    }
    else
    {
        auto l = solve(child[root].f, given / 2);
        auto r = solve(child[root].s, given - given / 2);
        res = min(res, l + r);
        l = solve(child[root].f, given - given / 2);
        r = solve(child[root].s, given / 2);
        res = min(res, l + r);
    }
    db(root, given, res);
    return res;
}

struct Solution
{
    Solution() {}
    void solveCase()
    {
        while (cin >> s)
        {
            db(s);
            totBalls = numNodes = 0;
            int root = parse(0, s.length() - 1);
            db("-----------------");
            auto res = solve(root, totBalls);
            if (res < MOD)
                cout << res / 2 << '\n';
            else
                cout << "impossible" << '\n';
        }
    }
};

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
