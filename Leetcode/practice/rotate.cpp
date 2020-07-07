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
    pair<int, int> rotate(pair<int, int> inp)
    {
        return {inp.s, -inp.f};
    }

public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        auto findCordinate = [&](int x, int y) -> pair<int, int> {
            int mid = n / 2;
            pair<int, int> ret;
            if (n & 1)
            {
                ret.f = x - mid;
                ret.s = y - mid;
                ret.f = -ret.f;
                swap(ret.f, ret.s);
            }
            else
            {
                if (x < mid)
                    ret.f = x - mid;
                else
                    ret.f = x - mid + 1;
                if (y < mid)
                    ret.s = y - mid;
                else
                    ret.s = y - mid + 1;
                ret.f = -ret.f;
                swap(ret.f, ret.s);
            }
            // ret.s = -ret.s;
            return ret;
        };
        db(findCordinate(0, 0));
        auto inverse = [&](int x, int y) -> pair<int, int> {
            auto topLeft = findCordinate(0, 0);
            pair<int, int> temp = {x - topLeft.f, y + topLeft.s};
            if (n % 2 == 0)
            {
                int mid = n / 2;
                if (temp.f >= mid)
                    temp.f--;
                if (temp.s >= mid)
                    temp.s--;
            }
            // db(x, y, temp);
            return temp;
        };
        set<pair<int, int>> vis;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                auto cord = findCordinate(i, j);
                if (cord.f == 0 && cord.s == 0)
                    continue;
                if (cord.f > 0 || cord.s <= 0)
                    continue;
                vector<pair<int, int>> sides;
                sides.pb(cord);
                for (size_t i = 0; i < 3; i++)
                {
                    auto curr = rotate(sides.back());
                    sides.pb(curr);
                }
                vector<int> vals;
                // db(sides);
                for (auto &x : sides)
                {
                    // db(x, inverse(x.f, x.s))
                    x = inverse(x.f, x.s);
                    vals.pb(matrix[x.f][x.s]);
                }
                for (size_t i = 0; i < 4; i++)
                    matrix[sides[i].f][sides[i].s] = vals[(3 + i) % 4];
                // db(sides);
            }
        }
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
        int n;
        cin >> n;
        vector<vector<int>> temp(n, vector<int>(n));
        S.rotate(temp);
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif