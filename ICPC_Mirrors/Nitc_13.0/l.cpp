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

// Optimise
#include <bits/stdc++.h>
using namespace std;

struct fraction
{
    ll p, q;
    fraction(ll p = 1, ll q = 1)
    {
        auto g = __gcd(p, q);
        this->p = p / g;
        this->q = q / g;
    }
    bool operator<(const fraction &f) const
    {
        return p * f.q < f.p * q;
    }
};

struct SuffixTree
{
    enum
    {
        N = 400010,
        ALPHA = 27
    }; // N ∼ 2∗maxlen+10
    int toi(char c) { return c == '$' ? 26 : c - 'a'; }
    string a; // v = cur node , q = cur position
    int t[N][ALPHA], l[N], r[N], p[N], s[N], v = 0, q = 0, m = 2;
    set<int> lens[N];
    fraction ans;
    void ukkadd(int i, int c)
    {
    suff:
        if (r[v] <= q)
        {
            if (t[v][c] == -1)
            {
                t[v][c] = m;
                l[m] = i;
                p[m++] = v;
                v = s[v];
                q = r[v];
                goto suff;
            }
            v = t[v][c];
            q = l[v];
        }
        if (q == -1 || c == toi(a[q]))
            q++;
        else
        {
            l[m + 1] = i;
            p[m + 1] = m;
            l[m] = l[v];
            r[m] = q;
            p[m] = p[v];
            t[m][c] = m + 1;
            t[m][toi(a[q])] = v;
            l[v] = q;
            p[v] = m;
            t[p[m]][toi(a[l[m]])] = m;
            v = s[p[m]];
            q = l[m];
            while (q < r[m])
            {
                v = t[v][toi(a[q])];
                q += r[v] - l[v];
            }
            if (q == r[m])
                s[m] = v;
            else
                s[m] = m + 2;
            q = r[v] - (q - r[m]);
            m += 2;
            goto suff;
        }
    }
    SuffixTree(string a) : a(a)
    {
        fill(r, r + N, a.size());
        memset(s, 0, sizeof s);
        memset(t, -1, sizeof t);
        fill(t[1], t[1] + ALPHA, 0);
        m = 2;
        q = 0;
        v = 0;
        s[0] = 1;
        l[0] = l[1] = -1;
        r[0] = r[1] = p[0] = p[1] = 0;
        for (size_t i = 0; i < a.size(); i++)
            ukkadd(i, toi(a[i]));
#ifdef LOCAL
        for (size_t i = 0; i <= 3 * a.size(); i++)
        {
            db(i, l[i], r[i], s[i], p[i]);
            for (size_t j = 0; j < 27; j++)
                if (t[i][j] >= 0)
                {
                    if (j < 26)
                        cout << char(j + 'a') << ": " << t[i][j] << ' ';
                    else
                        cout << '$' << ": " << t[i][j] << ' ';
                }
            cout << '\n';
        }
#endif
    }
    // example : find longest common substring ( uses ALPHA = 28)
    pair<int, int> best;
    int lcs(int node, int i1, int i2, int olen)
    {
        if (l[node] <= i1 && i1 < r[node])
            return 1;
        if (l[node] <= i2 && i2 < r[node])
            return 2;
        int mask = 0, len = node ? olen + (r[node] - l[node]) : 0;
        for (size_t c = 0; c < ALPHA; c++)
            if (t[node][c] != -1)
                mask |= lcs(t[node][c], i1, i2, len);
        if (mask == 3)
            best = max(best, {len, r[node] - len});
        return mask;
    }
    static pair<int, int> LCS(string s, string t)
    {
        SuffixTree st(s + (char)('z' + 1) + t + (char)('z' + 2));
        st.lcs(0, (s).size(), s.size() + 1 + t.size(), 0);
        return st.best;
    }

    int dfs(int node, int len)
    {
        bool isLeaf = true;
        if (node >= N)
        {
            cout << "WA\n";
            // return;
            exit(0);
        }
        int md = N;
        for (size_t i = 0; i < 27; i++)
            if (t[node][i] >= 0)
            {
                if (node == 0 && i == 26)
                    continue;
                isLeaf = false;
                if (t[node][i] >= N)
                {
                    cout << "WA\n";
                    // return;
                    exit(1);
                }
                md = min(md, dfs(t[node][i], len + r[t[node][i]] - l[t[node][i]]));
                if (lens[node].size() < lens[t[node][i]].size())
                    lens[node].swap(lens[t[node][i]]);
                for (auto &x : lens[t[node][i]])
                {
                    auto it = lens[node].lower_bound(x);
                    if (it != lens[node].end())
                        md = min(md, *it - x);
                    if (it != lens[node].begin())
                        md = min(md, x - *(--it));
                    lens[node].insert(x);
                }
            }
        if (md != N)
        {
            // cout << (len + md + 0.0) / md << '\n';
            ans = max(ans, fraction(len + md, md));
        }
        if (isLeaf)
        {
            lens[node].insert(len - 1);
            // return N;
            md = N;
        }
        db(node, len, md, lens[node]);
        // db(lens[node]);
        // #ifdef LOCAL
        //         for (size_t i = 0; i < 26; i++)
        //             if (t[node][i] >= 0)
        //                 cout << char(i + 'a') << ": " << t[node][i] << ", ";
        //         cout << '\n';
        //         db(lens[node]);
        // #endif
        return md;
    }

    void solve()
    {
        ans = fraction(1, 1);
        dfs(0, 0);
        // for (size_t i = 0; i < 26; i++)
        //     if (t[0][i] >= 0)
        //         dfs(t[0][i], min((int)a.size(), r[t[0][i]]) - l[t[0][i]]);
        cout << ans.p << "/" << ans.q << '\n';
    }
};

void solveCase()
{
    string w;
    cin >> w;
    w += '$';
    SuffixTree s(w);
    s.solve();
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
