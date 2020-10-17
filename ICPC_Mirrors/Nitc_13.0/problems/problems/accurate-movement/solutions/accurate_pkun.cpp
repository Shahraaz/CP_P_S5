#include <cstdio>

int main() {
  int n, a, b;
  scanf("%d%d%d", &a, &b, &n);
  printf("%d\n", 1 + 2 * ((n - b + (b - a) - 1) / (b - a)));
  return 0;
}
