#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define setbits(n) __builtin_popcountll(n)
#define mkunique(a) a.resize(unique(a.begin(),a.end())-a.begin()); //need to sort
void prints(set<ll> s) {for(ll u: s) cout<<u<<" "; cout<<"\n";}
void printms(multiset<ll> s) {for(ll u: s) cout<<u<<" "; cout<<"\n";}
void printv(vector<ll> s) {for(ll u: s) cout<<u<<" "; cout<<"\n";}
const ll mod=1e9+7;

ll mpow(ll x, ll y, ll mod){ 
    ll res = 1;
    x = x % mod;
    while (y > 0) { 
        if (y & 1) res = (res * x) % mod; 
        y = y >> 1;
        x = (x * x) % mod; 
    } 
    return res; 
} 

ll modInv(ll n,ll mod){ 
    return mpow(n,mod-2,mod); 
} 

struct Hash_RabinKarp
{
    const int maxSize = 1e6 + 10;
    const long long p1 = 805306457, p2 = 29, p3 = 31;
    const int mod1 = 1610612741, mod2 = 2100003221, mod3 = 1e9 + 9;
    vector<long long> p_pow1, p_pow2, p_pow3;
    vector<long long> inv_pow1, inv_pow2, inv_pow3;
    ll expo(ll base, int index, int mod)
    {
        if (index == 0)
            return 1;
        ll temp = expo(base, index / 2, mod);
        temp = (temp * temp) % mod;
        if (index & 1)
            temp = (temp * base) % mod;
        return temp;
    }
    Hash_RabinKarp()
    {
        p_pow1.resize(maxSize);
        p_pow2.resize(maxSize);
        p_pow3.resize(maxSize);
        inv_pow1.resize(maxSize);
        inv_pow2.resize(maxSize);
        inv_pow3.resize(maxSize);
        p_pow1[0] = p_pow2[0] = p_pow3[0] = 1;
        for (int i = 1; i < (int)p_pow1.size(); i++)
        {
            p_pow1[i] = (p_pow1[i - 1] * p1) % mod1;
            p_pow2[i] = (p_pow2[i - 1] * p2) % mod2;
            p_pow3[i] = (p_pow3[i - 1] * p3) % mod3;
        }
        inv_pow1[maxSize - 1] = expo(p_pow1[maxSize - 1], mod1 - 2, mod1);
        inv_pow2[maxSize - 1] = expo(p_pow2[maxSize - 1], mod2 - 2, mod2);
        inv_pow3[maxSize - 1] = expo(p_pow3[maxSize - 1], mod3 - 2, mod3);
        for (int i = maxSize - 2; i >= 0; --i)
        {
            inv_pow1[i] = (inv_pow1[i + 1] * p1) % mod1;
            inv_pow2[i] = (inv_pow2[i + 1] * p2) % mod2;
            inv_pow3[i] = (inv_pow3[i + 1] * p3) % mod3;
        }
    }
} hashTables;
 
