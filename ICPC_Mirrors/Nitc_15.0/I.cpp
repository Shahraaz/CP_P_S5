#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pop_b pop_back
#define pf push_front
#define pop_f pop_front
#define mt make_tuple
#define eb emplace_back
#define sf(x) sizeof(x)
#define len(x) x.length()
#define sz(x) x.size()
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define LB(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define UB(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
typedef long long ll;
typedef pair<ll,ll> ii;
typedef long double ld; 
typedef vector<int> vi;
typedef vector<set<ll>> vset;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef deque<ll> dql;
typedef deque<int> dqi;
typedef unsigned long long ull;
typedef tuple<int,int,int> State;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << ", ";
	err(++it, args...);
	cout<<"\n";
}

#define vmax(type)   std::numeric_limits<type>::max()
#define vmin(type)   std::numeric_limits<type>::min()
#define each(a,x) for( auto &a:(x))
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define rep2(i, l, r) for (ll i = (l); i < (r); i++)
#define rep2r(i, l, r) for (ll i = (r) - 1; i >= (l); i--)
#define range(a) a.begin(), a.end()
#define deb(x) cout<<#x<<" "<<x<<endl;
#define cinai(a, n) vi a(n); rep(i, n) { cin>>a[i]; }
#define cinal(a, n) vl a(n); rep(i, n) { cin>>a[i]; }
#define coutai(a, n) rep(i, n) { cout<<a[i]<<" "; } ent;
#define coutal(a, n) rep(i, n) { cout<<a[i]<<" "; } ent;
#define ent cout<<endl;
#define resize_vec(a) a.resize(unique(a.begin(), a.end()) - a.begin());
#define ms(dp, x) memset(dp, x, sf(dp))
#define endl '\n'

ll powm(ll a, ll b, ll mod) {
	ll res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

const ll mod = 1e9 + 7;
const ll N = 1000005;
const ll inf = 1e9;

void solve()
{
	int n;
	cin>>n;
	cinal(a, n);		
	cinal(b, n);
	sort(range(a));		
	sort(range(b));
	if(n == 1){
		cout<<abs(a[0]-b[0])<<endl;
		return;
	}		
	ll a1 = a[0], a2 = a[n-1], bn = inf, an = inf;
	rep(i, n){
		if(an > abs(a1 - b[i])){
			an = abs(a1 - b[i]);
		}
		if(bn > abs(a2 - b[i])){
			bn = abs(a2 - b[i]);
		}
	}
	cout<<max(an, bn)<<endl;
}

// #define _DEBUG 
// #define testCases
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int tc = 1;
#ifdef testCases
	cin>>tc;
#endif
	while(tc--)
	{
#ifdef _DEBUG
	int tt = clock();
#endif
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}