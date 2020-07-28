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
    int convert(string c)
    {
        if (c == "K" || c == "Q" || c == "J")
            return 10;
        if (c == "A")
            return 11;
        return stoi(c);
    }
    Solution() {}
    void solveCase()
    {
        int n, m;
        bool first = true;
        while (cin >> n >> m)
        {
            // if (first)
            //     first = false;
            // else
            // cout << '\n';
            vector<int> vecc(n);
            for (size_t i = 0; i < n; i++)
            {
                string c;
                cin >> c;
                vecc[i] = convert(c);
            }
            int maxLen = m + accumulate(all(vecc), 0);
            vector<int> next(maxLen, -1);
            using ld = long double;
            vector<ld> prob(maxLen);
            int curr = m - 1;
            for (auto &x : vecc)
            {
                next[curr] = x;
                curr += x;
            }
            while (next.size() && next.back() == -1)
                next.pop_back();
            db(n, m);
            db(vecc);
            db(next);
            vector<int> choices = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
            for (int i = next.size() - 1; i >= 0; i--)
            {
                if (next[i] >= 0)
                {
                    prob[i] = 1;
                }
                else
                {
                    prob[i] = 0;
                    for (auto &x : choices)
                        if (i + x < next.size())
                            prob[i] += prob[i + x];
                    prob[i] /= choices.size();
                }
            }
            int temp = min(10, (int)prob.size());
            ld ret = 0;
            for (size_t i = 0; i < temp; i++)
                ret += prob[i];
            ret /= temp;
            cout << fixed << setprecision(7);
            cout << ret << '\n';
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
