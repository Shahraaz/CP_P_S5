#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

#define all(v) v.begin(), v.end()
#define pb push_back
using ll = long long;
const int NAX = 2e5 + 5, MOD = 1000000007;

void solveCase()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    function<int()> do_it = [&]() -> int {
        int res = 2;
        vector<int> diff(n - 1);
        for (int i = 0; i + 1 < n; i++)
            diff[i] = a[i + 1] - a[i];
        vector<int> samelen(n - 1);
        db(diff);
        for (int i = diff.size() - 1; i >= 0; i--)
        {
            if (i + 1 < diff.size() && diff[i] == diff[i + 1])
                samelen[i] = samelen[i + 1] + 1;
            else
                samelen[i] = 1;

            res = max(res, samelen[i] + 1);
            int rptr = i + samelen[i];
            db(i, diff[i], samelen[i], rptr);
            if (rptr < diff.size())
            {
                assert(diff[rptr] != diff[i]);
                db(rptr, diff[rptr]);
                res = max(res, samelen[i] + 2);
                if (rptr + 1 < diff.size())
                {
                    int temp = diff[rptr + 1] + diff[rptr];
                    db(rptr + 1, diff[rptr + 1], temp);
                    if (temp % 2 == 0)
                    {
                        temp /= 2;
                        if (diff[i] == temp)
                        {
                            res = max(res, samelen[i] + 3);
                            if (rptr + 2 < diff.size() && diff[rptr + 2] == diff[i])
                                res = max(res, samelen[i] + 2 + samelen[rptr + 2] + 1);
                        }
                    }
                }
            }
            else
            {
                if (i > 0)
                    res = max(res, samelen[i] + 2);
            }
        }
        return res;
    };
    auto res = do_it();
    reverse(all(a));
    res = max(res, do_it());
    cout << res << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solveCase();
    }
    return 0;
}