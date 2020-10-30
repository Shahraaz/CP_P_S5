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
    int N = 0;
    enum
    {
        ALPHA = 26
    }; // N ∼ 2∗maxlen+10
    int toi(char c) { return c; }
    string a; // v = cur node , q = cur position
    vector<map<char, int>> t;
    vector<int> l, r, p, s;
    int v = 0, q = 0, m = 2;
    vector<set<int>> lens;
    int desiredLim, maxLen;
    int maxIdx;

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
        N = 2 * a.size() + 10;
        t.resize(N);
        l.resize(N);
        r.resize(N, a.size());
        p.resize(N);
        s.resize(N);
        lens.resize(N);
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
    }

    void dfs(int node, int len)
    {
        bool isLeaf = true;
        db(node, len, t[node]);
        for (auto &x : t[node])
        {
            if (node == 0 && x.f == '$')
                continue;
            isLeaf = false;
            dfs(x.s, len + r[x.s] - l[x.s]);
            if (lens[node].size() < lens[x.s].size())
                lens[node].swap(lens[x.s]);
            for (auto &x : lens[x.s])
                lens[node].insert(x);
        }
        if (isLeaf)
            lens[node].insert(len - 1);

        db(desiredLim, maxIdx);
        db(node, len, lens[node]);
        if (lens[node].size() && lens[node].size() >= desiredLim)
        {
            int currIdx = a.size() - *(lens[node].begin());
            db(currIdx);
            if (len > maxLen)
            {
                maxLen = len;
                maxIdx = currIdx;
            }
            else if (len == maxLen)
            {
                maxIdx = max(maxIdx, currIdx);
            }
        }
        return;
    }

    void solve(int m)
    {
        desiredLim = m;
        maxLen = 0;
        maxIdx = 0;
        dfs(0, 0);
        if (maxLen == 0)
            cout << "none" << '\n';
        else
            cout << maxLen << ' ' << maxIdx - 1 << '\n';
    }
};

void solveCase()
{
    while (true)
    {
        int m;
        cin >> m;
        if (m == 0)
            break;
        string str;
        cin >> str;
        if (m == 1)
        {
            cout << str.size() << ' ' <<  0 << '\n';
            continue;
        }
        str += '$';
        SuffixTree stree(str);
        stree.solve(m);
        db("\n\n");
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
    {
        solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
