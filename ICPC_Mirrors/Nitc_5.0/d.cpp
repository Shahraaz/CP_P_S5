#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout << #x << " " << x << "\n";
#define INF 9223372036854775807
const ll mod = 998244353;

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return -1;
    // cout << "Inverse doesn't exist";
    // m is added to handle negative x
    ll res = (x % m + m) % m;
    // cout << "Modular multiplicative inverse is " << res;
    return res;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll a, n;
        cin >> a >> n;
        // if (a == 1)
        // {
        //     cout << n + 1 << '\n';
        //     continue;
        // }
        // cout << a << ' ' << n << ' ' << gcd(a, n) << '\n';
        // db(a, n, gcd(a, n));
        if (gcd(a, n) > 1)
            cout << -1 << "\n";
        else
        {
            ll res = modInverse(a, n);
            // cout << inv * (a - 1) << '\n';
            // ll res = (inv * (a - 1)) % a;
            // cout << res << '\n';
            // res = (res * n + 1) / a;
            if (res == 0)
                res = n;
            cout << res << '\n';
            // cout << ((inv * n) % a) << '\n';
            // ll temp = (inv * n) % a;
            // // temp = temp;
            // cout << temp << '\n';
        }
    }
    return 0;
}