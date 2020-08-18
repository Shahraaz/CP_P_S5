#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Also works for score increases greater than one.

struct LinearFunction{
  ll c=0;
  ll m=0;
  ll eval(ll const t) const{
    return c+t*m;
  }
};

vector<LinearFunction> fen;

void add(int x,LinearFunction const &f){
  for (int i=x; i<fen.size(); i|=i+1)
    fen[i].c+=f.c,
    fen[i].m+=f.m;
}

LinearFunction get(int x){
  LinearFunction f;
  for (int i=x; i>=0; --(i&=i+1))
    f.c+=fen[i].c,
    f.m+=fen[i].m;
  return f;
}

int main(){
  int n,d; cin>>n>>d;
  vector<int> pts(n);
  vector<ll> total(n);
  fen.resize(d+1);

  for (int t=0; t<d; t++){
    int k; cin>>k;
    vector<int> q(k); for (int &x: q) cin>>x, --x;
    for (int x: q){
      total[x]+=get(pts[x]).eval(t);
      ++pts[x];
    }
    for (int x: q){
      add(pts[x]-1, {-t,+1});
      add(pts[x],   {+t,-1});
    }
    for (int x: q){
      total[x]-=get(pts[x]).eval(t);
    }
  }
  for (int x=0; x<n; x++){
    total[x]+=get(pts[x]).eval(d);
  }
  cout.precision(9);
  for (int i=0; i<n; i++){
    long double const avg=1+total[i]/(long double)d;
    cout<<fixed<<avg<<"\n";
  }
}
