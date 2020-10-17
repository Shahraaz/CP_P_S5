#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n), h(n);
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> h[i];

  int min_x = INF, max_x = -INF, min_y = INF, max_y = -INF;
  for (int i = 0; i < n; i++) {
    min_x = min(min_x, x[i] - h[i]);
    max_x = max(max_x, x[i] + h[i]);
    min_y = min(min_y, y[i] - h[i]);
    max_y = max(max_y, y[i] + h[i]);
  }
  int rx = (min_x + max_x) / 2, ry = (min_y + max_y) / 2;
  int rh = (max(max_x - min_x, max_y - min_y) + 1) / 2;
  cout << rx << " " << ry << " " << rh << endl;
}
