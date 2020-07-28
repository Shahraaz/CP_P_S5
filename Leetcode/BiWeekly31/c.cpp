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
    int minNumberOperations(vector<int> &target)
    {
        int ret = target[0];
        auto move = [&](int idx) {
            cout << idx << ' ';
            while (idx + 1 < target.size())
            {
                if (target[idx] <= target[idx + 1])
                    ++idx;
                else
                    break;
                // runningMax = max(runningMax, target[idx]);
                // prev = target[idx];
                // idx++;
            }
            cout << idx << '\n';
            return idx;
        };
        int idx = move(0);
        int prev = target[idx];
        int runningMax = prev;
        int leftht = target[0];
        int runnningMin = prev;
        for (size_t i = idx; i < target.size(); i++)
        {
            if (target[i] > prev)
            {
                cout << i << ' ' << prev << ' ' << leftht << ' ' << runningMax << '\n';
                ret += runningMax - max(prev, leftht);
                cout << runningMax - max(prev, leftht) << '\n';
                auto temp = move(i);
                leftht = prev;
                prev = target[temp];
                runningMax = prev;
                if (temp != i)
                    i = temp - 1;
            }
            else
            {
                // runningMax = max(runningMax, target[i]);
                prev = target[i];
            }
        }
        cout << prev << ' ' << leftht << ' ' << runningMax << '\n';
                cout << runningMax - max(prev, leftht) << '\n';
        cout << '\n';
        ret += runningMax - max(prev, leftht);
        return ret ;
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