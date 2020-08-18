#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

enum Type:int{POS=1,NEG=-1,FLEX=0};

bool exist[500000];
int el[500000],er[500000];
Type type[500000];
ll cost=0;

int succ(int x){return x!=-1 and exist[x]? er[x]: -1;}
int prev(int x){return x!=-1 and exist[x]? el[x]: -1;}
void kill(int x){
  if (x==-1) return;
  if (~el[x]) er[el[x]]=er[x];
  if (~er[x]) el[er[x]]=el[x];
  exist[x]=false;
}

int contributions(int b){
  int a=prev(b),c=succ(b);
  int t=type[b];
  if (t==FLEX){
    if (a==-1 or c==-1) return 0;
    t=-type[a];
  }
  return (c!=-1 and type[c]!=FLEX and t!=-type[c]);
}

void make_flexible(int x){
  if (not exist[x]) return;
  int dirty[5]={prev(prev(x)),prev(x),x,succ(x),succ(succ(x))};
  sort(dirty,dirty+5);
  for (int i=0; i<5; i++) if (dirty[i]!=-1 and (i==0 or dirty[i]!=dirty[i-1]) and exist[dirty[i]]) cost-=contributions(dirty[i]);
  if (prev(x)!=-1 and type[prev(x)]==FLEX){
    kill(prev(x)); kill(x);
  }else if (succ(x)!=-1 and type[succ(x)]==FLEX){
    kill(succ(x)); kill(x);
  }
  type[x]=FLEX;
  for (int i=0; i<5; i++) if (dirty[i]!=-1 and (i==0 or dirty[i]!=dirty[i-1]) and exist[dirty[i]]) cost+=contributions(dirty[i]);
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
  ios::sync_with_stdio(false);
  ll n,x,y; cin>>n>>x>>y;

  vector<pair<ll,int>> vs(n);
  vector<ll> v(n);
  for (int i=0; i<n; i++){
    cin>>v[i];
    vs[i]={abs(v[i]),i};
    exist[i]=true; el[i]=i-1; er[i]=i+1;
    type[i]=(v[i]>0?POS:v[i]<0?NEG:FLEX);
  }
  er[n-1]=-1;
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
