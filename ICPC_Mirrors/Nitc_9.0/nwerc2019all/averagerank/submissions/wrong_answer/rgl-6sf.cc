#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct LinearFunction{
  ll c=0;
  ll m=0;
  ll eval(ll const t) const{
    return c+t*m;
  }
};

vector<LinearFunction> fun;

int main(){
  ios::sync_with_stdio(false);
  int n,d; cin>>n>>d;
  vector<int> pts(n);
  vector<ll> total(n);
  fun.resize(d+1);

  for (int t=0; t<d; t++){
    int k; cin>>k;
    vector<int> q(k); for (int &x: q) cin>>x, --x;
    for (int x: q) total[x]+=fun[pts[x]].eval(t);
    for (int x: q) fun[pts[x]  ].c-=t, fun[pts[x]++].m++;
    for (int x: q) total[x]-=fun[pts[x]].eval(t);
  }
  for (int x=0; x<n; x++){
    total[x]+=fun[pts[x]].eval(d);
  }
  cout.precision(6);
  for (int i=0; i<n; i++){
    long double const avg=1+total[i]/(long double)d;
    cout<<avg<<"\n";
  }
}
