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
    vector<int> spiralOrder(vector<vector<int>> matrix)
    {
        if (matrix.size() == 0)
            return {};
        vector<int> ret;
        auto isValid = [&](int x, int y) {
            if (x < 0 || x >= matrix.size())
                return false;
            if (y < 0 || y >= matrix[0].size())
                return false;
            return matrix[x][y] != -MOD;
        };
        pair<int, int> curr(0, 0);
        pair<int, int> dir(0, 1);
        int cnt = matrix[0].size() * matrix.size();
        while (cnt--)
        {
            // cout << curr.f << ' ' << curr.s << '\n';
            if (!isValid(curr.f + dir.f, curr.s + dir.s))
            {
                if (dir.s == 0)
                    dir.f = -dir.f;
                swap(dir.f, dir.s);
            }
            ret.pb(matrix[curr.f][curr.s]);
            matrix[curr.f][curr.s] = -MOD;
            curr.f += dir.f;
            curr.s += dir.s;
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