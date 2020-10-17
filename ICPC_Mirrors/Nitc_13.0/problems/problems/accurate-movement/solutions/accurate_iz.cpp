#pragma GCC optimize("O3") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, n;
  while (cin >> a >> b >> n) {
    int pa = a, pb = b;
    int ans = 0;
    while (pa < n || pb < n) {
      ans++;
      if (pa == pb) pb += b - a;
      else pa += b - a;
    }
    cout << ans << endl;
  }
}
