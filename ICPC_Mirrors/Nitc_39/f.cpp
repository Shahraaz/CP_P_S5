#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

#define all(v) v.begin(), v.end()
#define pb push_back
const int NAX = 2e5 + 5, MOD = 1e9 + 7;

vector<int> maxlen(string str)
{
    vector<int> ret;
    int len = 0;
    char prev = '$';
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == prev)
        {
            len++;
        }
        else
        {
            if (len)
                ret.pb(len);
            prev = str[i];
            len = 1;
        }
    }
    if (len)
        ret.pb(len);
    if (str.size() > 1 && str.front() == str.back())
    {
        ret.front() += ret.back();
        ret.pop_back();
    }
    db(str, ret);
    return ret;
}

int solve(string str)
{
    int n = str.size();
    vector<int> vecc = maxlen(str);
    if (vecc.size() == 1)
        return n - 1;
    db(str, vecc);
    int ret = MOD;
    multiset<int> ss;
    for (int i = 0; i < vecc.size(); i++)
        ss.insert(vecc[i]);
    int sz = vecc.size();
    for (int i = 0; i < vecc.size(); i++)
    {
        db(i, ret, vecc[i], ss);
        if (vecc[i] == 1)
        {
            if (vecc.size() == 2)
            {
                ret = min(ret, n);
                continue;
            }

            ss.erase(ss.find(vecc[i]));
            ss.erase(ss.find(vecc[(i - 1 + sz) % sz]));
            ss.erase(ss.find(vecc[(i + 1 + sz) % sz]));

            int temp = vecc[(i - 1 + sz) % sz] + 1 + vecc[(i + 1 + sz) % sz];

            ss.insert(temp);

            db(ss);
            ret = min(ret, *ss.rbegin());

            ss.erase(ss.find(temp));

            ss.insert(vecc[i]);
            ss.insert(vecc[(i - 1 + sz) % sz]);
            ss.insert(vecc[(i + 1 + sz) % sz]);
        }
        else if (vecc[i] == 2)
        {
            if (vecc.size() == 2)
            {
                ret = min(ret, n - 1);
                continue;
            }
            db("part1", ss);
            ss.erase(ss.find(vecc[i]));
            ss.erase(ss.find(vecc[(i - 1 + sz) % sz]));

            int temp = vecc[(i - 1 + sz) % sz] + 1;

            ss.insert(temp);
            ss.insert(vecc[i] - 1);

            db(ss);
            ret = min(ret, *ss.rbegin());

            ss.erase(ss.find(temp));
            ss.erase(ss.find(vecc[i] - 1));

            ss.insert(vecc[i]);
            ss.insert(vecc[(i - 1 + sz) % sz]);

            // part 2
            db("part2", ss);

            ss.erase(ss.find(vecc[i]));
            ss.erase(ss.find(vecc[(i + 1 + sz) % sz]));

            temp = vecc[(i + 1 + sz) % sz] + 1;

            ss.insert(temp);
            ss.insert(vecc[i] - 1);

            db(ss);
            ret = min(ret, *ss.rbegin());

            ss.erase(ss.find(temp));
            ss.erase(ss.find(vecc[i] - 1));

            ss.insert(vecc[i]);
            ss.insert(vecc[(i + 1 + sz) % sz]);
        }
        else
        {
            ss.erase(ss.find(vecc[i]));

            int div = (vecc[i] - 1);
            ss.insert(div / 2);
            ss.insert(div - div / 2);
            ss.insert(1);

            db(ss);
            ret = min(ret, *ss.rbegin());

            ss.erase(ss.find(div / 2));
            ss.erase(ss.find(div - div / 2));
            ss.erase(ss.find(1));

            ss.insert(vecc[i]);
        }
    }
    db(vecc);
    return ret;
}

void solveCase()
{
    string str;
    cin >> str;
    int res = solve(str);
    for (auto &x : str)
        x = 'A' ^ 'R' ^ x;
    res = min(res, solve(str));
    cout << res << '\n';
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
        cout << "Case " << i << ": ";
        solveCase();
    }
    return 0;
}