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

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int U;
        cin >> U;
        int ctr = 10000;
        vector<pair<ll, string>> inp(ctr);
        map<char, ll> S;
        for (size_t i = 0; i < ctr; i++)
        {
            cin >> inp[i].f >> inp[i].s;
            // for (auto &c : inp[i].second)
            //     S[c]++;
            S[inp[i].s.front()]++;
            if (inp[i].s.size() > 1)
                S[inp[i].s[1]]++;
        }
        db(S);
        vector<pair<ll, char>> v;
        for (auto &x : S)
            v.pb({x.s, x.f});
        sort(all(v));
        db(v);
        cout << v.front().s;
        for (size_t i = 9; i > 0; i--)
            cout << v[i].s;
        cout << '\n';
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
        cout << "Case #" << i << ": ";
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
