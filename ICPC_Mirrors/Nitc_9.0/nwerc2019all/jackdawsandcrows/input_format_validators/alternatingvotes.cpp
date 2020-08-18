#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

#define MAX_N 500*1000LL
#define MAX_PENALTY 1000*1000*1000LL
#define MAX_VOTE 1000*1000*1000LL

int main() {

  ll n, x, y;

  if(!(cin >> n >> x >> y))
    exit(43);

  if(n < 1 || MAX_N < n || x < 1 || MAX_PENALTY < x || y < 1 || MAX_PENALTY < y)
    exit(43);

  vll a(n);
  while(n--) {
    if(!(cin >> a[n]) || a[n] < -MAX_VOTE || MAX_VOTE < a[n])
      exit(43);
  }

  char foo = '\0';
  if(cin >> foo)
    exit(43);

  if(a.size() == 1) exit(42);

  for(size_t i = 0; i < a.size() - 1; i++) {
    ll test = a[i] * a[i+1];
    if(test >= 0) exit(42);
  }
  exit(43);
}
