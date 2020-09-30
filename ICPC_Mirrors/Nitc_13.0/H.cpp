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

void solveCase()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    auto b = a;
    for (size_t i = 1; i < n; i++)
        b[i] = b[i - 1] + a[i];
    int sum = b.back();
    int maxCodeBlock = *max_element(all(a));
    vector<int> ans(sum + 1, -1);
    db(sum, maxCodeBlock);
    db(a, b);
    int q;
    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;
        if (k < maxCodeBlock)
        {
            cout << "Impossible\n";
            continue;
        }
        if (ans[k] < 0)
        {
            int curr = 0;
            int curAns = 0;
            int alreadyHave = 0;
            while (curr < n)
            {
                int left = curr - 1, right = n;
                db(curr, alreadyHave, curAns);
                while (left < right - 1)
                {
                    int mid = (left + right) >> 1;
                    db(curr, alreadyHave, curAns, left, right, mid);
                    if (b[mid] - alreadyHave > k)
                        right = mid;
                    else
                        left = mid;
                }
                alreadyHave = b[left];
                curr = left + 1;
                curAns++;
            }
            ans[k] = curAns;
        }
        cout << ans[k] << '\n';
    }
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
