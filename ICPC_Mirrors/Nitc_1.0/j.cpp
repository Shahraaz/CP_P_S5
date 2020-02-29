// Mike's solution
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <sstream>
 
using namespace std;
 
int P, V;
 
bool query(int r) {
  printf("check 0 %d\n", r);
  fflush(stdout);
  char foo[42];
  scanf("%s", foo);
  return (foo[0] == 'Y');
}
 
void answer(int r) {
  printf("answer %d\n", r);
  fflush(stdout);
}
 
const int N = 123456;
 
int va[N], vb[N], vc[N];
 
long long build(int it, int c) {
  long long cur = 0;
  for (int p = 0; p <= P; p++) {
    if (va[p] > vb[p]) {
      continue;
    }
    int mv = c - p;
    if (it == 0) mv = (mv >= 0) ? V : -1; else
    if (mv < 0) mv = -1;
    else mv /= it;
    vc[p] = mv;
    if (mv >= vb[p]) cur += vb[p] - va[p] + 1; else
    if (mv >= va[p]) cur += mv - va[p] + 1;
  }
  return cur;
}
 
int main() {
  scanf("%d %d", &P, &V);
  for (int p = 0; p <= P; p++) {
    va[p] = 0;
    vb[p] = V;
  }
  long long total = 1LL * (P + 1) * (V + 1);
  for (int it = 0; it <= 99; it++) {
    int a = 0, b = P + it * V;
    while (a < b) {
      int c = (a + b) >> 1;
      long long cur = build(it, c);
      if (2 * cur >= total) b = c;
      else a = c + 1;
    }
    build(it, a);
    bool res = query(a);
    if (res) {
      for (int p = 0; p <= P; p++) {
        if (vc[p] < vb[p]) vb[p] = vc[p];
      }
    } else {
      for (int p = 0; p <= P; p++) {
        if (vc[p] + 1 > va[p]) va[p] = vc[p] + 1;
      }
    }
    total = 0;
    for (int p = 0; p <= P; p++) {
      if (va[p] <= vb[p]) total += vb[p] - va[p] + 1;
    }
    if (total == 1) {
      for (int p = 0; p <= P; p++)
        if (va[p] <= vb[p]) answer(p + (it + 1) * va[p]);
      break;
    }
  }
  return 0;
}