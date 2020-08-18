#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> p,l,r,h,mh;

priority_queue<int,vector<int>,greater<int>> available;
map<pair<int,int>,vector<int>> waiting;
static int blockers[1<<20];

void schedule(int x){
  for (int i=x,depth=0; i!=-1; depth++, i=p[i]) if (i!=x){
    if (mh[i]<depth){
      waiting[{i,depth}].push_back(x);
      ++blockers[x];
    }
  }
  if (blockers[x]==0){
    available.push(x);
  }
}

int main(){
  ios::sync_with_stdio(false);

  int n,keep,root=-1; cin>>n>>keep;
  p.assign(n,-1); l.assign(n,-1); r.assign(n,-1); h.assign(n,0); mh.assign(n,0);
  for (int i=0; i<n; i++){
    cin>>p[i]; if (~(p[i]--)) (p[i]<i?r:l)[p[i]]=i; else root=i, h[i]=1, p[i]=-1;
  }
  vector<bool> res(n);

  available.push(root);
  for (int used=0; used<keep; used++){
    if (available.empty()){
      cout<<"impossible"<<endl;
      return 1;
    }
    int x=available.top(); available.pop();
    for (int i=x,j=1; i!=-1; i=p[i], j++){
      int nmh=(l[i]!=-1 and r[i]!=-1)? 1+min(h[l[i]],h[r[i]]): 1;
      if (l[i]!=-1) h[i]=max(h[i],h[l[i]]+1);
      if (r[i]!=-1) h[i]=max(h[i],h[r[i]]+1);
      while (mh[i]<nmh){
        ++mh[i];
        for (auto y: waiting[{i,mh[i]}]){
          if (not --blockers[y]){
            available.push(y);
          }
        }
      }
    }
    if (l[x]!=-1) schedule(l[x]);
    if (r[x]!=-1) schedule(r[x]);
    res[x]=true;
  }

  for (auto i: res) cout<<i; cout<<endl;
}
