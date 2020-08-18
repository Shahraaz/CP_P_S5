#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<ll> const &x,ll diff,bool first=true){
  int res=0;
  if (diff==0 and first){
    vector<ll> y;
    for (int i=0; i<x.size(); i++) if (x[i]==0) ++res; else y.push_back(x[i]);
    return res+solve(y,0,false);
  }
  int i=0; while (i<x.size() and diff>abs(x[i])) ++i;
  bool pos=(i<x.size() and x[i]<0);
  for (++i; i<x.size(); i++){
    auto xi=x[i];
    if (pos and diff>abs(xi)) xi+=diff;
    else if (not pos and diff>abs(xi)) xi-=diff;
    if (pos and xi<0) ++res; else if (not pos and xi>0) ++res; else pos=not pos;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  ll n,x,y; cin>>n>>x>>y;

  set<ll> diffs={0ll};
  vector<ll> v(n);
  for (int i=0; i<n; i++){
    cin>>v[i];
    diffs.insert(abs(v[i])+1);
  }

  ll res=y*n;
  for (ll i: diffs){
    res=min(res,x*i+y*solve(v,i));
    // cerr<<" answer "<<i<<" = "<<x*i+y*solve(v,i)<<endl;
  }
  cout<<res<<endl;
}
