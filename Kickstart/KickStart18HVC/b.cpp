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

void solveCase()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int maxsum = 0;
    {
        vector<int> prefsum(n);
        prefsum[0] = str[0] - '0';
        db(str);
        for (size_t i = 1; i < n; i++)
            prefsum[i] = prefsum[i - 1] + str[i] - '0';
        db(prefsum);
        for (size_t i = 0; i < n; i++)
        {
            int len = n - i - 1;
            int lim = len / 2;
            int ans = i + lim;
            int l = (i + 1) / 2;
            auto now = prefsum[ans] - (l > 0 ? prefsum[l - 1] : 0);
            db(i, l, ans, now);
            maxsum = max(maxsum, now);
        }
    }
    db("phase2");
    {
        reverse(all(str));
        vector<int> prefsum(n);
        db(str);
        prefsum[0] = str[0] - '0';
        for (size_t i = 1; i < n; i++)
            prefsum[i] = prefsum[i - 1] + str[i] - '0';
        db(prefsum);
        for (size_t i = 0; i < n; i++)
        {
            int len = n - i - 1;
            int lim = len / 2;
            int ans = i + lim;
            int l = (i + 1) / 2;
            auto now = prefsum[ans] - (l > 0 ? prefsum[l - 1] : 0);
            db(i, l, ans, now);
            maxsum = max(maxsum, now);
        }
    }
    cout << maxsum << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solveCase();
#ifdef TIMER
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}