//Solution by lukasP (Lukáš Poláček)
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>

#define rep(i,a,b) for(__typeof(b) i=(a); (i)<(b); ++(i))

int main() {
  std::vector<double> t(4);
  rep(i,0,4) std::cin >> t[i];
  std::sort(t.begin(), t.end());
  double sum = t[0] + t[1] + t[2] + t[3];

  double lead; std::cin >> lead;
  const double eps = 1e-6;
  if (lead * 3 + eps < sum - t[3]) {
    std::cout << "impossible" << std::endl;
  } else if (lead * 3 + eps > sum - t[0]) {
    std::cout << "infinite" << std::endl;
  } else {
    double need = lead * 3 - t[1] - t[2];
    printf("%.2lf\n", need);
  }
}