struct Rabin_Karp
{
    int valLen;
    Rabin_Karp()
    {
        valLen = 0;
    }
    Rabin_Karp(vector<ll> a)
    {
        prepareString(a);
    }
    vector<pair<long long, pair<long long, long long>>> hashUptoIndex;
    pair<long long, pair<long long, long long>> gethash(int startIndex, int endIndex)
    {
        if (startIndex > endIndex || startIndex < 0 || startIndex >= valLen || endIndex < 0 || endIndex >= valLen)
            return {0, {0, 0}};
        long long a = (hashUptoIndex[endIndex].first - (startIndex ? hashUptoIndex[startIndex - 1].first : 0) + hashTables.mod1) % hashTables.mod1;
        long long b = (hashUptoIndex[endIndex].second.first - (startIndex ? hashUptoIndex[startIndex - 1].second.first : 0) + hashTables.mod2) % hashTables.mod2;
        long long c = (hashUptoIndex[endIndex].second.second - (startIndex ? hashUptoIndex[startIndex - 1].second.second : 0) + hashTables.mod3) % hashTables.mod3;
        a = (a * hashTables.inv_pow1[startIndex]) % hashTables.mod1;
        b = (b * hashTables.inv_pow2[startIndex]) % hashTables.mod2;
        c = (c * hashTables.inv_pow3[startIndex]) % hashTables.mod3;
        auto ret = make_pair(a, make_pair(b, c));
        return ret;
    }
    void prepareString(vector<ll> text)
    {
        int n = text.size();
        valLen = n;
        hashUptoIndex.resize(n);
        for (int i = 0; i < n; ++i)
        {
            hashUptoIndex[i].first = (((i > 0) ? (hashUptoIndex[i - 1].first) : (0)) + text[i] * hashTables.p_pow1[i]) % hashTables.mod1;
            hashUptoIndex[i].second.first = (((i > 0) ? (hashUptoIndex[i - 1].second.first) : (0)) + text[i] * hashTables.p_pow2[i]) % hashTables.mod2;
            hashUptoIndex[i].second.second = (((i > 0) ? (hashUptoIndex[i - 1].second.second) : (0)) + text[i] * hashTables.p_pow3[i]) % hashTables.mod3;
        }
    }
};

pair<ll, pair<ll,ll>> gethash(vector<ll> text, ll k){
    int n = text.size();
    vector<pair<ll, pair<ll,ll>>> h(n);
    ll p1 = hashTables.p1, p2 = hashTables.p2, p3 = hashTables.p3;
    ll m1 = hashTables.mod1, m2 = hashTables.mod2, m3 = hashTables.mod3;
    ll gp1 = (mpow(p1,k,m1)-1)*modInv(p1-1,m1)%m1;
    ll gp2 = (mpow(p2,k,m2)-1)*modInv(p2-1,m2)%m2;
    ll gp3 = (mpow(p3,k,m3)-1)*modInv(p3-1,m3)%m3;
    for (int i = 0; i < n; ++i){
        ll mp1=mpow(p1,i*k,m1)*gp1%m1, mp2=mpow(p2,i*k,m2)*gp2%m2, mp3=mpow(p3,i*k,m3)*gp3%m3;
        h[i].ff = (((i > 0) ? (h[i - 1].ff) : (0)) + text[i] * mp1) % m1;
        h[i].ss.ff = (((i > 0) ? (h[i - 1].ss.ff) : (0)) + text[i] * mp2) % m2;
        h[i].ss.ss = (((i > 0) ? (h[i - 1].ss.ss) : (0)) + text[i] * mp3) % m3;
    }
    return h[n-1];
}
  
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll TT=clock();


    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> c(n), h(m);
        for(ll i=0;i<n;i++)
            cin>>c[i];
        for(ll i=0;i<m;i++)
            cin>>h[i];
        Rabin_Karp rk(c);
        ll r=n/m+2;
        vector<pair<ll, pair<ll,ll>>> b(r);
        for(ll i=1;i<r;i++)
            b[i]=gethash(h,i);
        ll k=0;
        while(h[k]==h[0]) k++;
        ll cnt=0, len=0;
        ll ans=0;
        //cout<<rk.gethash(0,3).ff<<" "<<rk.gethash(0,3).ss.ff<<","<<rk.gethash(0,3).ss.ss<<"\n";
        //cout<<b[1].ff<<" "<<b[1].ss.ff<<","<<b[1].ss.ss<<"\n";
        for(ll i=n-1;i>=0;i--){
            len++;
            if(c[i]!=h[0]){
                cnt=0;
                continue;
            }
            cnt++;
            if(cnt%k==0){
                ll pow = cnt/k;
                if(m*pow<=len){
                    //cout<<i<<" "<<pow<<"\n";
                    if(rk.gethash(i,i+m*pow-1)==b[pow]){
                        //cout<<i<<"\n";
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }


 
    cerr<<"\n\nTIME: "<<(long double)(clock()-TT)/CLOCKS_PER_SEC<<" sec\n";
    TT = clock();
    return 0;
}