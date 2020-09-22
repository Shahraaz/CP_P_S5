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

class Solution
{
public:
    string reorderSpaces(string text)
    {
        int n = text.size();
        vector<string> temp;
        stringstream sin(text);
        int textLen = 0;
        while (sin >> text)
        {
            temp.pb(text);
            textLen += text.size();
        }
        int spaces = n - textLen;
        string ret;
        if (temp.size() == 1)
        {
            ret = temp.front();
            for (size_t i = 0; i < spaces; i++)
                ret += " ";
        }
        else
        {
            bool first = true;
            for (auto &x : temp)
            {
                if (first)
                {
                    first = false;
                }
                else
                    for (size_t i = 0; i < spaces / (temp.size() - 1); i++)
                        ret += " ";
                ret += x;
            }
            for (size_t i = 0; i < spaces % (temp.size() - 1); i++)
                ret += " ";
        }
        return ret;
    }
};

#ifdef LOCAL
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    Solution S;
    for (int i = 1; i <= t; ++i)
    {
        ;
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif