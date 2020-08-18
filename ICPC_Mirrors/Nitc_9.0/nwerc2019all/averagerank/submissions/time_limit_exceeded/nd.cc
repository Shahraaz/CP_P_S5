// Sorting all competitors at the end of each day
// Time complexity: O(D N log N)
#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

int main() {
  int n, d;
  scanf("%d %d", &n, &d);
  std::vector<int> points(n, 0);
  std::vector<int64_t> total(n, 0);
  std::vector<std::pair<int, int>> order(n);

  for (int k = 0; k < d; ++k) {
    int m; scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
      int id;
      scanf("%d", &id);
      --id;
      points[id]++;
    }
    for (int i = 0; i < n; ++i) {
      order[i] = std::make_pair(points[i], i);
    }
    std::sort(order.begin(), order.end(), std::greater<std::pair<int, int>>());
    int rank = 1;
    for (int i = 0; i < n; ++i) {
      if (i > 0 && order[i].first != order[i - 1].first) rank = i + 1;
      total[order[i].second] += rank;
    }
  }

  for (int i = 0; i < n; ++i) {
    printf("%.6lf\n", total[i] / double(d));
  }
}
