#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

ll n;
const ll big = 1000000007;

// Does a ternary search on the n+1 relevant numbers of fake accounts.
// Checks the 200 closest values to the local minimum found.
// Also checks the 200 smallest and 200 largest values.

vl A;
vl K;
ll x,y;

ll f(ll i){
    // Finds the answer for K[i] fake accounts, in O(n).
    ll ans = K[i]*x;
    ll last = -1;
    rep(c1,0,n){
        if(abs(A[c1]) < K[i]){
            if(last != -1)last ^= 1;
        }
        else{
            ll sg = (A[c1] > 0);
            if(last == sg || A[c1] == 0){
                ans += y;
            }
            else{
                last = sg;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x >> y;
    K.push_back(0);
    rep(c1,0,n){
        ll a;
        cin >> a;
        A.push_back(a);
        K.push_back(abs(a) + 1);
    }
    sort(all(K));

    ll ans = big*big;

    const ll lim = 200;
    rep(c1,0,min(lim,n)){
        ans = min(ans, f(c1));
        ans = min(ans, f(n-c1));
    }

    ll l = 0;
    ll r = n+1;

    while(l < r-4){
        ll mid1 = (2*l+r)/3;
        ll mid2 = (l+2*r)/3;
        ll a = f(mid1);
        ll b = f(mid2);
        ans = min(ans,a);
        ans = min(ans,b);
        if(a < b){
            r = mid2;
        }
        else{
            l = mid1;
        }
    }

    rep(c1,l-lim, l+lim){
        if(c1 < 0 || c1 > n)continue;
        ans = min(ans, f(c1));
    }

    cout << ans << "\n";

    return 0;
}

