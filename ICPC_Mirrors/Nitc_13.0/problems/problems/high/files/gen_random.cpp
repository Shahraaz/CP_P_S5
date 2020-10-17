#include "testlib.h"

using namespace std;

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  int n = atoi(argv[1]);
  int A = atoi(argv[2]);
  int m = atoi(argv[3]);
  cout << n << '\n';
  int sum = 0;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int ai = rnd.next(1, A);
    if (i > 0) cout << ' ';
    cout << ai;
    sum += ai;
    mx = max(mx, ai);
  }
  cout << '\n';
  m = min(m, sum - mx + 1);
  cout << m << '\n';
  for (int i = 0; i < m; i++) {
    if (i > 0) cout << ' ';
    cout << rnd.next(mx, sum);
  }
  cout << '\n';
}
