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

const int NAX = 1e5 + 5, MOD = 1000000007;
int N, Q;
vector<int> D;

template <typename inpType, int (*func)(int, int)>
struct sparseTree
{
    int n, logLim, def;
    vector<vector<int>> lookup;

    void buildSparseTable(inpType &arr, int n, int def)
    {
        this->n = n;
        this->def = def;
        logLim = __lg(n) + 1;
        lookup.resize(n, vector<int>(logLim, def));
        for (int i = 0; i < n; i++)
            lookup[i][0] = arr[i];
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 0; (i + (1 << j) - 1) < n; i++)
                lookup[i][j] = func(lookup[i][j - 1], lookup[i + (1 << (j - 1))][j - 1]);
    }

    int query(int L, int R)
    {
        if (L < 0 || L > n - 1 || R < 0 || R > n - 1 || L > R)
            return def;
        int j = __lg(R - L + 1);
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

void solveCase()
{
    cin >> N >> Q;
    D.clear();
    D.pb(MOD + 1);
    for (size_t i = 0; i + 1 < N; i++)
    {
        int x;
        cin >> x;
        D.pb(x);
    }
    D.pb(MOD);

    sparseTree<vector<int>, max> smax;
    smax.buildSparseTable(D, D.size() - 1, 0);

    db(D);

    for (size_t i = 0; i < Q; i++)
    {
        int S, K;
        cin >> S >> K;
        --K;

        db(S, K);

        if (K == 0)
        {
            cout << S << ' ';
            continue;
        }

        int ans = S - 1, left = S - 1, val = 0;
        int L = S, R = N - 1;

        while (L <= R)
        {
            int m = (L + R) / 2;
            int mx = smax.query(S, m);

            int LL = 0, RR = S - 1, f;
            while (LL <= RR)
            {
                int mm = (LL + RR) / 2;
                if (smax.query(mm, S - 1) > mx)
                {
                    f = mm;
                    LL = mm + 1;
                }
                else
                    RR = mm - 1;
            }

            db(f, S, m, mx);
            db(smax.query(f, S - 1));
            if (m - f <= K)
            {
                ans = m;
                left = f;
                val = m - f;
                L = m + 1;
            }
            else
                R = m - 1;
        }

        db(S, K, left, val);

        if (val < K)
        {
            ans = left;
            val++;
            ans -= K - val;
        }
        else
            ans++;

        cout << ans << ' ';
    }
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
