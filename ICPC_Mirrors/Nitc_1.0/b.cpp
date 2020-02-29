// B Mike's submission.
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
 
const string TASKNAME = "bonus";
 
double f[3010][3010];
 
int main() {
  freopen((TASKNAME + ".in").c_str(), "r", stdin);
  freopen((TASKNAME + ".out").c_str(), "w", stdout);
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  for (int r = 0; r < 2; r++) {
    if (r == 0) a++;
    else b++;
    if (n > a + b) n = a + b;
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    double ans = 0;
    for (int x = 0; x <= a && x <= n; x++)
      for (int y = 0; y <= b && x + y <= n; y++) {
        if (f[x][y] == 0) continue;
        if (x + y == n) {
          if (r == 0) ans += 1.0 * x / a * f[x][y];
          else ans += 1.0 * y / b * f[x][y];
          continue;
        }
        if (x < a) {
          f[x + 1][y] += f[x][y] * (2.0 * (a - x)) / (2.0 * (a - x) + (b - y));
        }
        if (y < b) {
          f[x][y + 1] += f[x][y] * (b - y) / (2.0 * (a - x) + (b - y));
        }
      }
    printf("%.17lf\n", ans);
    if (r == 0) a--;
    else b--;
  }
  return 0;
}