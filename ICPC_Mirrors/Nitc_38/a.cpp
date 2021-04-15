#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

#define all(v) v.begin(), v.end()
#define pb push_back
using ll = long long;
const int NAX = 2e5 + 5, MOD = 1000000007;

const int NAX_PRIME = 1e4 + 5;
bool is_composite[NAX_PRIME];
vector<int> primes;

void seive(int n = NAX_PRIME)
{
    fill(is_composite, is_composite + n, false);
    for (int i = 2; i < n; i++)
    {
        if (!is_composite[i])
            primes.push_back(i);
        for (size_t j = 0; j < primes.size() && ((ll)i * primes[j] < n); j++)
        {
            is_composite[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

void solveCase()
{
    // return;
    int n;
    cin >> n;
    set<int> ss;
    // vector<vector<int>> idxes(1001);
    vector<int> nums(n + 1);
    set<int> ssss;
    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums[i + 1] = x;
        if (x)
            ssss.insert(x);
    }
    db(nums);
    db(ssss);
    int m = -1, r = -1;
    for (auto &x : primes)
    {
        if (x > n)
            break;
        for (size_t r = 0; r < x; r++)
        {
            int idx = r;
            db(x, r);
            set<int> ss;
            while (idx)
            {
                if (idx > n)
                    break;
                if (nums[idx] != 0)
                    ss.insert(nums[idx]);
                idx += x;
            }
            if (ss.size() == ssss.size())
            {
                cout << x << ' ' << r << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
}

int32_t main()
{
    seive();
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case " << i << ": ";
        solveCase();
    }
    return 0;
}