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

pair<int, int> a[NAX];
pair<int, int> b[NAX];
int p[NAX];
int n;

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        cin >> n;
        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i].f;
            a[i].s = i;
        }
        for (size_t i = 0; i < n; i++)
        {
            cin >> b[i].f;
            b[i].s = i;
        }
        sort(a, a + n);
        sort(b, b + n);
        for (size_t i = 0; i < n; i++)
        {
            if (a[i].f > b[i].f)
            {
                cout << "No\n";
                return;
            }
        }
        for (size_t i = 0; i + 1 < n; i++)
        {
            if (a[i + 1].f <= b[i].f)
            {
                cout << "Yes\n";
                return;
            }
        }
        for (size_t i = 0; i < n; i++)
            p[a[i].s] = b[i].s;
        int x = 0, len = 0;
        do
        {
            x = p[x];
            len++;
        } while (x != 0);
        if (len == n)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
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
