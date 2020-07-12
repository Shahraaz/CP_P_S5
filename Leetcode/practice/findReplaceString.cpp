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
    string findReplaceString(string S, vector<int> &indexes, vector<string> &sources, vector<string> &targets)
    {
        int n = S.length();
        vector<int> decision(n, -1);
        for (size_t i = 0; i < indexes.size(); i++)
            if (S.substr(indexes[i], sources[i].size()) == targets[i])
            {
                decision[indexes[i]] = i;
                for (size_t j = 1; j < sources[i].size(); j++)
                    decision[indexes[i] + j] = -2;
            }
        string ret;
        for (size_t i = 0; i < n; i++)
        {
            cout << i << ' ' << decision[i] << '\n';
            if (decision[i] == -1)
                ret += S[i];
            else if (decision[i] >= 0)
                ret += targets[decision[i]];
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