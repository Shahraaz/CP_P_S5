#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;

#define all(v) v.begin(), v.end()
#define pb push_back
using ll = long long;
const int NAX = 2e5 + 5, MOD = 1000000007;

void solveCase()
{
    int n, k;
    n = k = 50;
    cin >> n >> k;
    // if (n < k)
    // {
    //     cout << 0 << '\n';
    //     return;
    // }
    vector<ll> boxes(n);
    ll temp = 8;
    for (auto &x : boxes)
    {
        x = temp;
        temp *= 2;
        cin >> x;
    }
    sort(all(boxes));
    ll a, b;
    a = 1e18, b = 1e18;
    cin >> a >> b;
    auto ncr = [](int n, int r) -> ll {
        if (r > n || n < 0 || r < 0)
            return 0;
        __int128_t num = 1, den = 1;
        r = min(r, n - r);
        for (int i = 1; i <= r; i++)
        {
            num *= n - r + i;
            num /= i;
        }
        db(n, r, (long long)num);
        assert(num <= LLONG_MAX);
        return num;
    };
    // db(ncr(50, 25));
    set<int> ss;
    function<ll(ll, int, int)> ways = [&](ll target, int boxcount, int rptr) -> ll {
        if (boxcount == 0)
            return 1;
        if (boxcount < 0 || target < 0 || target < boxes[0])
            return 0;
        int i = 0;
        for (; i < rptr; i++)
            if (target < boxes[i])
                break;
        auto dontchose = ncr(i - 1, boxcount);
        auto chose = 0LL;
        if (ss.count(i) == 0)
        {
            ss.insert(i);
            chose = ways(target - boxes[i - 1], boxcount - 1, i);
        }
        db(i, rptr, target, boxcount, dontchose, chose);
        return chose + dontchose;
    };
    db(boxes);
    auto one = ways(b, k, n);
    ss.clear();
    one -= ways(a - 1, k, n);
    cout << one << '\n';
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
        solveCase();
    return 0;
}