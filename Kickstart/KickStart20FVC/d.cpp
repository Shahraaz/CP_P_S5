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

int N, M, K;
vector<int> reqd;
map<vector<int>, double> cache;

bool check(vector<int> a)
{
    for (size_t i = 0; i < M; i++)
        if (a[i] > reqd[i])
            return false;
    return true;
}

double solve(vector<int> a)
{
    if (a == reqd)
        return 0;
    if (cache.find(a) != cache.end())
        return cache[a];
    auto &ret = cache[a];
    ret = 1;
    int tot = 0;
    for (size_t i = 0; i < M; i++)
    {
        auto nv = a;
        nv[i]++;
        sort(all(nv));
        if (check(nv))
            ret += solve(nv) / M;
        else
            tot++;
    }
    ret = ret / (1 - (double)tot / M);
    return ret;
}

void solveCase()
{
    reqd.clear();
    cache.clear();
    cin >> N >> M >> K;
    for (size_t i = K; i < M; i++)
        reqd.pb(0);
    for (size_t i = 0; i < K; i++)
    {
        int x;
        cin >> x;
        reqd.pb(x);
    }
    vector<int> v;
    for (size_t i = 0; i < M; i++)
        v.pb(0);
    cout << fixed << setprecision(10) << solve(v) << '\n';
}

int32_t main()
{
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
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
