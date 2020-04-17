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
        int k, m;
        cin >> k;
        vector<int> sizes(k);
        vector<ll> v[k];
        vector<ll> prefSums[k];
        vector<pair<pair<int, int>, ll>> auxRes;
        vector<int> bigIndices;
        const int K = 500;
        auto compute = [&](int i, int j) -> ll {
            if (sizes[i] > sizes[j])
                swap(i, j);
            ll res = 0;
            db(v[i]);
            db(v[j]);
            for (auto &x : v[i])
            {
                int low = lower_bound(all(v[j]), x) - v[j].begin();
                db(x, low);
                ll temp = 0;
                temp += prefSums[j][sizes[j] - 1];
                if (low > 0)
                    temp -= prefSums[j][low - 1];
                res += (temp) - (sizes[j] - low) * x;
                if (low > 0)
                    res += low * x - prefSums[j][low - 1];
            }
            db(i, j, res);
            return res;
        };
        map<pair<int, int>, ll> mp;
        for (size_t i = 0; i < k; i++)
        {
            cin >> sizes[i];
            v[i].resize(sizes[i]);
            prefSums[i].resize(sizes[i]);
            for (size_t j = 0; j < sizes[i]; j++)
            {
                cin >> v[i][j];
                prefSums[i][j] = v[i][j];
                if (j > 0)
                    prefSums[i][j] += prefSums[i][j - 1];
            }
            sort(all(v[i]));
            if (sizes[i] >= K)
            {
                for (auto &j : bigIndices)
                    mp[{i, j}] = compute(i, j);
                bigIndices.pb(i);
            }
        }
        cin >> m;
        db(m);
        for (size_t i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            --x, --y;
            db(x, y);
            if (x > y)
                swap(x, y);
            if (sizes[x] >= K && sizes[y] >= K)
                cout << mp[{x, y}] << '\n';
            else
                cout << compute(x, y) << '\n';
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
