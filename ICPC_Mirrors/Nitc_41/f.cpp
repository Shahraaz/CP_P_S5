#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define deb(x) cout << #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define setbits(n) __builtin_popcountll(n)
#define mkunique(a) a.resize(unique(a.begin(), a.end()) - a.begin()); //need to sort
void prints(set<ll> s)
{
    for (ll u : s)
        cout << u << " ";
    cout << "\n";
}
void printms(multiset<ll> s)
{
    for (ll u : s)
        cout << u << " ";
    cout << "\n";
}
void printv(vector<ll> s)
{
    for (ll u : s)
        cout << u << " ";
    cout << "\n";
}
const ll mod = 1e9 + 7;

const int N = 1e5 + 10;
ll dp[N][501][2];
vector<ll> a;
ll n, k;

ll go(ll pos, ll seg, ll ns)
{
    if (pos != n && seg == k)
        return mod * mod;
    if (pos == n)
    {
        if (seg != k)
            return mod * mod;
        return 0;
    }
    if (dp[pos][seg][ns] != -1)
        return dp[pos][seg][ns];
    ll ans = 0;
    if (ns)
        ans = a[pos] + go(pos + 1, seg, 0);
    else
        ans = min(go(pos + 1, seg, 0), -a[pos] + go(pos + 1, seg + 1, 1));
    return dp[pos][seg][ns] = ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll TT = clock();

    ll t = 10;
    // cin >> t;
    while (t--)
    {
        // cin >> n >> k;
        n = 1e4;
        k = 500;
        a.assign(n, 0);
        for (ll i = 0; i < n; i++)
        {
            // cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        memset(dp, -1, sizeof(dp));
        cout << go(0, 0, 1) << "\n";
    }

    cerr << "\n\nTIME: " << (long double)(clock() - TT) / CLOCKS_PER_SEC << " sec\n";
    TT = clock();
    return 0;
}