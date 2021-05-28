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
const int NAX = 1e6 + 5, MOD = 1000000007;

int cnt[NAX];
int freq[NAX];
vector<int> factors[NAX];

void solveCase()
{
    int n = 2e5;
    cin >> n;

    vector<int> a(n);
    int limi = 1e6;
    for (auto &x : a)
    {
        x = limi--;
        cin >> x;
    }

    const int MAX_ELEM = *max_element(all(a));

    for (auto &x : a)
        freq[x]++;

    ll res = 0;
    for (size_t i = 1; i <= MAX_ELEM; i++)
    {
        for (size_t j = i; j <= MAX_ELEM; j += i)
        {
            int other = j / i;
            if (i != other && j != other && i != j)
                res += freq[j] * 1LL * freq[i] * freq[other];
        }
    }
    cout << res / 2 << '\n';
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