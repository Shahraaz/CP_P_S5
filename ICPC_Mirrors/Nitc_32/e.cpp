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

vector<string> split(string str)
{
    vector<string> ret;
    string curr;
    for (auto &x : str)
    {
        if (x == ':')
        {
            if (curr.size())
            {
                ret.pb(curr);
                curr = "";
            }
        }
        else
        {
            curr += x;
        }
    }
    if (curr.size())
    {
        ret.pb(curr);
        curr = "";
    }
    return ret;
}

int to_int(string h, string m, string s)
{
    int ret = 0;
    ret += stoi(h) * 60 * 60;
    ret += stoi(m) * 60;
    ret += stoi(s);
    db(h, m, s, ret);
    return ret;
}

void solveCase()
{
    int n;
    cin >> n;
    if (n == 0)
        exit(0);
    vector<vector<string>> days;
    for (size_t i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        auto s = split(str);
        // db(str, s);
        days.pb(s);
    }
    int pointdeducted = 0;
    int eight30 = to_int("8", "30", "00");
    int nine30 = to_int("9", "30", "00");
    int twelve30 = to_int("12", "30", "00");
    for (auto &x : days)
    {
        assert(x.size() == 7);
        int start_t = to_int(x[1], x[2], x[3]);
        int end_t = to_int(x[4], x[5], x[6]);
        if (end_t <= eight30)
        {
            pointdeducted++;
            continue;
        }
        start_t = min(start_t, eight30);
        if (x[0] == "D")
        {
            if (start_t > nine30)
            {
                pointdeducted++;
                continue;
            }
        }
        else
        {
            if (start_t > twelve30)
            {
                pointdeducted++;
                continue;
            }
        }
        if (end_t - start_t < to_int("09", "00", "00"))
            pointdeducted++;
    }
    if (pointdeducted == 0)
        cout << "All OK\n";
    else if (pointdeducted >= 3)
    {
        cout << "Issue Show Cause Letter\n";
    }
    else
        cout << pointdeducted << " Point(s) Deducted\n";
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 2;
    // cin >> t;
    for (int i = 1; i <= t;)
        solveCase();
    return 0;
}