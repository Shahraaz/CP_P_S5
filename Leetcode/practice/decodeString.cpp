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
    string decodeString(string s)
    {
        int fptr = 0;
        function<string()> dfs = [&]() -> string {
            string ret = "";
            if (fptr == s.length())
                return ret;
            int num = 0;
            while (fptr < s.length())
            {
                if (s[fptr] <= '9')
                {
                    num = num * 10 + s[fptr] - '0';
                    fptr++;
                }
                else if (s[fptr] == '[')
                {
                    fptr++;
                    auto temp = dfs();
                    while (num--)
                        ret += temp;
                    num = 0;
                }
                else if (s[fptr] == ']')
                {
                    fptr++;
                    return ret;
                }
                else
                {
                    ret += s[fptr];
                    fptr++;
                }
            }
            return ret;
        };
        cout << dfs() << '\n'
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