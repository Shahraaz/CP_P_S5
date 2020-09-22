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
    int maxUniqueSplit(string s)
    {
        set<string> prev;
        function<int(int)> solve = [&](int pos) -> int {
            if (pos >= s.size())
                return 0;
            int ret = 0;
            for (size_t i = pos; i < s.size(); i++)
            {
                string now = s.substr(pos, i - pos + 1);
                if (prev.find(now) == prev.end())
                {
                    prev.insert(now);
                    ret = max(ret, 1 + solve(i + 1));
                    prev.erase(now);
                }
            }
#ifdef DEBUG
            cout << pos << '\n';
            for (auto &x : prev)
            {
                cout << x << ' ';
            }
            cout << '\n';
#endif
            return ret;
        };
        return solve(0);
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