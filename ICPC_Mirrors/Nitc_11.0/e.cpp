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
    vector<string> vecc;
    vector<int> lbnd, rbnd;
    int inp[n];
    for (size_t i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int x;
        cin >> x;
        inp[i] = x * 100;
        vecc.pb(s);
        if (x == 0)
            lbnd.pb(x);
        else
            lbnd.pb((x - 1) * 100 + 50);
        if (x == 100)
            rbnd.pb(x * 100);
        else
            rbnd.pb(x * 100 + 49);
    }
    db(lbnd, rbnd);
    ll temp = accumulate(all(rbnd), 0LL);
    db(temp, 100 * 100);
    db(temp < (100 * 100));
    if (temp >= (100 * 100))
    {
        temp = accumulate(all(lbnd), 0LL);
        db(temp, 100 * 100);
        db(temp > (100 * 100));
        if (temp <= (100 * 100))
        {
            temp = accumulate(all(rbnd), 0LL);
            auto ll = lbnd;
            for (size_t i = 0; i < n; i++)
            {
                int tt = temp - rbnd[i];
                tt = 100 * 100 - tt;
                ll[i] = max(tt, lbnd[i]);
            }
            temp = accumulate(all(lbnd), 0LL);
            auto rr = rbnd;
            for (size_t i = 0; i < n; i++)
            {
                int tt = temp - lbnd[i];
                tt = 100 * 100 - tt;
                rr[i] = min(tt, rbnd[i]);
            }
            db(ll);
            db(rr);
            for (size_t i = 0; i < n; i++)
            {
                cout << vecc[i] << ' ';
                auto N = to_string(ll[i]);
                while (N.size() <= 2)
                    N = "0" + N;
                int sz = N.size();
                for (size_t j = 0; j + 2 < N.size(); j++)
                    cout << N[j];
                cout << ".";
                for (size_t j = N.size() - 2; j < N.size(); j++)
                    cout << N[j];
                cout << ' ';
                N = to_string(rr[i]);
                while (N.size() <= 2)
                    N = "0" + N;
                sz = N.size();
                for (size_t j = 0; j + 2 < N.size(); j++)
                    cout << N[j];
                cout << ".";
                for (size_t j = N.size() - 2; j < N.size(); j++)
                    cout << N[j];
                cout << ' ';
                cout << '\n';
            }
        }
        else
            cout << "IMPOSSIBLE\n";
    }
    else
        cout << "IMPOSSIBLE\n";
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
