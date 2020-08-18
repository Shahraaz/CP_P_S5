#include <bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> res;
unordered_map<int,vector<int>> e;
unordered_set<int> did;

void dfs(int x,int p=-1){
  did.insert(x);
  for (int y: e[x])
    if (!did.count(y)){
      if (x<0) res.emplace_back(p,y,-x);
      dfs(y,x);
    }
}

int main(){
  int n; cin>>n;
  for (int i=1; i<=n; i++)
    for (int x,j=(cin>>x,x); j--;)
      cin>>x, e[i].push_back(-x), e[-x].push_back(i);
  dfs(1);
  if (res.size()==n-1)
    for (auto i: res)
      cout<<get<0>(i)<<" "<<get<1>(i)<<" "<<get<2>(i)<<endl;
  else
    cout<<"impossible"<<endl;
}
