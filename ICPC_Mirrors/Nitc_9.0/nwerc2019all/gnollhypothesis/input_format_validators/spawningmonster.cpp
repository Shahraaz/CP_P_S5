#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ld eps = 1e-9;

#define MAX_SIZE 500

int main() {

  ll n, k;

  if(!(cin >> n >> k))
    exit(43);

  if(k < 1 || n < k|| MAX_SIZE < n)
    exit(43);

  ld sum = 0;

  while(n--) {
    ld chance;
    if(!(cin >> chance))
      exit(43);
    if (chance < 0) {
        cout << "Negative probability";
        exit(43);
    }
    sum += chance;
  }

  char foo = '\0';
  if(cin >> foo)
    exit(43);

  auto err = fabsl(sum - 100.0);
  if(err > eps) {
      cout << "Bad sum differs from 100.0 by " << err << endl;
      exit(43);
  }

  exit(42);
}
