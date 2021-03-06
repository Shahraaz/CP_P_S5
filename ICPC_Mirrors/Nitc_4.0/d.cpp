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
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        string str;
        cin >> str;
        int n = str.size();
        vector<int> grundy_dp(n, -1);
        vector<int> end_pos(n, -1);
        function<int(int, int)> grundy = [&](int start_ptr, int end_ptr) -> int {
            if (start_ptr + 1 == end_ptr)
                return 1;
            if (end_pos[start_ptr] == end_ptr)
                return 1 + grundy(start_ptr + 1, end_ptr - 1);
            return grundy(start_ptr, end_pos[start_ptr]) ^ grundy(end_pos[start_ptr] + 1, end_ptr);
        };
        stack<int> prev;
        for (size_t i = 0; i < n; i++)
        {
            if (str[i] == '(')
                prev.push(i);
            else
            {
                end_pos[prev.top()] = i;
                prev.pop();
            }
        }
        db(end_pos);
        if (grundy(0, n - 1) == 0)
            cout << "Bob\n";
        else
            cout << "ATM\n";
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    cin >> t;
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
