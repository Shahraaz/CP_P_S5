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

struct Trie
{
    int cnt = 0;
    vector<Trie *> child;
    Trie()
    {
        child = vector<Trie *>(26, nullptr);
        cnt = 0;
    }
    void insert(string &s)
    {
        auto curr = this;
        curr->cnt++;
        for (auto &x : s)
        {
            if (curr->child[x - 'a'] == nullptr)
                curr->child[x - 'a'] = new Trie();
            curr = curr->child[x - 'a'];
            curr->cnt++;
        }
    }
    int query(string &s, int checkLen)
    {
        auto curr = this;
        db(s, checkLen);
        for (auto &x : s)
        {
            if (curr->child[x - 'a'] == nullptr)
                break;
            curr = curr->child[x - 'a'];
            db(curr->cnt, checkLen);
            if (curr->cnt < checkLen)
                break;
            checkLen--;
            if (checkLen <= 0)
                break;
        }
        return checkLen <= 0;
    }
};

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        Trie t;
        for (auto &x : a)
        {
            cin >> x;
            // t.insert(x);
        }
        ll res = 0;
        for (size_t i = 0; i < m; i++)
        {
            string str;
            cin >> str;
            t.insert(str);
        }
        for (auto &x : a)
        {
            db("------------");
            // db(t.query(x));
            int lptr = 0, rptr = x.size(), ans = 0;
            while (lptr <= rptr)
            {
                int mid = (lptr + rptr) / 2;
                db(x, mid, t.query(x, mid));
                if (t.query(x, mid))
                {
                    lptr = mid + 1;
                    ans = max(ans, mid);
                }
                else
                    rptr = mid - 1;
            }
            db(x, ans);
            res += ans;
        }
        cout << res << '\n';
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
