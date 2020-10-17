#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);

  int n = inf.readInt();
  vector<ll> x(n), y(n), h(n);
  for (int i = 0; i < n; i++) {
    x[i] = inf.readLong();
    y[i] = inf.readLong();
    h[i] = inf.readLong();
  }

  auto check = [&](InStream &in) {
    ll rx = in.readLong();
    ll ry = in.readLong();
    ll rh = in.readLong();
    for (int i = 0; i < n; i++) {
      if (!(rx - rh <= x[i] - h[i] &&
            rx + rh >= x[i] + h[i] &&
            ry - rh <= y[i] - h[i] &&
            ry + rh >= y[i] + h[i])) {
        in.quitf(_wa, "%d-th obelisk is not covered by resulting pyramid", i + 1);
      }
    }
    return tuple<ll, ll, ll>(rx, ry, rh);
  };

  auto jury = check(ans);
  auto jury_res = get<2>(jury);

  auto part = check(ouf);
  auto part_res = get<2>(part);

  if (part_res < jury_res) {
    quitf(_fail, "participant has better answer: part_h=%lld, jury_h=%lld", part_res, jury_res);
  } else if (part_res == jury_res) {
    quitf(_ok, "x=%lld, y=%lld, h=%lld", get<0>(part), get<1>(part), get<2>(part));
  } else {
    quitf(_wa, "participant has worse answer: part_h=%lld, jury_h=%lld", part_res, jury_res);
  }
}
