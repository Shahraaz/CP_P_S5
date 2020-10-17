#include "testlib.h"
#include <cassert>

using namespace std;

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  int maxn = atoi(argv[1]);
  int maxk = atoi(argv[2]);
  printf("%d %d\n", rnd.next(1, maxn), rnd.next(1, maxk));
  return 0;
}
