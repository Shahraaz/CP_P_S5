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

const int NAX_PRIME = sqrt(1e15) + 5;
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
    db(primes.size(), primes.back());
}

void solveCase()
{
    seive();
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> c(n);
    vector<ll> foundPrime(m);
    for (auto &x : c)
        cin >> x;
    vector<vector<pair<int, int>>> adj(n + m);
    db(adj.size());
    for (size_t i = 0; i < k; i++)
    {
        int mx, nx, d;
        cin >> mx >> nx >> d;
        mx--, nx--;
        // db(mx, nx + m);
        adj[mx].pb({nx + m, d});
        adj[nx + m].pb({mx, d});
    }
    int primeptr = 0;
    for (size_t i = 0; i < m; i++)
    {
        db(i);
        while (primeptr < primes.size())
        {
            int matchIx = adj[i][0].first - m;
            db(matchIx);
            db(c[matchIx], primes[primeptr]);
            if (c[matchIx] % primes[primeptr] == 0)
            {
                foundPrime[i] = primes[primeptr];
                primeptr++;
                break;
            }
            else
                primeptr++;
        }
        db(i, foundPrime[i]);
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