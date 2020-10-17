#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)1e3;
const int MAX_C = (int)1e8;

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  int n = inf.readInt(1, MAX_N, "n");
  inf.readEoln();
  for (int i = 0; i < n; i++) {
    inf.readInt(-MAX_C, +MAX_C, format("x[%d]", i + 1));
    inf.readSpace();
    inf.readInt(-MAX_C, +MAX_C, format("y[%d]", i + 1));
    inf.readSpace();
    inf.readInt(1, +MAX_C, format("h[%d]", i + 1));
    inf.readEoln();
  }
  inf.readEof();
}
