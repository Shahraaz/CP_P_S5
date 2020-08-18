//Solution by lukasP (Lukáš Poláček)
#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i,a,b) for(__typeof(b) i=(a); (i)<(b); ++(i))

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> v(n + 1);
  v[0] = 0;
  rep(i,0,n) {
    scanf("%d", &v[i + 1]);
  }

  size_t start = 0;
  while (start + 1 < v.size() && v[start] <= v[start + 1]) ++start;
  while (v[start] == v[start - 1]) --start;

  size_t end = start;
  while (end + 1 < v.size() && v[end] >= v[end + 1]) ++end;
  std::reverse(v.begin() + start, v.begin() + end + 1);

  if (std::is_sorted(v.begin(), v.end())) {
    std::cout << start << " " << end << std::endl;
  } else {
    std::cout << "impossible" << std::endl;
  }
}
