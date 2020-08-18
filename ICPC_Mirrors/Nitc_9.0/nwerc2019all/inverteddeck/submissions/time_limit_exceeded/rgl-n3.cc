#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n; cin>>n;
  vector<int> v(n);
  for (int &i: v) cin>>i;

  for (int i=0; i<n; i++){
    if (i>0 and v[i]<v[i-1]) break;
    for (int j=n+1; j-->i;){
      if (j<n-2 and v[j]>v[j+1]) break;
      reverse(v.begin()+i,v.begin()+j);
      if (is_sorted(v.begin(),v.end())){
        cout<<i+1<<" "<<j<<endl;
        return 0;
      }
      reverse(v.begin()+i,v.begin()+j);
    }
  }

  cout<<"impossible"<<endl;
}
