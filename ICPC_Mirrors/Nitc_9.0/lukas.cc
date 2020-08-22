//Solution by lukasP (Lukáš Poláček)
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// order[b] - order of bucket b in the ranking
// last_change[b] - the number of day when 'total[b]' was last updated
// total[b] - the sum of ranking positions occupied by bucket b
std::vector<int64_t> order, last_change, total;
void update_bucket(int bucket, int day) {
  total[bucket] += (day - last_change[bucket]) * order[bucket];
  last_change[bucket] = day;
}
int main() {
  int n, d;
  scanf("%d %d", &n, &d);
  // points[i] - number of points of competitor i
  // partial_sum[i] - partial sum of placements of competitor i
  // enter_sum[i] - the "enter sum" of competitor i, i.e. the value of total[points[i]] when
  // competitor i last changed their score
  std::vector<int64_t> points(n, 0), enter_sum(n, 0), partial_sum(n, 0);
  order.assign(d + 1, 0);
  last_change.assign(d + 1, 0);
  total.assign(d + 1, 0);

  for (int k = 0; k < d; ++k) {
    int m; scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
      int id;
      scanf("%d", &id);
      --id;

      int bucket = points[id];
      update_bucket(bucket, k);
      partial_sum[id] += total[bucket] - enter_sum[id];
      ++order[bucket];

      ++points[id];
      bucket = points[id];
      update_bucket(bucket, k);
      enter_sum[id] = total[bucket];
    }
  }

  for (int i = 0; i < n; ++i) {
    update_bucket(points[i], d);
    partial_sum[i] += total[points[i]] - enter_sum[i];
  }

  for (int i = 0; i < n; ++i) {
    printf("%.9lf\n", partial_sum[i] / double(d) + 1);
  }
}
