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
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int K)
    {
        int n = quality.size();
        vector<pair<int, int>> workers(n);
        for (size_t i = 0; i < n; i++)
        {
            workers[i].f = wage[i];
            workers[i].s = quality[i];
        }
        sort(all(workers), [](pair<int, int> a, pair<int, int> b) {
            return a.f * b.s < a.s * b.f;
        });
        double ret = MOD;
        priority_queue<int> Q;
        int sumQ = 0;
        for (auto &x : workers)
        {
            Q.push(x.s);
            if (Q.size() > K)
            {
                sumQ += Q.top();
                Q.pop();
            }
            if (Q.size() == K)
                ret = min(ret, sumQ * x.f * 1.0 / x.s);
        }
        return ret;
    }
};

#ifdef LOCAL
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    Solution S;
    for (int i = 1; i <= t; ++i)
    {
        ;
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif