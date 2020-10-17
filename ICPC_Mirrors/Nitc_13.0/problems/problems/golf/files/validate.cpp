#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int MIN_C = (int) 4;
const int MAX_C = (int) 5e8;
const int MIN_N = (int) 4;
const int MAX_N = (int) 1000;
const int MIN_T = (int) 1;
const int MAX_T = (int) 100;

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  int w = inf.readInt(MIN_C, MAX_C, "w");
  inf.readSpace();
  int h = inf.readInt(MIN_C, MAX_C, "h");
  inf.readEoln();
  int n = inf.readInt(MIN_N, MAX_N, "n");
  inf.readEoln();
  vector<int> x(n + 1), y(n + 1);
  for (int i = 0; i < n; i++) {
    x[i] = inf.readInt(1, w - 1, "x_" + to_string(i + 1));
    inf.readSpace();
    y[i] = inf.readInt(1, h - 1, "y_" + to_string(i + 1));
    inf.readEoln();
  }
  x[n] = x[0];
  y[n] = y[0];
  for (int i = 0; i < n; i++) {
    ensuref(x[i] == x[i + 1] || y[i] == y[i + 1], "non-perpendicular edge: %d", i + 1);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ensuref(i == j || x[i] != x[j] || y[i] != y[j], "equal vertices: %d and %d", i + 1, j + 1);
      if (x[j] == x[j + 1]) {
        ensuref(x[i] != x[j] || y[i] <= min(y[j], y[j + 1]) || max(y[j], y[j + 1]) <= y[i], "vertex %d lies on edge %d", i + 1, j + 1);
      } else {
        ensuref(y[i] != y[j] || x[i] <= min(x[j], x[j + 1]) || max(x[j], x[j + 1]) <= x[i], "vertex %d lies on edge %d", i + 1, j + 1);
      }
      if (i != j) {
        ensuref(max(x[i], x[i + 1]) <= min(x[j], x[j + 1]) || max(x[j], x[j + 1]) <= min(x[i], x[i + 1]) ||
                max(y[i], y[i + 1]) <= min(y[j], y[j + 1]) || max(y[j], y[j + 1]) <= min(y[i], y[i + 1]),
               "edges %d and %d intersect", i + 1, j + 1);
      }
    }
  }
  int t = inf.readInt(MIN_T, MAX_T, "t");
  inf.readEoln();
  for (int i = 0; i < t; i++) {
    int xs = inf.readInt(1, w - 1, "xs_" + to_string(i + 1));
    inf.readSpace();
    int ys = inf.readInt(1, h - 1, "ys_" + to_string(i + 1));
    inf.readEoln();
    for (int j = 0; j < n; j++) {
      ensuref(!(min(x[j], x[j + 1]) <= xs && xs <= max(x[j], x[j + 1]) &&
                min(y[j], y[j + 1]) <= ys && ys <= max(y[j], y[j + 1])),
              "start %d lies on edge %d", i + 1, j + 1);
    }
    int parity = 0;
    for (int j = 0; j < n; j++) {
      if (x[j] == x[j + 1] && x[j] > xs && min(y[j], y[j + 1]) <= ys && ys < max(y[j], y[j + 1])) {
        parity ^= 1;
      }
    }
    ensuref(parity == 0, "start %d lies inside the polygon", i + 1);
  }
  inf.readEof();
  return 0;
}
