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
        int n, k;
        cin >> n >> k;
        cout << n << ' ' << k << '\n';
        vector<int> v(n);
        vector<bool> vis(n);
        vector<int> pos(n + 1);
        for (size_t i = 0; i < n; i++)
        {
            v[i] = i + 1;
            pos[i + 1] = i;
        }
        int init = 0;
        for (size_t i = 0; (i + 1) < n; i++)
            init += max(v[i], v[i + 1]);
        int maxi = init + n;
        if (k < init || k > maxi)
        {
            cout << -1 << '\n';
            return;
        }
        k -= init;
        int cnt = 1, curr = n - 2, rear = n;
        while (k >= 0 && curr >= 0)
        {
            int mini = min(k, curr);
            if (mini == k)
            {
                db("pref", n, mini, rear, k);
                while (cnt < (rear - mini))
                {
                    cout << cnt << ' ';
                    cnt++;
                }
                db("elem", rear);
                cout << rear << ' ';
                db("suff");
                while (cnt < rear)
                {
                    cout << cnt << ' ';
                    cnt++;
                }
                cout << '\n';
                return;
            }
            cout << cnt << ' ';
            cout << rear << ' ';
            cnt++;
            curr -= 2;
            k -= mini;
            rear--;
        }
        cout << '\n';
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
    cout << t << '\n';
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
