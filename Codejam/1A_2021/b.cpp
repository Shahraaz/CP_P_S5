#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

#define all(v) v.begin(), v.end()
#define pb push_back
const int NAX = 2e5 + 5, MOD = 1000000007;

const int NAX_PRIME = 500 + 0;
bool is_composite[NAX_PRIME];
vector<int> primes;

void seive(int n = NAX_PRIME)
{
    fill(is_composite, is_composite + n, false);
    for (int i = 2; i < n; i++)
    {
        if (!is_composite[i])
            primes.push_back(i);
        for (size_t j = 0; j < primes.size() && ((long long)i * primes[j] < n); j++)
        {
            is_composite[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
    long long prod = 1;
    for (size_t i = 0; i < primes.size(); i++)
    {
        prod = prod * primes[i];
        db(i, prod);
        if (prod > 50000)
            break;
    }
}

void solveCase()
{
    int n;
    cin >> n;
    vector<pair<long long, long long>> a(n);
    long long sum = 0;
    for (auto &x : a)
    {
        cin >> x.first >> x.second;
        sum += x.first * x.second;
    }
    for (long long i = sum - 1; i >= max(1LL, sum - 300000); i--)
    {
        auto curr = i;
        bool ok = true;
        long long now = sum;
        for (auto &x : a)
        {
            int cnt = 0;
            while (curr % x.first == 0)
            {
                cnt++;
                curr /= x.first;
                now -= x.first;
            }
            db(x, cnt);
            if (cnt > x.second)
            {
                ok = false;
                break;
            }
        }
        db(i, ok, curr, now);

        if (curr != 1)
            ok = false;

        if (ok && now == i)
        {
            cout << now << '\n';
            return;
        }
    }
    cout << 0 << '\n';
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
        cout << "Case #" << i << ": ";
        solveCase();
    }
    return 0;
}