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

int s,d,t,n;
vi R,L;

map<ll,ll> DP;

ll dp(ll x){
    if(x >= s)return 0;
    if(DP.find(x) != DP.end())return DP[x];
    ll x2 = x + d;
    ll j = -1;
    ll ans = 1e15;
    rep(i,0,n+1){
        if(L[i] < x2 && R[i] > x2){
            x2 = L[i];
        }
        if(L[i] >= x && j == -1){
            j = i;
        }
    }

    ll extra_jumps = (R[j] - x - d)/d;
    if(extra_jumps >= 1){
        DP[x] = min(t,d) * extra_jumps + dp(x + extra_jumps * d);
        return DP[x];
    }

    rep(i,j,n+1){
        if(R[i] - d <= L[j]){
            ans = min(ans, max(0ll,R[i] - d - x) + t + dp(R[i]));
        }
    }
    ans = min(ans, t + dp(x2));
    if(j == n){
        ans = min(ans, s-x);
    }
    DP[x] = ans;
    return ans;

}

int main() {
    cin >> s >> d >> t >> n;
    rep(c1,0,n){
        int r,l;
        cin >> l >> r;
        L.push_back(l);
        R.push_back(r);
    }
    L.push_back(s);
    R.push_back(s);
    ll ans = dp(0);
    cout << ans << "\n";

    return 0;
}

