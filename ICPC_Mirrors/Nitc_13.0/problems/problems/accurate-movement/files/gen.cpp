#include "testlib.h"

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  int C = atoi(argv[1]);
  int CA = std::atoi(argv[2]);
  int n = rnd.next(2, C);
  int b = rnd.next(2, std::min(n, CA));
  int a = rnd.next(1, b - 1);
  printf("%d %d %d\n", a, b, n);
}
