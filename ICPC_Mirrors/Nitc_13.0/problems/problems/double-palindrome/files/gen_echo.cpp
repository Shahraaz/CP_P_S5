#include "testlib.h"
#include <cassert>

using namespace std;

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  int n = atoi(argv[1]);
  int k = atoi(argv[2]);
  printf("%d %d\n", n, k);
  return 0;
}
