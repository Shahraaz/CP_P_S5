// Solution by lukasP (Lukáš Poláček)
// Time complexity: O(n^2 k)
#include <emmintrin.h>
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
  alignas(16) int stair[n];
  alignas(16) int ids[n];

  rep(j, 0, k) {
    double q;
    scanf("%lf", &q);
    int r = static_cast<int>(round(q * 10));

    rep(i, 0, n) { shifted[i] = h[i] - i * r; }

    stair[0] = shifted[0];
    ids[0] = 0;
    int cnt = 1;

    double longest = 0;
    __m128i all_ones = _mm_set1_epi16(0xff);
    for (int i = 0; i < n; ++i) {
      if (stair[cnt - 1] > shifted[i]) {
        stair[cnt] = shifted[i];
        ids[cnt] = i;
        ++cnt;
      }
      __m128i cur = _mm_set_epi32(shifted[i], shifted[i], shifted[i], shifted[i]);

      size_t pos = 0;
      while (pos + 3 < cnt) {
        __m128i a = _mm_load_si128((__m128i *)&stair[pos]);
        int cmp = _mm_movemask_epi8(_mm_cmplt_epi32(cur, a));
        if (cmp < 0xffff) {
          break;
        }
        pos += 4;
      }

      while (pos < cnt && stair[pos] > shifted[i]) {
        ++pos;
      }

      int end = ids[pos];
      longest = std::max(longest, static_cast<double>(i - end));
      int capacity = shifted[i] - stair[pos];
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
