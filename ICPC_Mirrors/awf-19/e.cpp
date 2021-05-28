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

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 rng(seed);
template <typename T>
using Random = std::uniform_int_distribution<T>;
ll low = 100000000000LL, high = 2 * low;
auto r = Random<long long>(low, high);

void solveCase()
{
    /*
        [c1 Y] [c2 1]

        c1 * (c1 - 1) / 2 * Y + (c2) * (c2-1)/2 + c1 * c2 = X

        
    */
    long long y = r(rng);
    db(y);
    y = 1004114344799;
    // cin >> y;
    if (y <= 100000)
    {
        cout << "YES\n"
             << 1 << '\n'
             << y << '\n';
        return;
    }
    //
    for (long long n = 1; n <= 100000; n++)
    {
        auto now = 2 * y - (n) * (n + 1);
        if (now < 0)
            break;
        if (now == 0)
        {
            cout << "YES\n"
                 << n << '\n';
            for (size_t i = 0; i < n; i++)
                cout << 1 << ' ';
            cout << '\n';
            return;
        }
        // now = n1 * (n1 +  1) * (x - 1)
        // if (now <= 100000)
        {
            for (ll n1 = 1; n1 <= n; n1++)
            {
                ll rhs = (n1) * (n1 + 1LL);
                if (now % rhs == 0)
                {
                    auto x_1 = now / rhs + 1;
                    if (x_1 <= 100000)
                    {
                        db(x_1, n1, 1, n);
                        // cout << "YES\n"
                        //      << n << '\n';
                        // for (size_t i = 0; i < n1; i++)
                        //     cout << 1 << ' ';
                        // for (size_t i = n1; i < n; i++)
                        //     cout << x_1 << ' ';
                        // cout << '\n';
                        return;
                    }
                }
            }
        }
    }
    assert(false);
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 30;
    // cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}