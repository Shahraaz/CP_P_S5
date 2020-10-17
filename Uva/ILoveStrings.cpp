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

struct SuffixTree
{
    enum
    {
        N = 200010,
        ALPHA = 26
    }; // N ∼ 2∗maxlen+10
    int toi(char c) { return c; }
    string a; // v = cur node , q = cur position
    map<char, int> t[N];
    int l[N], r[N], p[N], s[N], v = 0, q = 0, m = 2;
    void ukkadd(int i, int c)
    {
    suff:
        if (r[v] <= q)
        {
            if (t[v].find(c) == t[v].end())
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
        if (q == -1 || c == a[q])
            q++;
        else
        {
            l[m + 1] = i;
            p[m + 1] = m;
            l[m] = l[v];
            r[m] = q;
            p[m] = p[v];
            t[m][c] = m + 1;
            t[m][a[q]] = v;
            l[v] = q;
            p[v] = m;
            t[p[m]][a[l[m]]] = m;
            v = s[p[m]];
            q = l[m];
            while (q < r[m])
            {
                v = t[v][a[q]];
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
        // memset(t, -1, sizeof t);
        // fill(t[1], t[1] + ALPHA, 0);
        for (char c = 0; c < 127; c++)
            t[1][c] = 0;
        m = 2;
        q = 0;
        v = 0;
        s[0] = 1;
        l[0] = l[1] = -1;
        r[0] = r[1] = p[0] = p[1] = 0;
        for (size_t i = 0; i < a.size(); i++)
            ukkadd(i, a[i]);
#ifdef LOCAL
        for (size_t i = 0; i <= 2 * a.size() + 1; i++)
        {
            if (i == 1)
                continue;
            db(i, l[i], r[i], s[i], p[i]);
            for (size_t j = 0; j < 127; j++)
                if (t[i].find(j) != t[i].end())
                {
                    // if (j < 26)
                    cout << char(j) << ": " << t[i][j] << ' ';
                    //     else
                    //         cout << '$' << ": " << t[i][j] << ' ';
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
    bool find(string pattern)
    {
        auto node = 0;
        int ptr = 0;
        int len = 0;
        db(pattern);
        db(a);
        while (ptr < pattern.size())
        {
            db(node, ptr, l[node], r[node], len);
            if (ptr < r[node])
            {
                if (a[l[node] + len] == pattern[ptr])
                {
                    ++ptr;
                    ++len;
                }
                else
                {
                    db("a");
                    return false;
                }
            }
            else if (t[node].find(pattern[ptr]) == t[node].end())
            {
                db("b");
                return false;
            }
            else
            {
                node = t[node][pattern[ptr]];
                len = 1;
                ++ptr;
            }
        }
        return ptr == pattern.size();
    }
};

void solveCase()
{
    string s;
    cin >> s;
    s += '$';
    SuffixTree stree(s);
    int q;
    cin >> q;
    string Q;
    while (q--)
    {
        cin >> Q;
        if (stree.find(Q))
            cout << "y\n";
        else
            cout << "n\n";
    }
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
        solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
