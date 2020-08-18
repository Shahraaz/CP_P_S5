#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
vector<long long> l, r;
long long d, t;

int onWater(long x) {
  for(int i = 0; i < n; i++)
    if(l[i] <= x && x <= r[i])
      return i;
  return -1;
}

long long walkingDist(long long x) {
  if(t < d) {
    long ret = t * (x / d);
    ret += min(t, x % d);
    return ret;
  }
  return x;
}


int main() {
  long long s;
  cin>>s>>d>>t;
  cin>>n;
  n++;
  l.push_back(0);
  for(int i = 0; i < n - 1; i++) {
    long long x, y;
    cin>>x>>y;
    r.push_back(x);
    l.push_back(y);
  }
  r.push_back(s);

  set<long long> spts;
  for(int i = 0; i < n; i++) {
    spts.insert(l[i]);
    spts.insert(r[i]);
    for(int j = 0; j < n; j++) {
      long long x;
      x = l[i] + ((l[j] - l[i]) % d + d) % d;
      if(onWater(x) != -1)
	spts.insert(x);
      x = r[i] - ((r[i] - l[j]) % d + d) % d;
      if(onWater(x) != -1)
	spts.insert(x);
      x = l[i] + ((r[j] - l[i]) % d + d) % d;
      if(onWater(x) != -1)
	spts.insert(x);
      x = r[i] - ((r[i] - r[j]) % d + d) % d;
      if(onWater(x) != -1)
	spts.insert(x);
    }
  }

  int m = spts.size();
  vector<long long> pts = vector<long long>(spts.begin(), spts.end());
  vector<int> onwater;
  for(int i = 0; i < m; i++)
    onwater.push_back(onWater(pts[i]));

  vector<long long> dp(m, INT64_MAX);
  dp[0] = 0;
  for(int i = 1; i < m; i++) {
    int j = i - 1;
    while(j >= 0 && (pts[i] - pts[j] <= d || onwater[j] == onwater[i])) {
      if(onwater[j] == onwater[i])
	dp[i] = min(dp[i], dp[j] + walkingDist(pts[i] - pts[j]));
      if(pts[i] - pts[j] <= d)
	dp[i] = min(dp[i], dp[j] + t);
      j--;
    }
  }
  cout<<dp[m-1]<<endl;

  return 0;
}
