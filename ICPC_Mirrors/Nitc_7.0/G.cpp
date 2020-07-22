#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pop_b pop_back
#define pf push_front
#define pop_f pop_front

typedef long long int ll;
typedef pair<ll,ll> ii;
typedef long double ld; 
typedef vector<int> vi;
#define endl '\n'

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define rep2(i, l, r) for (ll i = (l); i < (r); i++)
#define rep2r(i, l, r) for (ll i = (r) - 1; i >= (l); i--)

const long long MAX_SIZE = 1000005; 
vector<long long >isprime(MAX_SIZE , true); 
vector<long long >prime; 
vector<long long >SPF(MAX_SIZE); 
  
// function generate all prime number less then N in O(n) 
void manipulated_seive(ll N) 
{ 
    isprime[0] = isprime[1] = false ;  
    for (ll i=2; i<N ; i++) 
    {  
        if (isprime[i]) 
        { 
            prime.push_back(i); 
            SPF[i] = i; 
        } 
        for (ll j=0;j < prime.size() && i*prime[j] < N && prime[j] <= SPF[i];j++) 
        { 
            isprime[i*prime[j]]=false; 
            SPF[i*prime[j]] = prime[j] ; 
        } 
    } 
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	manipulated_seive(n+1);
	ll a, b, q;
	cin>>q;
	while(q--)
	{
		cin>>a>>b;
		if(a == b)
			cout<<0<<endl;
		else if(isprime[a] and isprime[b]){
			if(a * b <= n){
				cout<<2<<endl;
			}
			else{
				cout<<-1<<endl;
			}
		}
		else if(__gcd(a, b) == 1 and SPF[a]*SPF[b] > n)
			cout<<-1<<endl;
		else if(__gcd(a, b) == 1 and !isprime[a] and !isprime[b]){
			cout<<4<<endl;
		}
		else{
			if(__gcd(a, b) > 1 and (isprime[a] or isprime[b]))
				cout<<1<<endl;
			else if(__gcd(a, b) > 1 and (!isprime[a] and !isprime[b])) 
				cout<<2<<endl;
			else{
				cout<<3<<endl;
			}
		}
	}
}