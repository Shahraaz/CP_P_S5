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

void solveCase()
{
    int n;
    cin >> n;
    map<int, vector<pair<set<int>, set<int>>>> vecc;
    int ctr = 1;
    pair<set<int>, set<int>> temp;
    for (size_t i = 1; i <= n; i++)
    {
        temp.first.insert(i);
        temp.second.insert(i);
    }
    vecc[ctr].push_back(temp);
    vector<int> res(n + 1);
    int cnt = 0;
    for (size_t i = 0; i < 32; i++, ctr++)
    {
        // db(vecc[ctr]);
        vector<int> q;
        for (auto &x : vecc[ctr])
        {
            int sz = x.first.size();
            if (sz == 0)
            {
            }
            else if (sz == 1)
            {
                res[*(x.first.begin())] = *(x.second.begin());
            }
            else
            {
                auto it = x.first.begin();
                for (size_t i = 0; 2 * i < sz; i++)
                {
                    q.push_back(*it);
                    ++it;
                }
            }
        }
        if (q.size() == 0)
            break;
        ++cnt;
        assert(cnt <= 32);
        cout << "ASK " << q.size() << ' ';
        for (auto &x : q)
            cout << x << ' ';
        cout << endl;
        set<int> ss;
        for (size_t i = 0; i < q.size(); i++)
        {
            int x;
            cin >> x;
            ss.insert(x);
        }
        for (auto &x : vecc[ctr])
        {
            int sz = x.first.size();
            if (sz == 0)
            {
            }
            else if (sz == 1)
            {
            }
            else
            {
                auto it1 = x.first.begin();
                pair<set<int>, set<int>> a, b;
                int i = 0;
                for (i = 0; 2 * i < sz; i++)
                {
                    a.first.insert(*it1);
                    ++it1;
                }
                for (; i < sz; i++)
                {
                    b.first.insert(*it1);
                    ++it1;
                }
                for (auto &elem : x.second)
                    if (ss.find(elem) != ss.end())
                        a.second.insert(elem);
                    else
                        b.second.insert(elem);
                assert(a.first.size() == a.second.size());
                assert(b.first.size() == b.second.size());
                assert((a.first.size() + b.first.size()) == x.first.size());
                vecc[ctr + 1].push_back(a);
                vecc[ctr + 1].push_back(b);
            }
        }
    }
    for (auto &x : vecc[ctr])
    {

        assert(x.first.size() == x.second.size());
        assert(x.second.size() == 1);
        if (x.first.size())
            res[*(x.first.begin())] = *(x.second.begin());
    }
    cout << "ANSWER ";
    for (size_t i = 1; i <= n; i++)
        cout << res[i] << ' ';
    cout << endl;
}

int32_t main()
{
#ifndef LOCAL
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    // cout << t << endl;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}