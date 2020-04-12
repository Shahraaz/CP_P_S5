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
        int n;
#ifdef LOCAL
        cin >> n;
        // srand(time(NULL));
        // n = 7;
        vector<int> a(n);
        for (auto &x : a)
        {
            cin >> x;
            // x = rand() % 200 - 100;
        }
#else
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

#endif
        vector<ll> weirdDpFord(n);
        vector<ll> weirdDpBack(n);
        vector<ll> cCntFord(n, 1);
        vector<ll> cCntDpBack(n, 1);
        ll res = LLONG_MIN;
        for (int i = 0; i < n; i++)
        {
            weirdDpFord[i] = a[i];
            if (i - 2 >= 0)
            {
                weirdDpFord[i] += weirdDpFord[i - 2];
                cCntFord[i] += cCntFord[i - 2];
            }
            if (cCntFord[i] == n / 2)
                res = max(res, weirdDpFord[i]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            weirdDpBack[i] = a[i];
            if (i + 2 < n)
            {
                weirdDpBack[i] += weirdDpBack[i + 2];
                cCntDpBack[i] += cCntDpBack[i + 2];
            }
            if (cCntDpBack[i] == n / 2)
                res = max(res, weirdDpBack[i]);
        }
        db(a, weirdDpBack, weirdDpFord);
        db(cCntFord, cCntDpBack);
        if (n & 1)
        {
            for (int i = 0; i < n; i++)
            {
                int cnt = cCntFord[i];
                ll temp = weirdDpFord[i];
                int k = 4;
                for (size_t j = i + 2; j < n; j++)
                {
                    k--;
                    if (cnt + cCntDpBack[j] == n / 2)
                    {
                        db(i, j, temp, weirdDpBack[j], cnt, cCntDpBack[j]);
                        res = max(res, temp + weirdDpBack[j]);
                    }
                    if (k == 0)
                        break;
                }
                cnt = 1;
                temp = a[i];
                if (i - 3 >= 0)
                {
                    temp += weirdDpFord[i - 3];
                    cnt += cCntFord[i - 3];
                }
                if (i + 3 < n)
                {
                    temp += weirdDpBack[i + 3];
                    cnt += cCntDpBack[i + 3];
                }
                db(i, cnt, temp);
                if (cnt == n / 2)
                {
                    res = max(res, temp);
                }
            }
            // for (int i = 0; i < n; i++)
            // {
            //     int cnt = 0;
            //     ll temp = 0;
            //     if (i - 2 >= 0)
            //     {
            //         cnt += cCntFord[i - 2];
            //         temp += weirdDpFord[i - 2];
            //     }
            //     if (cnt == n / 2)
            //     {
            //         res = max(res, temp);
            //     }
            //     if (i + 1 < n)
            //     {
            //         cnt += cCntDpBack[i + 1];
            //         temp += weirdDpBack[i + 1];
            //     }
            //     if (cnt == n / 2)
            //     {
            //         res = max(res, temp);
            //     }
            // }
        }
        else
        {
            res = max(weirdDpFord.back(), weirdDpBack.front());
            // for (int i = 0; i < n; i++)
            // {
            //     ll temp = 0;
            //     if (i - 1 >= 0)
            //         temp += weirdDpFord[i - 1];
            //     if (i + 1 < n)
            //         temp += weirdDpBack[i + 1];
            //     db(i, temp);
            //     res = max(res, temp);
            // }
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
