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
    int getScore(string str)
    {
        map<char, vector<int>> indices;
        map<char, int> sum;
        int n = str.size();
        for (size_t i = 0; i < n; i++)
        {
            indices[str[i]].pb(i);
            sum[str[i]] += i;
        }
        reverse(all(indices['b']));
        reverse(all(indices['g']));
        db(sum, indices);
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            char other = 'b' ^ 'g' ^ str[i];
            db(str[i], other);
            db(sum, indices);
            res += sum[other] - indices[other].size() * i;
            sum[str[i]] -= indices[str[i]].back();
            indices[str[i]].pop_back();
        }
        // cout << res << '\n';
        return res;
    }
    Solution() {}
    void solveCase()
    {
        string str;
        cin >> str;
        cout << getScore(str) << '\n';
        vector<int> indices(str.size());
        int n = str.size();
        for (size_t i = 0; i < n; i++)
            indices[i] = i;
        pair<int, string> mini;
        mini.f = MOD;
        do
        {
            auto str2 = str;
            for (size_t i = 0; i < n; i++)
                str2[indices[i]] = str[i];
            mini = min(mini, {getScore(str2), str2});
        } while (next_permutation(all(indices)));
        db(mini);
        cout << mini.f << ' ' << mini.s << '\n';
    }
};

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
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
