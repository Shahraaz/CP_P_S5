// Solution by lukasP (Lukáš Poláček)
#include <vector>
#include <cstdio>

#define rep(i, a, b) for (__typeof(b) i = (a); (i) < (b); ++(i))

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  std::vector<double> mul(n - k + 1);
  mul[0] = k / double(n);
  rep(i, 1, n - k + 1) { mul[i] = mul[i - 1] * (n - k - i + 1) / (n - i); }

  std::vector<double> s(n);
  rep(i, 0, n) scanf("%lf", &s[i]);

  rep(i, 0, n) {
    double res = 0;
    rep(j, 0, mul.size()) {
      int idx = (n + i - j) % n;
      res += mul[j] * s[idx];
    }
    printf("%.9lf", res);
    printf(i + 1 < n ? " " : "\n");
  }
}
