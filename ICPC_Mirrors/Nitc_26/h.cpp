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
const int NAX = 4, MOD = 1000000007;

using vi = vector<int>;
#define sz(x) (int)x.size()
#define rep(i, a, b) for (int i = a; i < b; ++i)

vi pi(const string &s)
{
    vi p(sz(s));

    rep(i, 1, sz(s))
    {
        int g = p[i - 1];
        while (g && s[i] != s[g])
            g = p[g - 1];
        p[i] = g + (s[i] == s[g]);
    }
    return p;
}
vi match(const string &s, const string &pat)
{
    vi p = pi(pat + '$' + s), res;
    rep(i, sz(p) - sz(s), sz(p)) if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
    return res;
}

void solveCase()
{
    string A, B, C;
    cin >> A >> B >> C;
    int n = A.size();
    int ret = MOD;
    // C += C;
    for (int i = 0; i < n; i++)
    {
        bool ok = true;
        string C_c = A;
        for (size_t j = 0; j < n; j++)
            if (A[j] != B[(i + j) % n])
            {
                C_c[j] = 'A' ^ 'B' ^ 'C' ^ A[j] ^ B[(i + j) % n];
            }
            else
            {
                ok = false;
                break;
            }
        if (ok)
        {
            C_c += C_c;
            auto res = match(C_c, C);
            db(i, C_c, res);
            for (auto &x : res)
                if (x < n)
                {
                    x = n - x + 1;
                    ll a;
                    a = i;
                    ll c = x;
                    int ans = a + c;
                    db(i, x);
                    db(ans);
                    {
                        int cur = i;
                        if (i < c)
                            cur += c - i;
                        else
                            cur += (i - c + n) % n;
                        db(cur);
                        ans = min(ans, cur);
                    }
                    {
                        int cur = c;
                        if (i < c)
                            cur += c - i;
                        else
                            cur += (i - c + n) % n;
                        db(cur);
                        ans = min(ans, cur);
                    }
                    // cout << ans;
                    db(i, x, ans);
                    db(a, c, ans);
                    ret = min(ret, ans);
                }
        }
    }
    if (ret == MOD)
        ret = -1;
    cout << ret << '\n';
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