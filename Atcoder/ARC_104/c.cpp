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

void no()
{
    cout << "No\n";
    exit(0);
}

void yes()
{
    cout << "Yes\n";
    exit(0);
}

int dp[201][201];
void solveCase()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int diff = -1;
    vector<int> who(2 * n, -1);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        if (a[i] >= 0)
            a[i]--;
        if (b[i] >= 0)
            b[i]--;
        if (a[i] >= 0 && b[i] >= 0)
            if (a[i] >= b[i])
                no();
        if (a[i] >= 0)
            if (who[a[i]] == -1)
                who[a[i]] = i;
            else
                no();
        if (b[i] >= 0)
            if (who[b[i]] == -1)
                who[b[i]] = i;
            else
                no();
    }
    memset(dp, -1, sizeof dp);
    function<int(int, int)> solve = [&](int pos, int len) -> int {
        if (pos > 2 * n)
            return false;
        if (pos == 2 * n)
            return true;
        int &ret = dp[pos][len];
        if (ret >= 0)
            return ret;
        ret = false;
        int rptr = pos + 2 * len;
        db(pos, len, rptr);
        if (rptr > 2 * n)
            return false;
        vector<int> occupied(2 * n);
        for (size_t i = pos; i < pos + len; i++)
        {
            if (who[i] >= 0) // left
            {
                if (a[who[i]] != -1 && a[who[i]] != i)
                    return ret = false;
                if (b[who[i]] != -1 && b[who[i]] != (i + len))
                    return ret = false;
                if (who[i + len] >= 0)
                    if (who[i] != who[i + len])
                        return ret = false;
            }
            if (who[i + len] >= 0)
            {
                if (a[who[i + len]] != -1 && a[who[i + len]] != i)
                    return ret = false;
                if (b[who[i + len]] != -1 && b[who[i + len]] != (i + len))
                    return ret = false;
            }
        }
        for (size_t i = 1; i <= n; i++)
            if (solve(rptr, i))
                return ret = true;
        return ret;
    };
    for (size_t i = 1; i <= n; i++)
        if (solve(0, i))
            yes();
    no();
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
    {
        solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
