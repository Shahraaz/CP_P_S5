#include "testlib.h"

constexpr int MAXN = 10'000'000;

int main(int argc, char **argv) {
  registerValidation(argc, argv);
  int a = inf.readInt(1, MAXN - 1, "a");
  inf.readSpace();
  int b = inf.readInt(a + 1, MAXN, "b");
  inf.readSpace();
  inf.readInt(b, MAXN, "n");
  inf.readEoln();
  inf.readEof();
}
