#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n; cin>>n;
  vector<int> v(n);
  for (int &i: v) cin>>i;

  vector<int> goodness(n+1);
  for (int i=1; i<n; i++)
    goodness[i]=goodness[i-1]+(v[i]<=v[i-1]);

  for (int i=0; i<n; i++){
    if (i>0 and v[i]<v[i-1]) break;
    if (i+1<n and v[i]<v[i+1]) continue;
    for (int j=n+1; j-->i;){
      if (j<n-1 and v[j]>v[j+1]) break;
      if (j>1 and i<=j-2 and v[j-1]>v[j-2]) continue;
      if (goodness[j-1]-goodness[i]!=j-i-1) continue;
      if ((i==0 or v[i-1]<=v[j-1]) and (j==n or v[i]<=v[j])){
        cout<<i+1<<" "<<j<<endl;
        return 0;
      }
      if (j<n-1 and v[j]==v[j+1]) continue;
    }
    if (i>0 and v[i]==v[i-1]) continue;
  }

  cout<<"impossible"<<endl;
}
