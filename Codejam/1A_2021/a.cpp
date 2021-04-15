#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

#define all(v) v.begin(), v.end()
#define pb push_back
const int NAX = 2e5 + 5, MOD = 1000000007;

void incrementVector(vector<int> &a)
{
    int n = a.size();

    // Add 1 to last digit and find carry
    a[n - 1] += 1;
    int carry = a[n - 1] / 10;
    a[n - 1] = a[n - 1] % 10;

    // Traverse from second last digit
    for (int i = n - 2; i >= 0; i--)
    {
        if (carry == 1)
        {
            a[i] += 1;
            carry = a[i] / 10;
            a[i] = a[i] % 10;
        }
    }

    // If carry is 1, we need to add
    // a 1 at the beginning of vector
    if (carry == 1)
        a.insert(a.begin(), 1);
}

void solveCase()
{
    int n;
    cin >> n;

    string prev;
    long long res = 0;
    for (size_t i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        db(prev, str);
        if (prev != "")
        { 
            
            if (prev.size() < str.size())
            {
                db("a");
            }
            else if (prev.size() == str.size())
            {
                db("b");
                if (prev < str)
                {
                }
                else
                {
                    str = str + "0";
                    res++;
                }
            }
            else
            {
                db("c");
                vector<int> num;
                for (auto &x : prev)
                    num.pb(x - '0');
                incrementVector(num);
                string next;
                for (auto &x : num)
                    next += '0' + x;
                db(prev, next);
                if (next.size() > prev.size())
                {
                    bool is1 = true;
                    for (size_t i = 0; i < prev.size(); i++)
                        is1 = is1 && (i == 0 ? str[i] == '1' : str[i] == '0');
                    while (str.size() < next.size())
                    {
                        str += "0";
                        res++;
                    }
                    if (is1)
                        str.back() = '1';
                }
                else
                {
                    bool ok = false;
                    for (size_t j = 0; j < str.size(); j++)
                    {
                        if (str[j] < next[j])
                        {
                            ok = true;
                            next += "0";
                            break;
                        }
                        else if (str[j] == next[j])
                        {
                            ;
                        }
                        else
                        {
                            ok = true;
                            break;
                        }
                    }
                    if (ok)
                    {
                        while (str.size() < next.size())
                        {
                            str += "0";
                            res++;
                        }
                    }
                    else
                    {
                        res += next.size() - str.size();
                        str = next;
                    }
                }
            }
        }
        db(prev, str);
        assert(prev.size() < str.size() || (prev.size() == str.size() && prev < str));
        prev = str;
    }
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
        cout << "Case #" << i << ": ";
        solveCase();
    }
    return 0;
}