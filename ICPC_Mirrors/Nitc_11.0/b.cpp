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

#include <bits/stdc++.h>
using namespace std;

vector<int> log2_precalc;

template <typename inpType, int (*func)(int, int)>
struct sparseTree
{
    int n, logLim, def;
    vector<vector<int>> lookup;

    void buildSparseTable(inpType arr, int n, int def)
    {
        this->n = n;
        this->def = def;
        logLim = log2_precalc[n] + 1;
        lookup.resize(n, vector<int>(logLim, def));
        // pc(arr);
        for (int i = 0; i < n; i++)
        {
            lookup[i][0] = arr[i];
            // db(i, 0, lookup[i][0]);
        }
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 0; (i + (1 << j) - 1) < n; i++)
            {
                // db(lookup[i][j - 1], lookup[i + (1 << (j - 1))][j - 1]);
                lookup[i][j] = func(lookup[i][j - 1], lookup[i + (1 << (j - 1))][j - 1]);
                // db(i, j, lookup[i][j]);
            }
    }

    int query(int L, int R)
    {
        if (L < 0 || L > n - 1 || R < 0 || R > n - 1 || L > R)
            return def;
        int j = log2_precalc[R - L + 1];
        return func(lookup[L][j], lookup[R - (1 << j) + 1][j]);
    }
};

int min(int a, int b)
{
    return std::min(a, b);
}
int max(int a, int b)
{
    return std::max(a, b);
}

void Solution::solveCase()
{
    int n;
    cin >> n;
    // n = 100000;
    vector<int> l(n, 0);
    vector<int> r(n, n - 1);
    for (size_t i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
    }

    log2_precalc.resize(n + 10);
    for (size_t i = 2; i < log2_precalc.size(); i++)
        log2_precalc[i] = log2_precalc[i / 2] + 1;

    sparseTree<vector<int>, max> lptrMax;
    lptrMax.buildSparseTable(l, n, MOD);
    sparseTree<vector<int>, min> rptrMin;
    rptrMin.buildSparseTable(r, n, 0);
    ll res = 0;
    for (size_t i = 0; i < n; i++)
    {
        auto calcMax = [&](int j) -> int {
            int lptr = 1, rptr = r[i] - j + 1;
            // rptr = min(rptr, n - i);
            int ans = 1;
            while (lptr <= rptr)
            {
                int mid = (lptr + rptr) / 2;
                if ((lptrMax.query(i, i + mid - 1) <= j) && (rptrMin.query(i, i + mid - 1) >= (j + mid - 1)))
                {
                    ans = max(ans, mid);
                    lptr = mid + 1;
                }
                else
                    rptr = mid - 1;
            }
            return ans;
        };
        int low = l[i], high = r[i];
        while (low + 5 <= high)
        {
            int mid1 = (low + low + high) / 3;
            int mid2 = (low + high + high) / 3;
            if (calcMax(mid1) < calcMax(mid2))
                low = mid1;
            else
                high = mid2;
        }
        db(i, low, high);
        while (low <= high)
        {
            auto temp = calcMax(low);
            db(i, low, temp);
            res = max(res, temp);
            low++;
        }
    }
    cout << res << '\n';
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
