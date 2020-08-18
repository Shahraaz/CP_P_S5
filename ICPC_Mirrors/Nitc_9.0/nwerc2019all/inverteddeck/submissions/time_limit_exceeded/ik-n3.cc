#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vs;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    vs.push_back(v);
  }

  if (is_sorted(vs.begin(),vs.end())) {
    cout << 1 << " " << 1 << endl;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n+1; j++) {
      reverse(vs.begin()+i, vs.begin()+j);
      if (is_sorted(vs.begin(),vs.end())) {
        cout << i+1 << " " << j << endl;
        return 0;
      } else {
        reverse(vs.begin()+i, vs.begin()+j);
      }
    }
  }

  cout<<"impossible"<<endl;
  return 0;
}
