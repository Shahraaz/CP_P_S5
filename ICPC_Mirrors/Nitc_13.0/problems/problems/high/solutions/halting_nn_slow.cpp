#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int sum = 0;
  int maxCodeBlock = 0;
  for (int i : a) {
      sum += i;
      maxCodeBlock = max(maxCodeBlock, i);
  }
  int q;
  cin >> q;
  vector<int> answer(sum + 1, -1);
  for (int i = 0; i < q; i++) {
    int k;
    cin >> k;
    if (k < maxCodeBlock) {
        cout << "Impossible\n";
        continue;
    }
    if (answer[k] < 0) {
      int cur = 0;
      int curAns = 0;
      while (cur < n) {
        int have = k;
        while (cur < n && have >= a[cur]) {
          have -= a[cur++];
        }
        curAns++;
      }
      answer[k] = curAns;
    }
    cout << answer[k] << '\n';
  }
}
