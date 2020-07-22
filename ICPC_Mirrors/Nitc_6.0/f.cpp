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
    void solveCase()
    {
        int n, k, j;
        cin >> n >> k >> j;
        map<int, pair<int, int>> table_details;
        for (size_t i = 0; i < n; i++)
        {
            int t, sz;
            cin >> t >> sz;
            if (sz == 1)
                table_details[t].f++;
            else
                table_details[t].s++;
        }
        db(table_details);
        int low = 1, high = 2 * n, ans = high;
        auto check = [&](int maxSz) -> bool {
            int jobCnt = 0;
            db(maxSz);
            for (auto x : table_details)
            {
                auto y = x.s;
                int fileGroupCnt = 1;
                int currSz = maxSz;
                if (maxSz < 1 && (y.s || y.f))
                    return false;
                if (maxSz < 2 && y.s)
                    return false;
                while (y.f + y.s > 0)
                {
                    if (y.s)
                    {
                        if (currSz >= 2)
                        {
                            y.s--;
                            currSz -= 2;
                        }
                        else
                        {
                            if (currSz == 1 && y.f > 0)
                            {
                                currSz--;
                                y.f--;
                            }
                            currSz = maxSz;
                            fileGroupCnt++;
                        }
                    }
                    else
                    {
                        if (currSz >= 1)
                        {
                            y.f--;
                            currSz--;
                        }
                        else
                        {
                            currSz = maxSz;
                            fileGroupCnt++;
                        }
                    }
                }
                jobCnt += ceil(fileGroupCnt * 1.0 / k);
            }
            return jobCnt <= j;
        };
        while (low <= high)
        {
            int mid = low + high;
            mid /= 2;
            auto ret = check(mid);
            db(mid, ret);
            if (ret)
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        cout << ans << '\n';
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
