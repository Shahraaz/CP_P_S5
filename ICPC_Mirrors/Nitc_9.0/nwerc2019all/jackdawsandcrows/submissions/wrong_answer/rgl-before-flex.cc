#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int const POS=1,NEG=-1,FLEX=0;

set<int> exist;
vector<int> type;
ll cost=0;

int succ(int x){
  if (x==-1) return -1;
  auto it=exist.upper_bound(x);
  if (it!=exist.end()) return *it;
  return -1;
}

int prev(int x){
  if (x==-1) return -1;
  auto it=exist.lower_bound(x);
  if (it!=exist.begin()) return *--it;
  return -1;
}

int contributions(int b){
  int a=prev(b),c=succ(b);
  int t=type[b];
  if (t==FLEX){
    if (a==-1 or c==-1) return 0;
    t=-type[a];
  }
  return (c!=-1 /*and type[c]!=FLEX*/ and t!=-type[c]);
}

void make_flexible(int x){
  set<int> dirty; dirty.insert(x);
  dirty.insert(prev(x)); dirty.insert(prev(prev(x)));
  dirty.insert(succ(x)); dirty.insert(succ(succ(x)));
  dirty.erase(-1);
  for (auto i: dirty){
    if (exist.count(i)) cost-=contributions(i);
  }
  if (prev(x)!=-1 and type[prev(x)]==FLEX){
    exist.erase(x); exist.erase(prev(x));
  }else if (succ(x)!=-1 and type[succ(x)]==FLEX){
    exist.erase(x); exist.erase(succ(x));
  }
  type[x]=FLEX;
  for (auto i: dirty){
    if (exist.count(i)) cost+=contributions(i);
  }
}

ll solve_basic(vector<ll> const &v){
  ll last=0;
  ll res=0;
  for (auto i: v)
    if (i==0 or last and last*i>=0) ++res;
    else last=i;
  return res;
}

int main(){
  ll n,x,y; cin>>n>>x>>y;

  type.assign(n,FLEX);
  vector<pair<ll,int>> vs(n);
  vector<ll> v(n);
  for (int i=0; i<n; i++){
    cin>>v[i];
    vs[i]={abs(v[i]),i};
    exist.insert(i);
    type[i]=(v[i]>0?POS:v[i]<0?NEG:FLEX);
  }
  sort(vs.begin(),vs.end());

  for (int i=0; i<n; i++){
    cost+=contributions(i);
  }

  ll res=solve_basic(v)*y;
  if (vs[0].first) res=min(res,cost*y);

  for (auto vsi: vs){
    ll const dist=vsi.first+1;
    make_flexible(vsi.second);
    res=min(res,cost*y+dist*x);
    // cerr<<"cost for "<<dist<<": "<<cost*y+dist*x<<endl;
  }
  cout<<res<<endl;
}
