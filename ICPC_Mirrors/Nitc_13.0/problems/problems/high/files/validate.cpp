#include "testlib.h"

using namespace std;

int const MAXN = 200000;
//int const MAXA = 100;
int const MAXQ = 100000;
int const MAXS = 1000000;

int main(int argc, char **argv) {
  registerValidation(argc, argv);
  int n = inf.readInt(1, MAXN, "n");
  inf.readEoln();
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0) inf.readSpace();
    int ai = inf.readInt(1, MAXS, "ai");
    sum += ai;
  }
  ensuref(sum <= MAXS, "sum of all ai = %lld exceeds %d", sum, MAXS);
  inf.readEoln();
  int q = inf.readInt(1, MAXQ, "q");
  inf.readEoln();
  for (int i = 0; i < q; i++) {
    if (i > 0) inf.readSpace();
    inf.readInt(1, (int) sum, "ki");
  }
  inf.readEoln();
  inf.readEof();
}
