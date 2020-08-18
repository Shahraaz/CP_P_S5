#include <bits/stdc++.h>
using namespace std;

optional<vector<int>> solve(vector<pair<int,int>> const &r,vector<int> const &x){
  vector<int> need(r.size(),2);

  for (int i=0,j=0; i<r.size() and j<x.size();)
    if (x[j]<r[i].first) j++; else if (r[i].second<x[j]) i++;
    else --need[i], (r[i].second<=x[j]?i:j)++;

  vector<int> res;
  for (int i=0,j=0; i<r.size(); i++){
    while (j<0 or j+1<x.size() and x[j+1]<=r[i].second) ++j;
    for (int k=r[i].second; k>=r[i].first and need[i]>0; --k){
      if (0<=j and j<x.size() and x[j]==k) {--j; continue;}
      if (i-1>=0       and k==r[i-1].second and need[i-1]<=0) continue;
      if (i+1<r.size() and k==r[i+1].first and need[i+1]<=0) continue;
      if (i+1<r.size() and k==r[i+1].first) --need[i+1];
      res.push_back(k);
      --need[i];
    }
    if (need[i]!=0){
      return nullopt;
    }
  }
  return res;
}

int main(){
  int n; cin>>n;

  vector<pair<int,int>> rects(n);
  for (int i=0; i<n; i++){
    cin>>rects[i].first>>rects[i].second;
  }

  int m; cin>>m;
  vector<int> x(m);
  for (int i=0; i<m; i++){
    cin>>x[i];
  }

  if (auto const res=solve(rects,x)){
    auto const ans=res.value();
    cout<<ans.size()<<endl;
    cout.precision(2);
    for (auto i: ans)
      cout<<fixed<<(double)i<<" ";
    cout<<endl;
  }else{
    cout<<"impossible"<<endl;
  }
}
