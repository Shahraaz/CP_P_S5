// Solution by lukasP (Lukáš Poláček)
// Time complexity: O(n^2 k)
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include <cmath>
#include <cstdio>

#define rep(i, a, b) for (__typeof(b) i = (a); (i) < (b); ++(i))

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  ++n;
  std::vector<int> h(n);
  rep(i, 0, n) { scanf("%d", &h[i]); }

  std::vector<int> shifted(n);
  rep(j, 0, k) {
    double q;
    scanf("%lf", &q);
    int r = static_cast<int>(round(q * 10));

    rep(i, 0, n) { shifted[i] = h[i] - i * r; }

    std::vector<std::pair<int, int>> down;
    down.emplace_back(shifted[0], 0);

    double longest = 0;
    for (int i = 0; i < n; ++i) {
      if (down.back().first > shifted[i]) {
        down.emplace_back(shifted[i], i);
      }
      size_t pos = 0;
      while (down[pos].first > shifted[i]) {
        ++pos;
      }

      int end = down[pos].second;
      longest = std::max(longest, static_cast<double>(i - end));
      int capacity = shifted[i] - down[pos].first;
      if (end > 0) {
        double diff = shifted[end - 1] - shifted[end];
        longest = std::max(longest, i - end + std::min(1.0, capacity / diff));
      }
      if (i + 1 < n && shifted[i + 1] != shifted[i]) {
        double diff = shifted[i] - shifted[i + 1];
        longest = std::max(longest, i - end + std::min(1.0, capacity / diff));
      }
    }
    if (longest < 1e-6) {
      printf("impossible\n");
    } else {
      printf("%.9lf\n", longest);
    }
  }
}
