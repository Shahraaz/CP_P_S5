#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  vector<int> v(n);
  for (int &i: v) cin>>i;

  int a=-1,b=-1;
  for (int i=0; i+1<n; i++)
    if (a==-1 and v[i]>v[i+1])
      a=i;
    else if (a!=-1 and b==-1 and v[i]<v[i+1])
      b=i+1;

  while (1<=a and a<n and v[a]==v[a-1]) --a;
  while (1<=b and b<n and v[b]==v[b-1]) ++b;

  if (b!=-1 and a==-1) a=0;
  if (a!=-1 and b==-1) b=n;
  if (a==-1 and b==-1) a=0,b=1;
  if (a!=-1 and b!=-1) reverse(v.begin()+a,v.begin()+b);

  if (is_sorted(v.begin(),v.end())){
    cout<<a+1<<" "<<b<<endl;
  }else{
    cout<<"impoSSIBle"<<endl;
  }
}
