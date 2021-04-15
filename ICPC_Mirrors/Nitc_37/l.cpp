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
const int NAX = 3e4 + 5, MOD = 1000000007;

const int NAX_PRIME = NAX;
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

using ld = double;
const int PCNT = 500;

ld res_dp[NAX][PCNT], pre_lg[NAX];
bool computed[NAX][PCNT];

ld solve(int x, int pidx)
{
    if (x <= 1 || pidx == PCNT || x < primes[pidx])
        return 0;
    if (computed[x][pidx])
        return res_dp[x][pidx];
    computed[x][pidx] = 1;
    auto &ret = res_dp[x][pidx];
    ret = solve(x, pidx + 1);
    ll now = 1, cnt = 0;
    while (x >= now)
    {
        ret = max(ret, cnt * pre_lg[primes[pidx]] + solve(x - now, pidx + 1));
        now *= primes[pidx];
        ++cnt;
    }
    // db(x, pidx, ret);
    return ret;
}

void solveCase()
{
    seive();
    int t = 3e4;
    cin >> t;
    for (size_t i = 1; i < NAX; i++)
        pre_lg[i] = log(i);
    db(primes[PCNT]);
    cout << fixed << setprecision(10);
    for (size_t i = 0; i < t; i++)
    {
        int x = i + 1;
        cin >> x;
        db(x, exp(solve(x, 0)));
        cout << solve(x, 0) << '\n';
    }
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}