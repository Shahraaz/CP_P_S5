#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout << #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define PI 3.141592653589
#define setbits(n) __builtin_popcountll(n)
#define mkunique(a) a.resize(unique(a.begin(), a.end()) - a.begin());
const ll mod = 1e9 + 7;

ll n, k, lc, pc, lm, pm, t, d, INF = 1e15;

ll cost(ll m, vector<ll> a)
{
    ll tot = 0, r = n, last = n - 1;
    ll donable = 0, donorsNeeded = 0;
    for (ll i = 0; i < m; i++)
    {
        if (a[i] < lc)
        {
            if (lc - a[i] > d)
                return INF;
            donorsNeeded += (lc - a[i]);
        }
        else
            donable += min(d, a[i] - lc);
    }
    ll passengers = m * (k - 1);
    passengers = min(passengers, n - m);
    // cout << "m " << m << '\n';
    // cout << "passengers " << passengers << '\n';
    for (ll i = n - 1; i >= n - passengers; i--)
        donable += min(d, a[i] - 1);
    ll cost = m * pc;
    for (int i = m; i < (n - passengers); i++)
    {
        cost += pm;
        if (a[i] > lm)
            donable += min(d, a[i] - lm);
        else
        {
            if (lm - a[i] > d)
                return INF;
            donorsNeeded += lm - a[i];
        }
    }
    // cout << "donable " << donable << '\n';
    // cout << "donorsNeeded " << donorsNeeded << '\n';
    if (donable < donorsNeeded)
        return INF;
    return cost + donorsNeeded * t;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T = clock();

    cin >> n >> k;
    cin >> lc >> pc >> lm >> pm;
    cin >> t >> d;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
    int l = 0, high = n;
    ll ans = INF;
    while (l + 500 <= high)
    {
        int mid1 = (l + l + high) / 3;
        int mid2 = (l + high + high) / 3;
        auto one = cost(mid1, a);
        auto two = cost(mid2, a);
        ans = min(ans, one);
        ans = min(ans, two);
        if (one <= two)
            high = mid2;
        else
            l = mid1;
    }

    for (ll i = l; i <= high; i++)
    {
        auto c = cost(i, a);
        ans = min(ans, c);
        // cout << i << ": " << c << "\n";
    }

    if (ans >= INF)
        ans = -1;
    cout << ans << '\n';

    cerr << "\n\nTIME: " << (double)(clock() - T) / CLOCKS_PER_SEC << " sec\n";
    T = clock();
    return 0;
}