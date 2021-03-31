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
const int NAX = 5000 + 5, MOD = 1000000007;

const int p = 98789101LL;
int hashs[NAX];
int pows[NAX];
struct Rabin_Karp
{
    int valLen;
    Rabin_Karp()
    {
        pows[0] = 1;
        for (int i = 1; i < NAX; i++)
            pows[i] = (pows[i - 1] * 1LL * p) % MOD;
    }
    int prepareString(vector<int> &s)
    {
        int ret = 0;
        for (int i = 0; i < s.size(); i++)
            ret = (ret * 1LL * p + s[i]) % MOD;
        return ret;
    }
    int prepareString(set<pair<int, int>> &s)
    {
        int i = 0, ret = 0;
        for (auto &x : s)
        {
            ret = (ret * 1LL * p + x.second) % MOD;
            ++i;
        }
        return ret;
    }
};

Rabin_Karp R;

int a[NAX], m[NAX], l[NAX], res[NAX];
vector<int> tosearch[NAX];

void solveCase()
{
    int n = 5000, q = 2000;
    cin >> n >> q;
    for (size_t i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> queries(n + 1);
    vector<pair<int, pair<int, int>>> hashes;
    for (size_t i = 0; i < q; i++)
    {
        res[i] = 0;
        tosearch[i].clear();
        cin >> m[i];
        queries[m[i]].pb(i);
        for (size_t j = 0; j < m[i]; j++)
        {
            int x;
            cin >> x;
            tosearch[i].pb(x);
        }
        hashes.pb({m[i], {i, R.prepareString(tosearch[i])}});
    }
    set<pair<int, int>> ms;
    vector<int> inset(n + 1, -1);
    sort(all(hashes));
    for (size_t i = 0; i < n; i++)
    {
        int val = a[i];
        if (inset[val] == -1)
        {
            ms.insert({i, val});
            inset[val] = i;
        }
        else
        {
            ms.erase({inset[val], val});
            inset[val] = i;
            ms.insert({i, val});
        }
        int now = 0;
        auto it = ms.end();
        int cnt = 0;
        for (size_t j = 1; j <= n; j++)
        {
            if (it != ms.begin())
            {
                --it;
                cnt = (cnt * 1LL * p + it->second) % MOD;
            }
            else
                cnt = (cnt * 1LL * p) % MOD;
            while (now < q && hashes[now].first == j)
            {
                if (hashes[now].second.second == cnt || hashes[now].second.second == 0)
                    res[hashes[now].second.first] = 1;
                now++;
            }
            if (now == q)
                break;
        }
    }
    for (size_t i = 0; i < q; i++)
    {
        if (res[i])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 100;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}