/**
 *    author:  tourist
 *    created: 22.10.2019 16:51:18       
**/
#include <bits/stdc++.h>

using namespace std;

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
  vector<vector<int>> mark(w + 1, vector<int>(h + 1, 0));
  for (int i = 0; i < n; i++) {
    int xa = x[i];
    int ya = y[i];
    int xb = x[(i + 1) % n];
    int yb = y[(i + 1) % n];
    if (xa > xb) swap(xa, xb);
    if (ya > yb) swap(ya, yb);
    for (int xx = xa; xx <= xb; xx++) {
      for (int yy = ya; yy <= yb; yy++) {
        mark[xx][yy] = 1;
      }
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int xs, ys;
    cin >> xs >> ys;
    int dx = 1, dy = 1;
    int xc = xs, yc = ys;
    long long T = 0;
    while (true) {
      if (mark[xc][yc]) {
        cout << T << " " << xc << " " << yc << '\n';
        break;
      }
      ++T;
      xc += dx;
      yc += dy;
      if (xc == 0 || xc == w) {
        dx = -dx;
      }
      if (yc == 0 || yc == h) {
        dy = -dy;
      }
      if (xc == xs && yc == ys && dx == 1 && dy == 1) {
        cout << -1 << '\n';
        break;
      }
    }
  }
  return 0;
}
