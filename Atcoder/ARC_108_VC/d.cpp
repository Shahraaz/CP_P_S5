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

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int power(int base, int index)
{
    if (index == 0)
        return 1;
    int temp = power(base, index / 2);
    temp = (temp * 1LL * temp) % MOD;
    if (index & 1)
        temp = (temp * 1LL * base) % MOD;
    return temp;
}

void solveCase()
{
    int n;
    cin >> n;
    char caa, cab, cba, cbb;
    cin >> caa >> cab >> cba >> cbb;
    db(n, caa, cab, cba, cbb);
    if (n <= 3 || (cab == 'B' && cbb == 'B') || (cab == 'A' && caa == 'A'))
    {
        db("xyz");
        cout << 1 << '\n';
    }
    else if (cab == 'B')
    {
        db("a");
        //cab == 'B and cbb = 'A'
        if (cba == 'B')
        {
            db("b");
            vector<int> f(n + 1);
            f[2] = f[3] = 1;
            for (size_t i = 4; i <= n; i++)
                f[i] = add(f[i - 2], f[i - 1]);
            cout << f[n] << '\n';
        }
        else
            cout << power(2, n - 3) << '\n';
    }
    else
    {
        //cab == 'A and cbb = 'B'
        //cab == 'B and cbb = 'A'
        db("c");
        if (cba == 'A')
        {
            db("d");
            vector<int> f(n + 1);
            f[2] = f[3] = 1;
            for (size_t i = 4; i <= n; i++)
                f[i] = add(f[i - 2], f[i - 1]);
            cout << f[n] << '\n';
        }
        else
            cout << power(2, n - 3) << '\n';
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
        solveCase();
    return 0;
}