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

void solveCase()
{
    int n;
    cin >> n;
    using ld = long double;
    vector<ld> a(n);
    for (auto &x : a)
        cin >> x;
    ld res = 0;
    function<ld(vector<ld>)> backtrack = [&](vector<ld> v) -> ld {
        db(v);
        if (v.size() == 1)
            return 0;
        int n = v.size();
        vector<ld> next(n - 1);
        ld den = (ld)1 / (n - 1);
        ld curr = 0;
        for (size_t i = 0; i + 1 < n; i++)
        {
            curr += v[i] + v[i + 1];
            int chances = n - i - 1;
            int num = 0;
            chances--;
            next[i] = v[i] * chances * den;
            db(i, "a", chances);
            num += chances;
            if (i - 1 >= 0)
            {
                next[i] += v[i + 1] * (i)*den;
                db(i, "b", i);
            }
            next[i] += den * (v[i] + v[i + 1]);
            db(i, "c", 1);
        }
        return curr * den + backtrack(next);
    };
    res = backtrack(a);
    cout << fixed << setprecision(8);
    cout << res << '\n';
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
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
