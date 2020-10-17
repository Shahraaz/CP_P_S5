/**
 *    author:  tourist
 *    created: 22.10.2019 16:21:41       
**/
#include <bits/stdc++.h>

using namespace std;

inline int inv(int a, int md) {
  a = (a % md + md) % md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}

int GetFirstSmallerPoint(int md, int step, int start, int bound) {
  if (start < bound) {
    return start;
  }
  if (step == 0) {
    return -1;
  }
  if (start >= step) {
    int go = (md - 1 - start) / step;
    start = start + (go + 1) * step - md;
  }
  if (start < bound) {
    return start;
  }
  int new_step = md % step;
  int new_start = bound + (step - 1 - start);
  int x = GetFirstSmallerPoint(step, new_step, new_start, bound);
  return (x == -1 ? -1 : bound - 1 - x);
}

int CountStepsBeforeInside(int md, int start, int step, int ya, int yb) {
  assert(0 <= ya && ya <= yb && yb < md);
  start = (start + md - ya) % md;
  int pt = GetFirstSmallerPoint(md, step, start, yb - ya + 1);
  if (pt == -1) {
    return -1;
  }
  int A = (pt - start + md) % md;
  int B = step;
  int C = md;
  int g = __gcd(B, C);
  assert(A % g == 0);
  A /= g;
  B /= g;
  C /= g;
  return (int) ((long long) A * inv(B, C) % C);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int w, h;
  cin >> w >> h;
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  const long long inf = (long long) 9e18;
  int tt;
  cin >> tt;
  while (tt--) {
    int xs, ys;
    cin >> xs >> ys;
    long long ans = inf;
    for (int rx = 0; rx < 2; rx++) {
      for (int ry = 0; ry < 2; ry++) {
        for (int trans = 0; trans < 2; trans++) {
          for (int i = 0; i < n; i++) {
            if (x[i] == x[(i + 1) % n]) {
              int ya = y[i];
              int yb = y[(i + 1) % n];
              if (ya > yb) {
                swap(ya, yb);
              }
              int till_first = (x[i] - xs + 2 * w) % (2 * w);
              int start = (ys + till_first) % (2 * h);
              int step = (2 * w) % (2 * h);
              int cur = CountStepsBeforeInside(2 * h, start, step, ya, yb);
              if (cur != -1) {
                ans = min(ans, cur * (2LL * w) + till_first);
              }
            }
          }
          for (int i = 0; i < n; i++) {
            swap(x[i], y[i]);
          }
          swap(xs, ys);
          swap(w, h);
        }
        for (int i = 0; i < n; i++) {
          y[i] = 2 * h - y[i];
        }
      }
      for (int i = 0; i < n; i++) {
        x[i] = 2 * w - x[i];
      }
    }
    if (ans == inf) {
      cout << -1 << '\n';
    } else {
      int xf = (int) ((xs + ans) % (2 * w));
      int yf = (int) ((ys + ans) % (2 * h));
      if (xf >= w) xf = 2 * w - xf;
      if (yf >= h) yf = 2 * h - yf;
      cout << ans << " " << xf << " " << yf << '\n';
    }
  }
  return 0;
}
