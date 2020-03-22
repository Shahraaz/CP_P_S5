// Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define MULTI_TEST
#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#define pc(...)
#endif

#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()
auto TimeStart = chrono::steady_clock::now();
auto seed = TimeStart.time_since_epoch().count();
std::mt19937 rng(seed);
using ll = long long;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using Random = std::uniform_int_distribution<T>;

const int NAX = 2e5 + 5, MOD = 1000000007;

class Solution
{
private:
    vector<string> S;
    int h, w, k;
    int solve(vector<vector<int>> &CCnt)
    {
        vector<int> Cnt(h);
        int prev = -1, ret = 0;
        for (size_t i = 0; i < w; i++)
        {
            bool okCut = false;
            for (size_t j = 0; j < h; j++)
            {
                if (CCnt[j][i] > k)
                    return INT_MAX;
                if (Cnt[j] + CCnt[j][i] > k)
                {
                    okCut = true;
                }
            }
            if (okCut)
            {
                ret++;
                for (size_t j = 0; j < h; j++)
                    Cnt[j] = CCnt[j][i];
                prev = i;
            }
            else
            {
                for (size_t j = 0; j < h; j++)
                    Cnt[j] += CCnt[j][i];
            }
            db(i);
            pc(Cnt);
        }
        return ret;
    }

public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        cin >> h >> w >> k;
        db(h, w, k);
        S.resize(h);
        for (auto &x : S)
            cin >> x;
        ll res = INT_MAX;
        for (int i = 0; i < (1 << (h - 1)); i++)
        {
            vector<vector<int>> CCnt(h, vector<int>(w));
            int ptr = 0;
            for (size_t j = 0; j < h; j++)
            {
                for (int z = 0; z < w; z++)
                    CCnt[ptr][z] += S[j][z] == '1';
                if (i & (1 << j))
                    ++ptr;
            }
#ifdef LOCAL
            db(i);
            for (size_t j = 0; j < h; j++)
            {
                for (int z = 0; z < w; z++)
                    cout << CCnt[j][z] << ' ';
                cout << '\n';
            }
#else

#endif
            res = min(res, (ll)ptr + solve(CCnt));
            db(i, res);
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
#ifdef MULTI_TEST
    cin >> t;
#endif
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}