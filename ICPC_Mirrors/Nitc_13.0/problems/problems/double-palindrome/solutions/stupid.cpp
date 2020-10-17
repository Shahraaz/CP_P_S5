/**
 *    author:  tourist
 *    created: 23.11.2017 20:36:15       
**/
#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

int len, alpha;
long long ans;

void go(string s) {
  if (!s.empty()) {
    string sr = s;
    reverse(sr.begin(), sr.end());
    for (int i = 0; i < (int) s.size(); i++) {
      if (sr.substr(i) + sr.substr(0, i) == s) {
        ans++;
        break;
      }
    }
  }
  if ((int) s.length() == len) {
    return;
  }
  for (int j = 0; j < alpha; j++) {
    go(s + (char) ('a' + j));
  }
}

int main() {
  scanf("%d %d", &len, &alpha);
  ans = 0;
  go("");
  cout << ans % md << endl;
  return 0;
}
