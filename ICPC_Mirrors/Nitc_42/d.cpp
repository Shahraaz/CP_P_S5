#include <bits/stdc++.h>

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

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
#define print(s)          \
    for (ll u : s)        \
        cout << u << " "; \
    cout << "\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;

const int N = 51;
ll dp[N][N][N][N];
ll n, k, tmm;
vector<vector<ll>> pe, te;

ll go(ll pos, ll left, ll ex, ll time)
{
    if (time > tmm || left > n || ex > min(n, k))
        return -1e15;
    if (pos == n)
        return 0;
    if (dp[pos][left][ex][time] != -1)
        return dp[pos][left][ex][time];
    ll ans = 0;
    for (ll i = 0; i < 8; i++)
    {
        ll take = 0, val = 0, tot = 0;
        for (ll j = 0; j < 3; j++)
        {
            if (i & (1 << j))
                val += pe[pos][j], tot += te[pos][j], take++;
        }
        ll exmov = max(0ll, take - 1);
        ans = max(ans, val + go(pos + 1, left + take, ex + exmov, time + tot));
    }
    return dp[pos][left][ex][time] = ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll TT = clock();
    db(mod, -(mod * mod), -(mod * mod) - (mod * mod));
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> tmm;
        pe.assign(n, vector<ll>(3));
        te.assign(n, vector<ll>(3));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < 3; j++)
                cin >> te[i][j];
        }
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < 3; j++)
                cin >> pe[i][j];
        memset(dp, -1, sizeof(dp));
        cout << go(0, 0, 0, 0) << "\n";
    }

    cerr << "\n\nTIME: " << (long double)(clock() - TT) / CLOCKS_PER_SEC << " sec\n";
    TT = clock();
    return 0;
}