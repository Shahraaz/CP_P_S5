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

using ld = long double;
const ld EPS = 1e-12;

vector<int> KMP(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int gauss(vector<vector<ld>> a, vector<ld> &ans)
{
    int n = (int)a.size();
    int m = (int)a[0].size() - 1;

    vector<int> where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; ++col)
    {
        int sel = row;
        for (int i = row; i < n; ++i)
            if (abs(a[i][col]) > abs(a[sel][col]))
                sel = i;
        if (abs(a[sel][col]) < EPS)
            continue;
        for (int i = col; i <= m; ++i)
            swap(a[sel][i], a[row][i]);
        where[col] = row;

        for (int i = 0; i < n; ++i)
            if (i != row)
            {
                double c = a[i][col] / a[row][col];
                for (int j = col; j <= m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign(m, 0);
    for (int i = 0; i < m; ++i)
        if (where[i] != -1)
        {
            ans[i] = a[where[i]][m] / a[where[i]][i];
            assert(ans[i] < 1 + EPS);
        }
    for (int i = 0; i < n; ++i)
    {
        double sum = 0;
        for (int j = 0; j < m; ++j)
            sum += ans[j] * a[i][j];
        if (abs(sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i = 0; i < m; ++i)
        if (where[i] == -1)
            return 2;
    return 1;
}

void solveCase()
{
    string g, k;
    cin >> g >> k;
    // if (g == k)
    // {
    //     cout << fixed << setprecision(10) << 0.0 << '\n';
    //     return;
    // }
    ld ph, pt;
    cin >> ph;
    pt = 1 - ph;
    auto pg = KMP(g);
    db(g);
    db(pg);
    auto pk = KMP(k);
    db(k);
    db(pk);
    int noofvars = g.size() * k.size();
    vector<vector<ld>> equations(noofvars);
    auto cacl_next = [](string &str, vector<int> &p, char c) -> vector<int> {
        vector<int> ret(str.size());
        db(str, p);
        for (int i = 0; i < str.size(); i++)
        {
            int i_next = i;
            if (str[i] == c)
                i_next = i + 1;
            else
            {
                if (i != 0)
                {
                    i_next = p[i - 1];
                    while (i_next != 0 && str[i_next] != c)
                        i_next = p[i_next - 1];
                }
                i_next = i_next + (str[i_next] == c);
            }
            ret[i] = i_next;
            db(i, c, i_next);
        }
        return ret;
    };
    vector<int> next_g_h = cacl_next(g, pg, 'H');
    vector<int> next_g_t = cacl_next(g, pg, 'T');

    vector<int> next_k_h = cacl_next(k, pk, 'H');
    vector<int> next_k_t = cacl_next(k, pk, 'T');

    for (size_t i = 0; i < g.size(); i++)
    {
        for (size_t j = 0; j < k.size(); j++)
        {
            int idx = i * k.size() + j;
            equations[idx].resize(noofvars + 1);

            int inext = next_g_h[i], jnext = next_k_h[j];

            equations[idx][idx] += 1;
            if (jnext == k.size())
                ;
            else if (inext == g.size())
                equations[idx][noofvars] += ph;
            else
                equations[idx][inext * k.size() + jnext] -= ph;

            inext = next_g_t[i], jnext = next_k_t[j];

            if (jnext == k.size())
                ;
            else if (inext == g.size())
                equations[idx][noofvars] += pt;
            else
                equations[idx][inext * k.size() + jnext] -= pt;

            if (equations[idx][idx] < EPS)
            {
                assert(false);
                equations[idx] = vector<ld>(noofvars + 1);
                equations[idx][idx] = 1;
            }

            db(idx, equations[idx]);
        }
    }

    vector<ld> res(noofvars);

    assert(gauss(equations, res) != 0);

    cout << fixed << setprecision(10);
    cout << res[0] << '\n';
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