#include "testlib.h"

using namespace std;

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  int n = atoi(argv[1]);
  int S = atoi(argv[2]);
  int m = atoi(argv[3]);
  cout << n << '\n';
  int one = S / n;
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << ' ';
    cout << one + (S % n > i);
  }
  cout << '\n';
  cout << m << '\n';
  for (int i = 0; i < m; i++) {
    if (i > 0) cout << ' ';
    cout << rnd.next(1, S);
  }
  cout << '\n';
}
