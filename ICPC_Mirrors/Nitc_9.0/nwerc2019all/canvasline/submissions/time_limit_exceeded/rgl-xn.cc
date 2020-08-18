#include <bits/stdc++.h>
using namespace std;

vector<int> with(vector<pair<int,int>> const &r,int x){
  vector<int> res;
  for (int i=r.size(); i--;)
    if (r[i].first<=x and x<=r[i].second)
      res.push_back(i);
  return res;
}

int main(){
  int n; cin>>n; vector<pair<int,int>> r(n); for (auto &i: r) cin>>i.first>>i.second;
  int m; cin>>m; vector<int> q(m); for (auto &i: q) cin>>i;

  vector<int> interesting;
  for (auto const &i: r) interesting.push_back(i.second);
  for (int x=r.front().first; x<=r.back().second; x++) interesting.push_back(x);

  vector<int> have(n);
  for (int x: q){
    for (auto y: with(r,x)) if (2<++have[y]){
      cout<<"impossible"<<endl;
      return 0;
    }
  }

  set<int> used;
  for (int x: interesting){
    if (binary_search(q.begin(),q.end(),x)) continue;
    if (used.count(x)) continue;
    auto const having=with(r,x);
    bool ok=not having.empty();
    for (auto y: having) ok&=(2>have[y]);
    if (ok){
      for (auto y: having) ++have[y];
      used.insert(x);
    }
  }

  if (find_if_not(have.begin(),have.end(),[](int x){return x==2;})==have.end()){
    cout<<used.size()<<endl;
    for (auto i: used) cout<<i<<" "; cout<<endl;
  }else{
    cout<<"impossible"<<endl;
  }
}
