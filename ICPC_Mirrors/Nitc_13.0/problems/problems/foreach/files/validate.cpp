#include "testlib.h"

constexpr int MAXN = 50;
constexpr int MAXV = 100;

int main(int argc, char **argv) {
  registerValidation(argc, argv);
  int n = inf.readInt(1, MAXN, "n");
  inf.readEoln();
  inf.readInts(n, 1, MAXV, "a");
  inf.readEoln();
  inf.readInts(n, 1, MAXV, "b");
  inf.readEoln();
  inf.readEof();
}
